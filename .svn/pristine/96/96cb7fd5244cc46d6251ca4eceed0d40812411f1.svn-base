#include "quit.h"
#include "ui_quit.h"

quit::quit(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::quit)
{
    //this->showFullScreen();
    ui->setupUi(this);
}

quit::~quit()
{
    delete ui;
}

void quit::on_yes_clicked()
{
    qApp->quit();
}

void quit::on_Cancel_clicked()
{
    quit::close();
}
