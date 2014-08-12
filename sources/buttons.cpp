#include "buttons.h"
#include "ui_buttons.h"

buttons::buttons(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::buttons)
{   //this->showFullScreen();
    ui->setupUi(this);
}

buttons::~buttons()
{
    delete ui;
}


void buttons::on_quit_clicked()
{
    quit *c = new quit();
     c->show();
}

void buttons::on_CREDITS_clicked()
{
    credits *d = new credits();
    d->show();
}

void buttons::on_newgame_clicked()
{
    newgame1 *e = new newgame1();
    e->show();
    name *h = new name();
    h->show();

}

void buttons::on_commandLinkButton_clicked()
{
    scores *f = new scores();
    f->show();
}

void buttons::on_help_clicked()
{
    help *g = new help();
    g->show();
}
