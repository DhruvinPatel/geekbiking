#include "newgame3.h"
#include "ui_newgame3.h"

newgame3::newgame3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newgame3)
{
    ui->setupUi(this);
}

newgame3::~newgame3()
{
    delete ui;
}

void newgame3::on_commandLinkButton_2_clicked()
{
    newgame3::close();
    newgame2 *c = new newgame2();
    c->show();

}

void newgame3::on_commandLinkButton_clicked()
{
    start(6,true);
}

void newgame3::on_commandLinkButton_3_clicked()
{
    start(7,true);
}

void newgame3::on_commandLinkButton_4_clicked()
{
    start(8,true);
}

void newgame3::on_commandLinkButton_5_clicked()
{
    start(1,true);
}

void newgame3::on_commandLinkButton_6_clicked()
{
    start(9,true);
}
