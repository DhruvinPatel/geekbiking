#include "newgame2.h"
#include "ui_newgame2.h"

newgame2::newgame2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newgame2)
{
    ui->setupUi(this);
}

newgame2::~newgame2()
{
    delete ui;
}

void newgame2::on_commandLinkButton_clicked()
{
    newgame2::close();
    newgame3 *c = new newgame3();
    c->show();
}

void newgame2::on_commandLinkButton_2_clicked()
{
    newgame2::close();
    newgame1 *d = new newgame1();
    d->show();
}

void newgame2::on_commandLinkButton_3_clicked()
{
    start(1,false);
}

void newgame2::on_commandLinkButton_4_clicked()
{
    start(4,false);
}
