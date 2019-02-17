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
#include <sstream>		// for using stream operators on the alarms file
#include <fstream>		// for opening the alarms file
#include <vector>		// for list management
#include <algorithm>

// define some constants
#define ALARMS_FILE ".alarms.dat"
#define TEXT_COLOR "#fafafa"
#define BACKGROUND_COLOR "#1d1d1d"
#define BACKGROUND_HOVER "#4242ef"
#define FONT_SIZE "18px"
#define FONT_FAMILY "Hack"
#define CLOCK_SIZE "150px"

// structures
// this structure holds some data
struct alarm_struct {
	int hour;
	int minute;
	std::string title;
};

// Default styles (global objects)
QString style_widget = "QWidget {"
	"background-color: " BACKGROUND_COLOR
	"};";

QString style_button = "QPushButton {"
	"background-color: " BACKGROUND_COLOR
	"; font-size: " FONT_SIZE
	"; font-family: " FONT_FAMILY
	"; border: none"
	"}"

	"QPushButton:hover {"
	"border: none;"
	"background-color: " BACKGROUND_HOVER
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
	"}";

class AddAlarmWidget : public QObject {
	QWidget *add_alarm_widget = new QWidget();
	QSpinBox *spinbox_hours = new QSpinBox;
	QSpinBox *spinbox_minutes = new QSpinBox;
	QLineEdit *input_title = new QLineEdit;

	int hour = 0, minute = 0;

public:
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
	input_title->setMaxLength(32);
	input_title->insert("Sample alarm title");

	layout_form->addRow(tr("&Hours: "), spinbox_hours);
	layout_form->addRow(tr("&Minutes: "), spinbox_minutes);

	layout_form->addRow(tr("&Title: "), input_title);
	layout_form->addWidget(button_done);

	QObject::connect(button_done, &QPushButton::clicked, this, &AddAlarmWidget::save_close);
	
	add_alarm_widget->setLayout(layout_form);
}

void AddAlarmWidget::show()
{
	if (not add_alarm_widget->isVisible()) {
		add_alarm_widget->show();
	}
}

void AddAlarmWidget::save_close()
{
	std::fstream save_file;
	save_file.open(ALARMS_FILE, std::fstream::out | std::fstream::app);	

	std::string current_title = input_title->text().toStdString();
	current_title.replace(current_title.begin(), current_title.end(), " ", "~");

	save_file << spinbox_hours->value() << " " << spinbox_minutes->value() << current_title << std::endl;
	save_file.close();

	add_alarm_widget->close();
}

class MainWindow : public QObject {
	QWidget *widget_main = new QWidget();
	QGridLayout *layout = new QGridLayout();
	QPushButton *button_connect_upload = new QPushButton(QIcon("icons/connect.jpg"), "Connect");
	QPushButton *button_add_alarm = new QPushButton(QIcon("icons/add_alarm.jpg"), "Add alarm");
	QLabel *label_time = new QLabel(QTime::currentTime().toString("hh:mm:ss"));
	QLabel *label_whitespace = new QLabel("");
	bool arduino_connected = false;
	AddAlarmWidget *add_alarm_widget = new AddAlarmWidget();
	bool device_connected = false;
	std::vector<alarm_struct> alarms_list; // this needs to be removed entierly from the program
	
	// these objects suck and should be removed in the future
	QLabel *label_alarm_0 = new QLabel("Eat, PWN, Repeat");
	QLabel *label_alarm_1 = new QLabel("Go to bed");
	QLabel *label_alarm_2 = new QLabel("Wake up");
	QLabel *label_time_0 = new QLabel("13:37");
	QLabel *label_time_1 = new QLabel("4:00");
	QLabel *label_time_2 = new QLabel("5:45");
	QPushButton *button_delete_0 = new QPushButton(QIcon("icons/delete.jpg"), "");
	QPushButton *button_delete_1 = new QPushButton(QIcon("icons/delete.jpg"), "");
	QPushButton *button_delete_2 = new QPushButton(QIcon("icons/delete.jpg"), "");

public:
	MainWindow();
	void read_alarms_list();
	void update_alarms();
	void update_time();
	void close_all();
	void delete_alarm_0();
	void delete_alarm_1();
	void delete_alarm_2();
	void connect_bluetooth();
	void check_alarm();
};

MainWindow::MainWindow()
{
	read_alarms_list();
	
	QTimer *timer_update = new QTimer(widget_main);
	QTimer *timer_alarm = new QTimer(widget_main);

	label_time->setAlignment(Qt::AlignCenter);
	widget_main->setWindowTitle("Arduino Alarm Manager");
	widget_main->setWindowIcon(QIcon("icons/logo.jpg"));
	widget_main->setStyleSheet(style_widget);

	button_connect_upload->setStyleSheet(style_button);
	button_connect_upload->setToolTip("connect to a device");
	button_add_alarm->setStyleSheet(style_button);
	button_add_alarm->setToolTip("add an alarm");
	label_time->setStyleSheet(style_clock);
	label_time->setToolTip("current time");
	button_delete_0->setStyleSheet(style_button);
	button_delete_0->setToolTip("detele alarm");
	button_delete_1->setStyleSheet(style_button);
	button_delete_2->setStyleSheet(style_button);
	label_alarm_0->setStyleSheet(style_alarm_title);
	label_alarm_1->setStyleSheet(style_alarm_title);
	label_alarm_2->setStyleSheet(style_alarm_title);
	label_time_0->setStyleSheet(style_alarm_title);
	label_time_1->setStyleSheet(style_alarm_title);
	label_time_2->setStyleSheet(style_alarm_title);

	layout->addWidget(button_connect_upload, 0, 0);
	layout->addWidget(label_whitespace, 0, 1, 1, 5);
	layout->addWidget(button_add_alarm, 0, 7);
	layout->addWidget(label_time, 1, 0, 2, 9);

	layout->addWidget(button_delete_0, 3, 0, 1, 1);
	layout->addWidget(label_time_0, 3, 1, 1, 2);
	layout->addWidget(label_alarm_0, 3, 4, 1, 5);

	layout->addWidget(button_delete_1, 4, 0);
	layout->addWidget(label_time_1, 4, 1, 1, 2);
	layout->addWidget(label_alarm_1, 4, 4, 1, 5);

	layout->addWidget(button_delete_2, 5, 0);
	layout->addWidget(label_time_2, 5, 1, 1, 2);
	layout->addWidget(label_alarm_2, 5, 4, 1, 5);
	
	widget_main->setLayout(layout);
	widget_main->show();

	QObject::connect(timer_update, &QTimer::timeout, this, &MainWindow::update_time);
	QObject::connect(button_connect_upload, &QPushButton::clicked, this, &MainWindow::connect_bluetooth);
	QObject::connect(button_add_alarm, &QPushButton::clicked, add_alarm_widget, &AddAlarmWidget::show);
	QObject::connect(button_delete_0, &QPushButton::clicked, this, &MainWindow::delete_alarm_0);
	QObject::connect(button_delete_1, &QPushButton::clicked, this, &MainWindow::delete_alarm_1);
	QObject::connect(button_delete_2, &QPushButton::clicked, this, &MainWindow::delete_alarm_2);
	QObject::connect(timer_alarm, &QTimer::timeout, this, &MainWindow::check_alarm);
	
	timer_update->start(500);
	timer_alarm->start(500);
}

void MainWindow::check_alarm()
{
	std::cout << "Alarm found!" << std::endl;
}

void MainWindow::read_alarms_list()
{
	alarms_list.clear();
	// std::string current_line;
	// std::fstream file_pointer;

	// alarm_struct alarm;
	// char separator;
	
	// file_pointer.open(ALARMS_FILE, std::fstream::in | std::fstream::out | std::fstream::app);

	// std::cout << "Checking alarms file..." << std::endl;
	// while (std::getline(file_pointer, current_line)) {
	// 	std::cout << "Adding alarm..." << std::endl;
	// 	std::stringstream(current_line) >> alarm.hour   >> separator
	// 					>> alarm.minute >> separator
	// 					>> alarm.title;

	// 	alarm.title.replace(alarm.title.begin(), alarm.title.end(), "~", " ");
	// 	alarms_list.push_back(alarm);

	// 	std::cout << "Added an alarm!" << std::endl;
	// }
}

void MainWindow::update_time()
{
	label_time->setText(QTime::currentTime().toString("hh:mm:ss"));
}

void MainWindow::delete_alarm_0()
{
	//alarms_list.erase(0);
}

void MainWindow::delete_alarm_1()
{
	//alarms_list.erase(1);
}

void MainWindow::delete_alarm_2()
{
	//alarms_list.erase(2);
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

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	MainWindow main_window;
	
	int exit_value = app.exec();
	
	return exit_value;
}
