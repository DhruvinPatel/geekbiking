#include "scores.h"
#include "ui_scores.h"
#include "name.h"
#include <iostream>
#include <fstream>
#include <QTextStream>

using namespace std;
QString text;
scores::scores(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::scores)
{
    this->showFullScreen();
    ui->setupUi(this);
    string STRING="";
    ifstream myreadfile;
    myreadfile.open("data.txt");
    while(!myreadfile.eof())
    {  string a = STRING;
       getline(myreadfile,STRING);
       STRING = a+"\n"+STRING;
    }
    QString s = STRING.c_str();
    myreadfile.close();
    ui->label_3->setText((QString)s);

}

scores::~scores()
{
    delete ui;
}


void scores::on_commandLinkButton_clicked()
{
    scores::close();
}
