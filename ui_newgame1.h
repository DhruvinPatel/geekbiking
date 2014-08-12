/********************************************************************************
** Form generated from reading UI file 'newgame1.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWGAME1_H
#define UI_NEWGAME1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newgame1
{
public:
    QWidget *centralwidget;
    QCommandLinkButton *commandLinkButton;
    QLabel *label;
    QLabel *label_2;
    QCommandLinkButton *commandLinkButton_2;
    QCommandLinkButton *commandLinkButton_3;
    QCommandLinkButton *commandLinkButton_4;
    QCommandLinkButton *commandLinkButton_5;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *newgame1)
    {
        if (newgame1->objectName().isEmpty())
            newgame1->setObjectName(QStringLiteral("newgame1"));
        newgame1->resize(1350, 750);
        centralwidget = new QWidget(newgame1);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        commandLinkButton = new QCommandLinkButton(centralwidget);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(1160, 280, 141, 121));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix3/images/s1.ico"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton->setIcon(icon);
        commandLinkButton->setIconSize(QSize(150, 100));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 1341, 721));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix2/images/bg.jpg")));
        label->setScaledContents(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 40, 211, 61));
        commandLinkButton_2 = new QCommandLinkButton(centralwidget);
        commandLinkButton_2->setObjectName(QStringLiteral("commandLinkButton_2"));
        commandLinkButton_2->setGeometry(QRect(20, 280, 131, 111));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix3/images/b1.ico"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_2->setIcon(icon1);
        commandLinkButton_2->setIconSize(QSize(300, 100));
        commandLinkButton_3 = new QCommandLinkButton(centralwidget);
        commandLinkButton_3->setObjectName(QStringLiteral("commandLinkButton_3"));
        commandLinkButton_3->setGeometry(QRect(170, 150, 181, 181));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix2/images/tmap6icon.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_3->setIcon(icon2);
        commandLinkButton_3->setIconSize(QSize(181, 181));
        commandLinkButton_4 = new QCommandLinkButton(centralwidget);
        commandLinkButton_4->setObjectName(QStringLiteral("commandLinkButton_4"));
        commandLinkButton_4->setGeometry(QRect(470, 150, 181, 181));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix2/images/tmap7icon.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_4->setIcon(icon3);
        commandLinkButton_4->setIconSize(QSize(181, 181));
        commandLinkButton_5 = new QCommandLinkButton(centralwidget);
        commandLinkButton_5->setObjectName(QStringLiteral("commandLinkButton_5"));
        commandLinkButton_5->setGeometry(QRect(840, 150, 181, 181));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix2/images/tmap9icon.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_5->setIcon(icon4);
        commandLinkButton_5->setIconSize(QSize(181, 181));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(200, 360, 161, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(490, 360, 151, 41));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(880, 360, 101, 41));
        newgame1->setCentralWidget(centralwidget);
        label->raise();
        commandLinkButton->raise();
        label_2->raise();
        commandLinkButton_2->raise();
        commandLinkButton_3->raise();
        commandLinkButton_4->raise();
        commandLinkButton_5->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        menubar = new QMenuBar(newgame1);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1350, 25));
        newgame1->setMenuBar(menubar);
        statusbar = new QStatusBar(newgame1);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        newgame1->setStatusBar(statusbar);

        retranslateUi(newgame1);

        QMetaObject::connectSlotsByName(newgame1);
    } // setupUi

    void retranslateUi(QMainWindow *newgame1)
    {
        newgame1->setWindowTitle(QApplication::translate("newgame1", "GEEK BIKING", 0));
        commandLinkButton->setText(QString());
        label->setText(QString());
        label_2->setText(QApplication::translate("newgame1", "<html><head/><body><p><span style=\" font-size:36pt; font-weight:600; text-decoration: underline;\">EASY</span></p><p><br/></p></body></html>", 0));
        commandLinkButton_2->setText(QString());
        commandLinkButton_3->setText(QString());
        commandLinkButton_4->setText(QString());
        commandLinkButton_5->setText(QString());
        label_3->setText(QApplication::translate("newgame1", "<html><head/><body><p><span style=\" font-size:22pt; font-weight:600; color:#2a30a1;\">NEPTUNE</span></p></body></html>", 0));
        label_4->setText(QApplication::translate("newgame1", "<html><head/><body><p><span style=\" font-size:22pt; font-weight:600; color:#3141aa;\">MERCURY</span></p></body></html>", 0));
        label_5->setText(QApplication::translate("newgame1", "<html><head/><body><p><span style=\" font-size:22pt; font-weight:600; color:#2b3b96;\">MARS</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class newgame1: public Ui_newgame1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWGAME1_H
