
// Class definitions
class AddAlarmWidget : public QObject {
	QSpinBox *spinbox_hours = new QSpinBox;
	QSpinBox *spinbox_minutes = new QSpinBox;
	QWidget *add_alarm_widget = new QWidget();
	MainWindow *parent_pointer;
	int hour = 0, minute = 0;

public:
	bool visible = false;
	AddAlarmWidget(MainWindow*);
	void show();
	void save_close();
};

AddAlarmWidget::AddAlarmWidget(MainWindow *parent)
{
	QFormLayout *layout_form = new QFormLayout;
	QPushButton *button_done = new QPushButton("OK", add_alarm_widget);
	parent_pointer = parent;

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
	parent_pointer->update_alarms();
}
