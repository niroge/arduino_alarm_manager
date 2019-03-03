/*
 * Copyright (C) 2019
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// Author: Nitu Robert Georgian
// Email: 0x0FF1C3@protonmail.com

// include the QT5 libraries
#include <QApplication>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLayout>
#include <QTime>
#include <QTimer>
#include <QString>
#include <QGroupBox>
#include <QSpinBox>
#include <QLineEdit>
#include <QFormLayout>

// standard libraries
#include <iostream>
#include <fstream>
#include <vector>

// personal libraries
#ifdef unix
#include "libs/bluetooth_unix.hpp"
#else
#include "libs/bluetooth_windows.hpp"
#endif

// define the constants
#define ALARMS_FILE "alarms.dat"
#define THEMES_DIRECTORY "theme"
#define THEMES_MAIN_WINDOW "main.css"
#define THEMES_ADD_ALARM_WINDOW "add_alarm.css"
#define THEMES_POPUP_MESSAGE "message.css"

// this structure holds the alarm
struct alarm_struct {
	unsigned short hour;
	unsigned short minute;
};

// class prototypes
class AddAlarmWidget;
class MainWindow;

// define the classes
class AddAlarmWidget : public QObject {
    QString local_stylesheet;
	QWidget *this_widget = new QWidget();
	QSpinBox *spinbox_hours = new QSpinBox;
	QSpinBox *spinbox_minutes = new QSpinBox;

public:
	bool visible = false;

	AddAlarmWidget();
	void load_theme();
	void save_close();
	void show_widget();
};

AddAlarmWidget::AddAlarmWidget()
{
	QFormLayout *formlayout = new QFormLayout;
	QPushButton *pushbutton_done = new QPushButton("Add", this_widget);

	this_widget->setWindowTitle("Add an alarm");
	this_widget->setStyleSheet(local_stylesheet);

	spinbox_hours->setValue(12);
	spinbox_hours->setRange(0, 23);

	spinbox_minutes->setValue(30);
	spinbox_minutes->setRange(0, 59);

	pushbutton_done->setStyleSheet(local_stylesheet);
	pushbutton_done->setStyleSheet("font-size: 12px");

	formlayout->addRow(tr("&Hours: "), spinbox_hours);
	formlayout->addRow(tr("&Minutes: "), spinbox_minutes);

	formlayout->addWidget(pushbutton_done);

	QObject::connect(pushbutton_done, &QPushButton::clicked, this, &AddAlarmWidget::save_close);

	this_widget->setLayout(formlayout);

	load_theme();
}

void AddAlarmWidget::load_theme()
{
	std::string current_line;
	std::string theme_file_name;
	std::fstream theme_file;

	theme_file_name = std::string(THEMES_DIRECTORY) + "/" + std::string(THEMES_ADD_ALARM_WINDOW);

	theme_file.open(theme_file_name, std::fstream::in);

	if (!theme_file.is_open()) {
		theme_file.open(theme_file_name, std::fstream::out);

		theme_file << "/* This is the theme of the AddAlarmWidget, customize it as you wish */" << std::endl
		           << "QWidget {" << std::endl
		           << "    background-color: #1d1d1d;" << std::endl
			   << "    color: #fafafa;" << std::endl
			   << "    font-family: Hack, Monospace, Sans-Serif;" << std::endl
			   << "} " << std::endl << std::endl
			   << "QSpinBox {" << std::endl
			   << "    background-color: #1d1d1d;" << std::endl
			   << "    color: #fafafa;" << std::endl
			   << "    font-family: Hack, Monospace, Sans-Serif;" << std::endl
			   << "} " << std::endl << std::endl
			   << "QPushButton {" << std::endl
			   << "    border: none;" << std::endl
			   << "    font-family: Hack, Monospace, Sans-Serif;" << std::endl
			   << "    color: #fafafa;" << std::endl
			   << "    font-size: 12px;" << std::endl
			   << "} " << std::endl << std::endl
			   << "QPushButton:hover {" << std::endl
			   << "    background-color: #3030be;" << std::endl
			   << "} " << std::endl;

		theme_file.close();
		theme_file.open(theme_file_name, std::fstream::in);
	}

	while (std::getline(theme_file, current_line))
		local_stylesheet += QString::fromStdString(current_line);

	this_widget->setStyleSheet(local_stylesheet);
}

void AddAlarmWidget::show_widget()
{
	this_widget->show();

	visible = true;

	while (!this_widget->isVisible());

	visible = false;

	std::cout << "Ended the show() function" << std::endl;
}

void AddAlarmWidget::save_close()
{
	bool added_alarm = false;
	alarm_struct alarm;
	std::string title, line;
	std::fstream alarms_file;
	std::vector<alarm_struct> alarms_list;

	alarms_file.open(ALARMS_FILE, std::fstream::in);

	for (int i = 0; i < 3; i++) {
		alarms_file >> alarm.hour >> alarm.minute;

		if (added_alarm == false && alarm.hour == 25) {
			added_alarm = true;
			alarm.hour = spinbox_hours->value();
			alarm.minute = spinbox_minutes->value();
		}

		alarms_list.push_back(alarm);
	}

	do {
		std::getline(alarms_file, title);
	} while (title.empty());

	alarms_file.close();

	alarms_file.open(ALARMS_FILE, std::fstream::out | std::fstream::trunc);

	for (int i = 0; i < 3; i++)
		alarms_file << alarms_list[i].hour << " " << alarms_list[i].minute << std::endl;

	alarms_file << title << std::endl;
	alarms_file.close();

	this_widget->close();
}


class MainWindow : public QObject {
	int bluetooth_socket = -1;
	bool device_connected = false;
	std::string custom_message = "";
	std::vector<alarm_struct> alarms;

    QString local_stylesheet = "";

	QWidget *this_widget = new QWidget();
	QTimer *timer_time = new QTimer(this_widget);
	QTimer *timer_alarms = new QTimer(this_widget);
	QGridLayout *gridlayout = new QGridLayout();
	QLineEdit *lineedit_message = new QLineEdit();
	QPushButton *pushbutton_connect = new QPushButton();
	QPushButton *pushbutton_add_alarm = new QPushButton();
	QLabel *label_time = new QLabel(QTime::currentTime().toString("hh:mm:ss"));
	AddAlarmWidget *add_alarm_widget = new AddAlarmWidget();

	// item deletion
	QLabel *label_time0 = new QLabel("");
	QLabel *label_time1 = new QLabel("");
	QLabel *label_time2 = new QLabel("");
	QPushButton *pushbutton_del0 = new QPushButton();
	QPushButton *pushbutton_del1 = new QPushButton();
	QPushButton *pushbutton_del2 = new QPushButton();

	QIcon *icon_add = new QIcon("icons/add.png");
	QIcon *icon_delete = new QIcon("icons/delete.png");

public:
	MainWindow();

	void add_alarms();
	void load_theme();
	void update_time();
	void insert_title();
	void update_alarms();
	void insert_elements();
	void delete_alarm(int);
	void display_alarm(int);
	void connect_bluetooth();
	void configure_elements();
	void popup_message(const char *, const char *);
};

MainWindow::MainWindow()
{
	load_theme();
	insert_elements();
	configure_elements();
	insert_title();

	QObject::connect(pushbutton_add_alarm, &QPushButton::clicked, this, &MainWindow::add_alarms);
	QObject::connect(pushbutton_connect, &QPushButton::clicked, this, &MainWindow::connect_bluetooth);
	QObject::connect(timer_time, &QTimer::timeout, this, &MainWindow::update_time);
	QObject::connect(timer_alarms, &QTimer::timeout, this, &MainWindow::update_alarms);
	QObject::connect(pushbutton_del0, &QPushButton::clicked, this, [this] {delete_alarm(0);});
	QObject::connect(pushbutton_del1, &QPushButton::clicked, this, [this] {delete_alarm(1);});
	QObject::connect(pushbutton_del2, &QPushButton::clicked, this, [this] {delete_alarm(2);});

	timer_time->start(500);
	timer_alarms->start(50);

	this_widget->show();
}

void MainWindow::add_alarms()
{
	bool can_add = false;
	std::fstream file_pointer;

	for (int i = 0; i < 3; i++) {
		if (alarms[i].hour == 25) {
			can_add = true;
			break;
		}
	}

	if (can_add) {
		file_pointer.open(ALARMS_FILE, std::fstream::out | std::fstream::trunc);

		for (int i = 0; i < 3; i++)
			file_pointer << alarms[i].hour << " " << alarms[i].minute << std::endl;

		file_pointer << lineedit_message->text().toStdString() << std::endl;
		add_alarm_widget->show_widget();
	} else {
		popup_message("Error", "Cannot add more than 3 alarms!");
	}

	while (add_alarm_widget->visible);
}

void MainWindow::load_theme()
{
	std::fstream theme_file;
	std::string theme_file_name = std::string(THEMES_DIRECTORY) + "/" + std::string(THEMES_MAIN_WINDOW);
	theme_file.open(theme_file_name, std::fstream::in);

	if (!theme_file.is_open()) {
		// theme file is not installed, creating it...
		theme_file.open(theme_file_name, std::fstream::out);
		theme_file << "/* this is the theme of the main widget, customize it as you wish */" << std::endl << std::endl
		           << "QWidget {" << std::endl
			   << "    background-color: #1d1d1d; " << std::endl
			   << "} " << std::endl << std::endl
			   << "QPushButton {" << std::endl
			   << "    background-color: #1d1d1d; " << std::endl
			   << "    font-size: 18px; " << std::endl
			   << "    font-family: Hack, Monospace, sans-serif; " << std::endl
			   << "    color: #fafafa; " << std::endl
			   << "    border: none; " << std::endl
			   << "} " << std::endl << std::endl
			   << "QPushButton:hover {" << std::endl
			   << "    border: none; " << std::endl
			   << "    background-color: #4242ef;" << std::endl
			   << "    color: #fafafa; " << std::endl
			   << "} " << std::endl << std::endl
			   << "QPushButton:flat {" << std::endl
			   << "    border: none; " << std::endl
			   << "    background-color: #1d1d1d;" << std::endl
			   << "} " << std::endl << std::endl
			   << "QLabel {" << std::endl
			   << "    background-color: #1d1d1d;" << std::endl
			   << "    font-size: 150px;" << std::endl
			   << "    font-family: Hack, Monospace, sans-serif;" << std::endl
			   << "    color: #00ff00;" << std::endl
			   << "} " << std::endl << std::endl
			   << "QLineEdit {" << std::endl
			   << "    border: 0px solid #000000;" << std::endl
			   << "    border-bottom: 1px solid #00ff00;" << std::endl
			   << "    font-size: 24px;" << std::endl
			   << "    color: #00ff00;" << std::endl
			   << "};" << std::endl;

		theme_file.close();

		theme_file.open(theme_file_name, std::fstream::in);
	}

	// theme file is already created
	std::string line;

	while (std::getline(theme_file, line))
		local_stylesheet += QString::fromStdString(line);

	theme_file.close();
}

void MainWindow::update_time()
{
	label_time->setText(QTime::currentTime().toString("hh:mm:ss"));
}

void MainWindow::update_alarms()
{
	std::fstream file_pointer;

	alarm_struct alarm;

	alarms.clear();

	file_pointer.open(ALARMS_FILE, std::fstream::in);

	if (!file_pointer.is_open()) {
		file_pointer.open(ALARMS_FILE, std::fstream::out | std::fstream::trunc);
		file_pointer << "25 3" << std::endl
			     << "25 3" << std::endl
			     << "25 3" << std::endl
			     << "Custom message" << std::endl;

		file_pointer.close();
		file_pointer.open(ALARMS_FILE, std::fstream::in);
	}

	for (int i = 0; i < 3; i++) {
		file_pointer >> alarm.hour >> alarm.minute;
		alarms.push_back(alarm);
	}

	file_pointer.close();

	for (int i = 0; i < 3; i++)
		display_alarm(i);
}

void MainWindow::insert_title()
{
	std::string current_line;
	std::fstream file_pointer;

	alarm_struct alarm;

	alarms.clear();

	file_pointer.open(ALARMS_FILE, std::fstream::in);

	if (!file_pointer.is_open()) {
		file_pointer.open(ALARMS_FILE, std::fstream::out | std::fstream::trunc);
		file_pointer << "25 3" << std::endl
			     << "25 3" << std::endl
			     << "25 3" << std::endl
			     << "Custom message" << std::endl;

		file_pointer.close();
		file_pointer.open(ALARMS_FILE, std::fstream::in);
	}

	for (int i = 0; i < 3; i++) {
		file_pointer >> alarm.hour >> alarm.minute;
		alarms.push_back(alarm);
	}

	do {
		std::getline(file_pointer, current_line);
	} while (current_line.empty());

	custom_message = current_line;
	lineedit_message->setText(QString::fromStdString(current_line));

	file_pointer.close();
}

void MainWindow::delete_alarm(int id)
{
	alarm_struct alarm;
	std::string current_line;
	std::fstream file_pointer;

	file_pointer.open(ALARMS_FILE, std::fstream::in);
	alarms.clear();

	for (int i = 0; i < 3; i++) {
		file_pointer >> alarm.hour >> alarm.minute;

		if (i == id) {
			alarm.hour = 25;
			alarm.minute = 3;
		}

		alarms.push_back(alarm);
	}

	do {
		std::getline(file_pointer, current_line);
	} while (current_line.empty());

	file_pointer.close();

	file_pointer.open(ALARMS_FILE, std::fstream::out | std::fstream::trunc);

	file_pointer << alarms[0].hour << " " << alarms[0].minute << std::endl
		     << alarms[1].hour << " " << alarms[1].minute << std::endl
		     << alarms[2].hour << " " << alarms[2].minute << std::endl
		     << current_line << std::endl;

	file_pointer.close();
}

void MainWindow::display_alarm(int alarm_id)
{
	switch (alarm_id)
	{
	case 0:
		if (alarms[0].hour == 25) {
			pushbutton_del0->hide();
			label_time0->hide();
		} else {
			pushbutton_del0->show();
			label_time0->setText((std::to_string(alarms[0].hour) + ":" + std::to_string(alarms[0].minute)).c_str());
			label_time0->show();
		}

		break;

	case 1:
		if (alarms[1].hour == 25) {
			pushbutton_del1->hide();
			label_time1->hide();
		} else {
			pushbutton_del1->show();
			label_time1->setText((std::to_string(alarms[1].hour) + ":" + std::to_string(alarms[1].minute)).c_str());
			label_time1->show();
		}

		break;

	case 2:
		if (alarms[2].hour == 25) {
			pushbutton_del2->hide();
			label_time2->hide();
		} else {
			pushbutton_del2->show();
			label_time2->setText((std::to_string(alarms[2].hour) + ":" + std::to_string(alarms[2].minute)).c_str());
			label_time2->show();
		}

		break;

	default:
		std::cerr << "Invalid alarm id: " << alarm_id << std::endl;
	}
}

void MainWindow::insert_elements()
{
	gridlayout->addWidget(pushbutton_connect, 0, 0);
	gridlayout->addWidget(pushbutton_add_alarm, 0, 4, 1, 1);
	gridlayout->addWidget(label_time, 1, 0, 2, 5);
	gridlayout->addWidget(lineedit_message, 3, 1, 1, 3);
	gridlayout->addWidget(pushbutton_del0, 4, 0);
	gridlayout->addWidget(pushbutton_del1, 5, 0);
	gridlayout->addWidget(pushbutton_del2, 6, 0);
	gridlayout->addWidget(label_time0, 4, 1, 1, 4);
	gridlayout->addWidget(label_time1, 5, 1, 1, 4);
	gridlayout->addWidget(label_time2, 6, 1, 1, 4);

	this_widget->setLayout(gridlayout);
}

void MainWindow::connect_bluetooth()
{
	if (!device_connected) {
		bluetooth_socket = niroge::bluetooth_connect("0f:f1:c3:0c:af:fe");
		if (bluetooth_socket == -1) {
			popup_message("Connection error!", "An error occoured while trying to connect to the "
				      "clock. Please check that the bluetooth is activated and that the clock "
				      "is in a short range");
			return;
		}

		pushbutton_connect->setText("Upload ");
		device_connected = true;
		popup_message("Configuration uploaded!", "Task terminated successfully! Disconnected from the device");
	} else {
		// niroge::bluetooth_send(bluetooth_socket, lol_me);
		bluetooth_socket = -1;
		pushbutton_connect->setText("Connect");
		device_connected = false;
		popup_message("Connected!", "You are connected to the device");

	}
}

void MainWindow::configure_elements()
{
	this_widget->setStyleSheet(local_stylesheet);

	label_time->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	gridlayout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

	this_widget->setWindowTitle("Arduino Alarm Manager");
	this_widget->setWindowIcon(QIcon("icons/logo.jpg"));

	lineedit_message->setToolTip("The custom message of the clock");

	pushbutton_add_alarm->setText("Alarm");
	pushbutton_add_alarm->setIcon(*icon_add);
	pushbutton_add_alarm->setToolTip("Add an alarm");

	pushbutton_connect->setText("Connect");
	pushbutton_connect->setToolTip("Connect to the alarm device");
	pushbutton_connect->setIcon(QIcon("icons/connect.jpg"));

	pushbutton_del0->setIcon(*icon_delete);
	pushbutton_del0->setFixedSize(icon_delete->actualSize(icon_delete->availableSizes().first()));
	pushbutton_del0->setToolTip("delete this alarm");

	pushbutton_del1->setIcon(*icon_delete);
	pushbutton_del1->setFixedSize(icon_delete->actualSize(icon_delete->availableSizes().first()));
	pushbutton_del1->setToolTip("delete this alarm");

	pushbutton_del2->setIcon(*icon_delete);
	pushbutton_del2->setFixedSize(icon_delete->actualSize(icon_delete->availableSizes().first()));
	pushbutton_del2->setToolTip("delete this alarm");

	label_time->setToolTip("Current time");

	label_time0->setStyleSheet("font-size: 42px; font-family: Monospace, sans-serif;");
	label_time0->setAlignment(Qt::AlignVCenter);
	label_time1->setStyleSheet("font-size: 42px; font-family: Monospace, sans-serif;");
	label_time1->setAlignment(Qt::AlignVCenter);
	label_time2->setStyleSheet("font-size: 42px; font-family: Monospace, sans-serif;");
	label_time2->setAlignment(Qt::AlignVCenter);
}

void MainWindow::popup_message(const char *title, const char *message)
{
	std::string theme_file_name = std::string(THEMES_DIRECTORY) + "/" + std::string(THEMES_POPUP_MESSAGE);
	std::string current_line;
	std::fstream theme_file;

	QString popup_stylesheet = "";

	theme_file.open(theme_file_name, std::fstream::in);

	if (!theme_file.is_open()) {
		theme_file.open(theme_file_name, std::fstream::out);
		theme_file << "/* this file is the stylesheet of the popup message, customize it as you wish */" << std::endl << std::endl
		           << "QWidget { " << std::endl
			   << "    background-color: #1d1d1d;" << std::endl
			   << "} " << std::endl << std::endl
			   << "QLabel { " << std::endl
			   << "    color: #fafafa;" << std::endl
			   << "    font-family: Hack, Monospace, Sans-Serif;" << std::endl
			   << "    font-size: 12px;" << std::endl
			   << "}; " << std::endl;

		theme_file.close();
		theme_file.open(theme_file_name, std::fstream::in);
	}

	while (std::getline(theme_file, current_line))
		popup_stylesheet += QString::fromStdString(current_line);


	QWidget *child_error = new QWidget;
	QGridLayout *gridlayout = new QGridLayout();
	QLabel *label_error = new QLabel(message, child_error);
	QPushButton *pushbutton_confirm = new QPushButton(child_error);

	child_error->setWindowTitle(title);
	child_error->setStyleSheet(popup_stylesheet);
	child_error->setMaximumWidth(640);

	label_error->setWordWrap(true);

	pushbutton_confirm->setText("Close");
	QObject::connect(pushbutton_confirm, SIGNAL(clicked()), child_error, SLOT(hide()));

	gridlayout->addWidget(label_error);
	gridlayout->addWidget(pushbutton_confirm);

	child_error->setLayout(gridlayout);
	child_error->show();
}

int main(int argument_counter, char **argument_vector)
{
	QApplication arduino_alarm_manager(argument_counter, argument_vector);
	MainWindow main_widget;

	return arduino_alarm_manager.exec();
}
