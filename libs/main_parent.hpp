class MainWindow : public QObject {
	QLineEdit *input_message = new QLineEdit();
	QWidget *widget_main = new QWidget();
	QGridLayout *layout = new QGridLayout();
	QPushButton *button_connect_upload = new QPushButton(QIcon("icons/connect.jpg"), "Connect");
	QPushButton *button_add_alarm = new QPushButton(QIcon("icons/add_alarm.jpg"), "Add alarm");
	QLabel *label_time = new QLabel(QTime::currentTime().toString("hh:mm:ss"));
	bool arduino_connected = false;
	AddAlarmWidget *add_alarm_widget = new AddAlarmWidget(this);
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
}

void MainWindow::update_alarms()
{
	std::string current_line;
	std::fstream file_pointer;

	file_pointer.open(ALARMS_FILE, std::fstream::in);

	alarms_list.clear();
	alarm_struct current_alarm;

	std::cout << "Updated alarms!" << std::endl;

	for (int i = 0; i < 3; i++) {
		file_pointer >> current_alarm.hour >> current_alarm.minute;
		alarms_list.push_back(current_alarm);
	}

	// this part sucks and must be updated, I *need* to actually study the library
	// so that I can find a better way to do this
	if (alarms_list[0].hour != 25) {
		std::cout << "Alarm 0 is visible" << std::endl;
		label_time_0->show();
		button_delete_0->show();
		label_time_0->setText((std::to_string(alarms_list[0].hour) + ":" + std::to_string(alarms_list[0].minute)).c_str());
	} else {
		std::cout << "Alarm 0 is *NOT* visible" << std::endl;
		label_time_0->hide();
		button_delete_0->hide();
	}

	if (alarms_list[1].hour != 25) {
		std::cout << "Alarm 1 is visible" << std::endl;
		label_time_1->show();
		button_delete_1->show();
		label_time_1->setText((std::to_string(alarms_list[1].hour) + ":" + std::to_string(alarms_list[1].minute)).c_str());
	} else {
		std::cout << "Alarm 1 is *NOT* visible" << std::endl;
		label_time_1->hide();
		button_delete_1->hide();
	}

	if (alarms_list[2].hour != 25) {
		std::cout << "Alarm 2 is visible" << std::endl;
		label_time_2->show();
		button_delete_2->show();
		label_time_2->setText((std::to_string(alarms_list[2].hour) + ":" + std::to_string(alarms_list[2].minute)).c_str());
	} else {
		std::cout << "Alarm 2 is *NOT* visible" << std::endl;
		label_time_2->hide();
		button_delete_2->hide();
	}

	std::cout << "alarm 0 -> " << alarms_list[0].hour << ":" << alarms_list[0].minute << std::endl;
	std::cout << "alarm 1 -> " << alarms_list[1].hour << ":" << alarms_list[1].minute << std::endl;
	std::cout << "alarm 2 -> " << alarms_list[2].hour << ":" << alarms_list[2].minute << std::endl;

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

	update_alarms();
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

	update_alarms();
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

	update_alarms();
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
