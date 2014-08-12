#include "name.h"
#include "ui_name.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <queue>

using namespace std;
name::name(QWidget *parent) :
		QMainWindow(parent), ui(new Ui::name) {
	ui->setupUi(this);
}

name::~name() {
	delete ui;
}

using namespace std;
void name::on_pushButton_clicked() {

	text = ui->lineEdit->text();
	name::close();
}
