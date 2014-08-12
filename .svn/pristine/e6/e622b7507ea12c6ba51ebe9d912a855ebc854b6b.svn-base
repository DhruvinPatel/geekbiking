#include "newgame1.h"
#include <stdio.h>
#include "ui_newgame1.h"
#include "Game.h"

int level = 0;
int terrain = 0;
newgame1::newgame1(QWidget *parent) :
		QMainWindow(parent), ui(new Ui::newgame1) {
	ui->setupUi(this);

}

newgame1::~newgame1() {
	delete ui;
}

void newgame1::on_commandLinkButton_2_clicked() {
	newgame1::close();
}

void newgame1::on_commandLinkButton_clicked() {
	newgame1::close();
	newgame2 *b = new newgame2();
	b->show();
}

void newgame1::on_commandLinkButton_3_clicked() {
    start(2,false);
}

void newgame1::on_commandLinkButton_4_clicked() {
    start(3,false);
}

void newgame1::on_commandLinkButton_5_clicked()
{
    start(5,false);
}
