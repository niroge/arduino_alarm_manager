// Arduino Alarm Manager
// Copyright (C) 2019   <robert@battlestation>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or (at
// your option) any later version.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

// include the libraries
// the QT system
#include <QApplication>		// the QApplication class
#include <QWidget>		// the QWidget class
#include <QPushButton>		// the QPushButton class
#include <QLabel>		// the QLabel class
#include <QLayout>		// the QLayout class
#include <QTime>		// for getting the current time
#include <QString>		// for QString, to set the CSS of the window
#include <QObject>		// the QObject::connect function
#include <QGroupBox>		// like an HTML's <div></div> tag
#include <QTimer>		// for the clock
#include <QSpinBox>		// for the spin box
#include <QLineEdit>		// for the title
#include <QFormLayout>		// for the form layout
#include <QList>		// for the various alarms labels

// the standard libraries
#include <iostream>		// for
#include <fstream>		// for opening the alarms file
#include <vector>		// for list management
#include <sstream>		// string streaming
#include <map>			// dictionary-like [for the alarms]

// personal libraries
#ifdef unix
#include "libs/bluetooth_unix.hpp"
#else
#include "libs/bluetooth_windows.hpp"
#endif

// define some constants
#define ALARMS_FILE ".alarms.dat"
#define TEXT_COLOR "#fafafa"
#define BACKGROUND_COLOR "#1d1d1d"
#define BACKGROUND_HOVER "#4242ef"
#define FONT_SIZE "18px"
#define FONT_FAMILY "Hack"
#define FONT_COLOR "#fafafa"
#define CLOCK_SIZE "150px"

// structures
// this structure holds some data
struct alarm_struct {
	unsigned short hour;
	unsigned short minute;
};

// Default styles (global objects)
QString style_widget = "QWidget {"
	"background-color: " BACKGROUND_COLOR
	"};";

QString style_button = "QPushButton {"
	"background-color: " BACKGROUND_COLOR
	"; font-size: " FONT_SIZE
	"; font-family: " FONT_FAMILY
	"; color: " FONT_COLOR
	"; border: none"
	"}"

	"QPushButton:hover {"
	"border: none;"
	"background-color: " BACKGROUND_HOVER
	"; color: " FONT_COLOR
	"} "

	"QPushButton:flat"
	"{border: none;"
	"background-color: " BACKGROUND_COLOR
	"}";

QString style_clock = "QLabel {"
	"background-color: " BACKGROUND_COLOR
	"; font-size: " CLOCK_SIZE
	"; color: #00ff00"
	"};";

QString style_alarm_title = "QLabel {"
	"background-color: " BACKGROUND_COLOR
	"; font-size: 36px;"
	"font-family: " FONT_FAMILY
	"; color: " FONT_COLOR
	"}";


// Here lies a...
// (looks around, noone except you is here)
// gLoBaLh vArIaBlEh
// Just kidding, the CSS variables are the only global variables
// (and they'll be removed in the future versions, allowing custom themes)
bool updated = false;

// The widget that manages the alarms
// Class prototypes
class AddAlarmWidget;
class MainWindow;


// Class definitions
class AddAlarmWidget : public QObject {
	QSpinBox *spinbox_hours = new QSpinBox;
	QSpinBox *spinbox_minutes = new QSpinBox;
	QWidget *add_alarm_widget = new QWidget();
	int hour = 0, minute = 0;

public:
	bool visible = false;
	AddAlarmWidget();
	void show();
	void save_close();
};

AddAlarmWidget::AddAlarmWidget()
{
	QFormLayout *layout_form = new QFormLayout;
	QPushButton *button_done = new QPushButton("OK", add_alarm_widget);

	add_alarm_widget->setWindowTitle("add alarm");
	add_alarm_widget->setStyleSheet(style_widget);

	spinbox_hours->setRange(0, 23);
	spinbox_minutes->setRange(0, 59);

	spinbox_hours->setSingleStep(1);
	spinbox_minutes->setSingleStep(1);

	spinbox_hours->setValue(12);
	spinbox_minutes->setValue(30);

	layout_form->addRow(tr("&Hours: "), spinbox_hours);
	layout_form->addRow(tr("&Minutes: "), spinbox_minutes);

	layout_form->addWidget(button_done);

	QObject::connect(button_done, &QPushButton::clicked, this, &AddAlarmWidget::save_close);

	add_alarm_widget->setLayout(layout_form);
}

void AddAlarmWidget::show()
{
	visible = true;

	while (not add_alarm_widget->isVisible()) {
		add_alarm_widget->show();
	}

	visible = false;
	std::cout << "now from show(), visible = false" << std::endl;
}

void AddAlarmWidget::save_close()
{
	std::cout << "Called save_close()" << std::endl;
	std::fstream save_file;
	save_file.open(ALARMS_FILE, std::fstream::in);

	bool added_alarm = false;
	std::string title, line;
	alarm_struct current_alarm;
	std::vector<alarm_struct> alarms_list;

	for (int i = 0; i < 3; i++) {
		save_file >> current_alarm.hour >> current_alarm.minute;

		if (current_alarm.hour == 25 && added_alarm == false) {
			std::cout << "Alarm saved at index " << i << std::endl;
			added_alarm = true;
			current_alarm.hour = spinbox_hours->value();
			current_alarm.minute = spinbox_minutes->value();
		} else {
			std::cout << "Using existing alarm at " << current_alarm.hour << ":" << current_alarm.minute << std::endl;
		}

		alarms_list.push_back(current_alarm);
	}

	do {
		std::getline(save_file, title);
	} while (title.empty());

	std::cout << "[save_close] title -> " << title << std::endl;
	save_file.close();
	save_file.open(ALARMS_FILE, std::fstream::out | std::fstream::trunc);

	save_file << alarms_list[0].hour << " " << alarms_list[0].minute << std::endl
		  << alarms_list[1].hour << " " << alarms_list[1].minute << std::endl
		  << alarms_list[2].hour << " " << alarms_list[2].minute << std::endl
		  << title << std::endl;

	std::cout << "Alarms file saved" << std::endl;
	std::cout << "[alarm 0] "<< alarms_list[0].hour << " " << alarms_list[0].minute << std::endl
		  << "[alarm 1] "<< alarms_list[1].hour << " " << alarms_list[1].minute << std::endl
		  << "[alarm 2] "<< alarms_list[2].hour << " " << alarms_list[2].minute << std::endl
		  << "[ title ] "<< title << std::endl;
	std::cout << "=================" << std::endl;

	// to complete
	add_alarm_widget->close();
	updated = true;
}

class MainWindow : public QObject {
	QLineEdit *input_message = new QLineEdit();
	QWidget *widget_main = new QWidget();
	QGridLayout *layout = new QGridLayout();
	QPushButton *button_connect_upload = new QPushButton(QIcon("icons/connect.jpg"), "Connect");
	QPushButton *button_add_alarm = new QPushButton(QIcon("icons/add_alarm.jpg"), "Add alarm");
	QLabel *label_time = new QLabel(QTime::currentTime().toString("hh:mm:ss"));
	bool arduino_connected = false;
	AddAlarmWidget *add_alarm_widget = new AddAlarmWidget();
	bool device_connected = false;
	std::string message_title;
	std::vector<alarm_struct> alarms_list; // this needs to be removed entierly from the program

	// these objects suck and should be removed in the future
	QLabel *label_time_0 = new QLabel("HH:MM");
	QLabel *label_time_1 = new QLabel("HH:MM");
	QLabel *label_time_2 = new QLabel("HH:MM");
	QPushButton *button_delete_0 = new QPushButton();
	QPushButton *button_delete_1 = new QPushButton();
	QPushButton *button_delete_2 = new QPushButton();
	QIcon *icon_delete = new QIcon("icons/delete.png");

public:
	MainWindow();
	void add_alarms();
	void read_alarms_list();
	void update_alarms();
	void update_time();
	void delete_alarm_0();
	void delete_alarm_1();
	void delete_alarm_2();
	void connect_bluetooth();
};

MainWindow::MainWindow()
{
	read_alarms_list();
	bluetooth_connect("DE:AD:BE:EF:FE:ED");

	QTimer *timer_update = new QTimer(widget_main);
	QTimer *timer_alarms_update = new QTimer(widget_main);

	label_time->setAlignment(Qt::AlignCenter);
	layout->setAlignment(Qt::AlignCenter | Qt::AlignHCenter);

	widget_main->setWindowTitle("Arduino Alarm Manager");
	widget_main->setWindowIcon(QIcon("icons/logo.jpg"));
	widget_main->setStyleSheet(style_widget);
	input_message->setToolTip("The title of the clock");

	button_connect_upload->setStyleSheet(style_button);
	button_connect_upload->setToolTip("connect to a device");

	button_add_alarm->setStyleSheet(style_button);
	button_add_alarm->setToolTip("add an alarm");

	label_time->setStyleSheet(style_clock);
	label_time->setToolTip("current time");

	button_delete_0->setStyleSheet(style_button);
	button_delete_0->setFixedSize(icon_delete->actualSize(icon_delete->availableSizes().first()));
	button_delete_0->setToolTip("detele alarm");
	button_delete_0->setIcon(*icon_delete);
	button_delete_0->hide();

	button_delete_1->setStyleSheet(style_button);
	button_delete_1->setToolTip("delete alarm");
	button_delete_1->setFixedSize(icon_delete->actualSize(icon_delete->availableSizes().first()));
	button_delete_1->setIcon(*icon_delete);
	button_delete_1->hide();

	button_delete_2->setStyleSheet(style_button);
	button_delete_2->setToolTip("delete alarm");
	button_delete_2->setFixedSize(icon_delete->actualSize(icon_delete->availableSizes().first()));
	button_delete_2->setIcon(*icon_delete);
	button_delete_2->hide();

	label_time_0->setStyleSheet(style_alarm_title);
	label_time_0->setToolTip("Alarm 0's time");
	label_time_0->hide();

	label_time_1->setStyleSheet(style_alarm_title);
	label_time_1->setToolTip("Alarm 1's time");
	label_time_1->hide();

	label_time_2->setStyleSheet(style_alarm_title);
	label_time_2->setToolTip("Alarm 2's time");
	label_time_2->hide();

	layout->addWidget(button_connect_upload, 0, 0);
	layout->addWidget(button_add_alarm, 0, 4, 1, 1);

	layout->addWidget(label_time, 1, 0, 2, 5);

	layout->addWidget(input_message, 3, 1, 1, 3);

	layout->addWidget(button_delete_0, 4, 0);
	layout->addWidget(button_delete_1, 5, 0);
	layout->addWidget(button_delete_2, 6, 0);

	layout->addWidget(label_time_0, 4, 1, 1, 4);
	layout->addWidget(label_time_1, 5, 1, 1, 4);
	layout->addWidget(label_time_2, 6, 1, 1, 4);

	widget_main->setLayout(layout);

	QObject::connect(timer_update, &QTimer::timeout, this, &MainWindow::update_time);
	QObject::connect(button_connect_upload, &QPushButton::clicked, this, &MainWindow::connect_bluetooth);
	QObject::connect(timer_alarms_update, &QTimer::timeout, this, &MainWindow::update_alarms);
	QObject::connect(button_add_alarm, &QPushButton::clicked, this, &MainWindow::add_alarms);
	QObject::connect(button_delete_0, &QPushButton::clicked, this, &MainWindow::delete_alarm_0);
	QObject::connect(button_delete_1, &QPushButton::clicked, this, &MainWindow::delete_alarm_1);
	QObject::connect(button_delete_2, &QPushButton::clicked, this, &MainWindow::delete_alarm_2);

	timer_update->start(500);
	timer_alarms_update->start(50);

	widget_main->show();
}

void MainWindow::add_alarms()
{
	bool can_add = false;
	updated = false;
	for (int i = 0; i < 3; i++) {
		if (alarms_list[i].hour == 25)
			can_add = true;
	}

	if (can_add)
		add_alarm_widget->show();

	else {
		widget_main->setWindowTitle("Cannot add more than 3 alarms!");
		updated = true;
	}

	while (add_alarm_widget->visible);
}

void MainWindow::read_alarms_list()
{
	std::fstream file_pointer;
	std::string current_line;

	alarm_struct current_alarm;

	alarms_list.clear();

	file_pointer.open(ALARMS_FILE, std::fstream::in);

	if (file_pointer.is_open()) {
		for (int i = 0; i < 3; i++) {
			std::cout << "Reading the alarms file!" << std::endl;
			file_pointer >> current_alarm.hour >> current_alarm.minute;
			alarms_list.push_back(current_alarm);
		}

		std::getline(file_pointer, current_line);
		input_message->setText(QString::fromStdString(current_line));
	} else {
		std::cout << "Creating the alarms file..." << std::endl;
		file_pointer.open(ALARMS_FILE, std::fstream::out);
		for (int i = 0; i < 3; i++) {
			std::cout << "Writing the alarms file!" << std::endl;
			file_pointer << "25 3" << std::endl;
			current_alarm.hour = 25;
			current_alarm.minute = 3;
			alarms_list.push_back(current_alarm);
		}

		file_pointer << "Insert a title (max 69 chars)" << std::endl;
	}

	file_pointer.close();
}

void MainWindow::update_time()
{
	label_time->setText(QTime::currentTime().toString("hh:mm:ss"));
	update_alarms();
}

void MainWindow::update_alarms()
{
	std::string current_line;
	std::fstream file_pointer;

	file_pointer.open(ALARMS_FILE, std::fstream::in);

	alarms_list.clear();
	alarm_struct current_alarm;

	for (int i = 0; i < 3; i++) {
		file_pointer >> current_alarm.hour >> current_alarm.minute;
		alarms_list.push_back(current_alarm);
	}

	// this part sucks and must be updated, I *need* to actually study the library
	// so that I can find a better way to do this
	if (alarms_list[0].hour != 25) {
		label_time_0->show();
		button_delete_0->show();
		label_time_0->setText((std::to_string(alarms_list[0].hour) + ":" + std::to_string(alarms_list[0].minute)).c_str());
	} else {
		label_time_0->hide();
		button_delete_0->hide();
	}

	if (alarms_list[1].hour != 25) {
		label_time_1->show();
		button_delete_1->show();
		label_time_1->setText((std::to_string(alarms_list[1].hour) + ":" + std::to_string(alarms_list[1].minute)).c_str());
	} else {
		label_time_1->hide();
		button_delete_1->hide();
	}

	if (alarms_list[2].hour != 25) {
		label_time_2->show();
		button_delete_2->show();
		label_time_2->setText((std::to_string(alarms_list[2].hour) + ":" + std::to_string(alarms_list[2].minute)).c_str());
	} else {
		label_time_2->hide();
		button_delete_2->hide();
	}

	do {
		std::getline(file_pointer, current_line);
	} while (current_line.empty());

	input_message->setText(QString::fromStdString(current_line));
	file_pointer.close();
}

void MainWindow::delete_alarm_0()
{
	//alarms_list.erase(0);
	std::cout << "Alarm 0 deleted!" << std::endl;
	std::fstream file_pointer;
	std::string title;

	file_pointer.open(ALARMS_FILE, std::fstream::in);
	alarm_struct current_alarm;

	std::vector<alarm_struct> alarms_list;
	file_pointer >> current_alarm.hour >> current_alarm.minute;
	std::cout << "Ignored time " << current_alarm.hour << ":" << current_alarm.minute << std::endl;

	for (int i = 0; i < 2; i++) {
		file_pointer >> current_alarm.hour >> current_alarm.minute;
		alarms_list.push_back(current_alarm);
		std::cout << "Saved " << current_alarm.hour << ":" << current_alarm.minute << std::endl;
	}

	do {
		std::getline(file_pointer, title);
	} while (title.empty());

	std::cout << "Title is -> " << title << std::endl;

	file_pointer.close();

	file_pointer.open(ALARMS_FILE, std::fstream::out | std::fstream::trunc);

	file_pointer << 25 << " " << 3 << std::endl;
	file_pointer << alarms_list[0].hour << " " << alarms_list[0].minute << std::endl
		     << alarms_list[1].hour << " " << alarms_list[1].minute << std::endl
		     << title << std::endl;

	file_pointer.close();
}

void MainWindow::delete_alarm_1()
{
	//alarms_list.erase(1);	//alarms_list.erase(0);
	// MUST BE FIXED
	std::cout << "Alarm 1 deleted!" << std::endl;
	std::fstream file_pointer;
	std::string title;

	file_pointer.open(ALARMS_FILE, std::fstream::in);
	alarm_struct current_alarm;

	std::vector<alarm_struct> alarms_list;

	for (int i = 0; i < 3; i++) {
		file_pointer >> current_alarm.hour >> current_alarm.minute;

		if (i != 1)
			alarms_list.push_back(current_alarm);
	}

	do {
		std::getline(file_pointer, title);
	} while (title.empty());

	std::cout << "Title is [1] -> " << title << std::endl;
	file_pointer.close();

	file_pointer.open(ALARMS_FILE, std::fstream::out | std::fstream::trunc);

	file_pointer << alarms_list[0].hour << " " << alarms_list[0].minute << std::endl
		     << 25 << " " << 3 << std::endl
		     << alarms_list[1].hour << " " << alarms_list[1].minute << std::endl
		     << title << std::endl;

	file_pointer.close();
}

void MainWindow::delete_alarm_2()
{	//alarms_list.erase(0);
	std::cout << "Alarm 2 deleted!" << std::endl;
	std::fstream file_pointer;
	std::string title;

	file_pointer.open(ALARMS_FILE, std::fstream::in);
	alarm_struct current_alarm;

	std::vector<alarm_struct> alarms_list;

	for (int i = 0; i < 2; i++) {
		file_pointer >> current_alarm.hour >> current_alarm.minute;
		alarms_list.push_back(current_alarm);
	}

	file_pointer >> current_alarm.hour >> current_alarm.minute;

	do {
		std::getline(file_pointer, title);
	} while (title.empty());

	std::cout << "Title is [2] -> " << title << std::endl;
	file_pointer.close();

	file_pointer.open(ALARMS_FILE, std::fstream::out | std::fstream::trunc);

	file_pointer << alarms_list[0].hour << " " << alarms_list[0].minute << std::endl
		     << alarms_list[1].hour << " " << alarms_list[1].minute << std::endl
		     << 25 << " " << 3 << std::endl
		     << title << std::endl;

	file_pointer.close();
}

void MainWindow::connect_bluetooth()
{
	std::cout << "Not implemented, for now simply switches the \"upload\" button on or off" << std::endl;

	if (device_connected) {
		button_connect_upload->setText("Connect");
		device_connected = false;
	} else {
		button_connect_upload->setText("Upload ");
		device_connected = true;
	}
}

// the main() function
int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	MainWindow main_window;

	return app.exec();
}
