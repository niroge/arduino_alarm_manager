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
#include <QFormLayout>

// the standard libraries
#include <iostream>		// for 
#include <fstream>		// for opening the alarms file
#include <vector>		// for list management
#include <sstream>

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
	int hour;
	int minute;
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
	if (not add_alarm_widget->isVisible()) {
		add_alarm_widget->show();
	}

	visible = false;
}

void AddAlarmWidget::save_close()
{
	std::fstream save_file;
	save_file.open(ALARMS_FILE, std::fstream::out | std::fstream::app);	

	// to complete
	add_alarm_widget->close();
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
	
	QTimer *timer_update = new QTimer(widget_main);

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
	
	button_delete_1->setStyleSheet(style_button);
	button_delete_1->setToolTip("delete alarm");
	button_delete_1->setFixedSize(icon_delete->actualSize(icon_delete->availableSizes().first()));
	button_delete_1->setIcon(*icon_delete);
	
	button_delete_2->setStyleSheet(style_button);
	button_delete_2->setToolTip("delete alarm");
	button_delete_2->setFixedSize(icon_delete->actualSize(icon_delete->availableSizes().first()));
	button_delete_2->setIcon(*icon_delete);
	
	label_time_0->setStyleSheet(style_alarm_title);
	label_time_0->setToolTip("Alarm 0's time");
	
	label_time_1->setStyleSheet(style_alarm_title);
	label_time_1->setToolTip("Alarm 1's time");
	
	label_time_2->setStyleSheet(style_alarm_title);
	label_time_2->setToolTip("Alarm 2's time");

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
	
	update_alarms();
	
	QObject::connect(timer_update, &QTimer::timeout, this, &MainWindow::update_time);
	QObject::connect(button_connect_upload, &QPushButton::clicked, this, &MainWindow::connect_bluetooth);
	//QObject::connect(button_add_alarm, &QPushButton::clicked, add_alarm_widget, &AddAlarmWidget::show);
	QObject::connect(button_add_alarm, &QPushButton::clicked, this, &MainWindow::add_alarms);
	QObject::connect(button_delete_0, &QPushButton::clicked, this, &MainWindow::delete_alarm_0);
	QObject::connect(button_delete_1, &QPushButton::clicked, this, &MainWindow::delete_alarm_1);
	QObject::connect(button_delete_2, &QPushButton::clicked, this, &MainWindow::delete_alarm_2);

	timer_update->start(500);

	widget_main->show();
}

void MainWindow::add_alarms()
{
	add_alarm_widget->show();
	while (add_alarm_widget->visible);
	update_alarms();
}

void MainWindow::read_alarms_list()
{
	std::fstream file_pointer;
	std::string current_line;
	char separator;

	alarm_struct current_alarm;

	
	file_pointer.open(ALARMS_FILE, std::fstream::in);

	if (file_pointer.is_open()) {
		for (int i = 0; i < 3; i++) {
			std::cout << "Reading the alarms file!" << std::endl;
			std::getline(file_pointer, current_line);
			std::stringstream line_stream(current_line);
			line_stream >> current_alarm.hour >> separator >> current_alarm.minute;
			alarms_list.push_back(current_alarm);
		}

		std::getline(file_pointer, current_line);
		input_message->setText(QString::fromStdString(current_line));
	} else {
		std::cout << "Creating the alarms file..." << std::endl;
		file_pointer.open(ALARMS_FILE, std::fstream::out);
		for (int i = 0; i < 3; i++) {
			std::cout << "Writing the alarms file!" << std::endl;
			file_pointer << "< 3" << std::endl;
			current_alarm.hour = '<';
			current_alarm.minute = '3';
			alarms_list.push_back(current_alarm);
		}

		file_pointer << "Insert a title (max 69 chars)" << std::endl;
	}

	file_pointer.close();
}

void MainWindow::update_time()
{
	label_time->setText(QTime::currentTime().toString("hh:mm:ss"));
}

void MainWindow::update_alarms()
{
	char separator;
	
	std::string current_line;
	std::fstream file_pointer;

	file_pointer.open(ALARMS_FILE, std::fstream::in);
	
	alarms_list.clear();
	alarm_struct current_alarm;

	std::cout << "Updated alarms!" << std::endl;
	
	for (int i = 0; i < 3; i++) {
		std::getline(file_pointer, current_line);
		std::stringstream(current_line) >> current_alarm.hour >> separator >> current_alarm.minute;
		alarms_list.push_back(current_alarm);


	}

	label_time_0->setText((std::to_string(alarms_list[0].hour) + " " + std::to_string(alarms_list[0].minute)).c_str());
	label_time_1->setText((std::to_string(alarms_list[1].hour) + " " + std::to_string(alarms_list[1].minute)).c_str());
	label_time_2->setText((std::to_string(alarms_list[2].hour) + " " + std::to_string(alarms_list[2].minute)).c_str());

	std::cout << "alarm 0 -> " << alarms_list[0].hour << ":" << alarms_list[0].minute << std::endl;
	std::cout << "alarm 1 -> " << alarms_list[1].hour << ":" << alarms_list[1].minute << std::endl;
	std::cout << "alarm 2 -> " << alarms_list[2].hour << ":" << alarms_list[2].minute << std::endl;
}

void MainWindow::delete_alarm_0()
{
	//alarms_list.erase(0);
	std::cout << "Alarm 0 deleted!" << std::endl;
}

void MainWindow::delete_alarm_1()
{
	//alarms_list.erase(1);
	std::cout << "Alarm 1 deleted!" << std::endl;
}

void MainWindow::delete_alarm_2()
{
	//alarms_list.erase(2);
	std::cout << "Alarm 2 deleted!" << std::endl;
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
