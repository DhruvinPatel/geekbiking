/********************************************************************************
** Form generated from reading UI file 'newgame3.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWGAME3_H
#define UI_NEWGAME3_H

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

class Ui_newgame3
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QCommandLinkButton *commandLinkButton_2;
    QCommandLinkButton *commandLinkButton;
    QCommandLinkButton *commandLinkButton_3;
    QCommandLinkButton *commandLinkButton_4;
    QCommandLinkButton *commandLinkButton_5;
    QCommandLinkButton *commandLinkButton_6;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *newgame3)
    {
        if (newgame3->objectName().isEmpty())
            newgame3->setObjectName(QStringLiteral("newgame3"));
        newgame3->resize(1350, 750);
        centralwidget = new QWidget(newgame3);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 1341, 721));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix2/images/bg.jpg")));
        label->setScaledContents(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 40, 261, 61));
        commandLinkButton_2 = new QCommandLinkButton(centralwidget);
        commandLinkButton_2->setObjectName(QStringLiteral("commandLinkButton_2"));
        commandLinkButton_2->setGeometry(QRect(20, 280, 131, 111));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix3/images/b1.ico"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_2->setIcon(icon);
        commandLinkButton_2->setIconSize(QSize(300, 100));
        commandLinkButton = new QCommandLinkButton(centralwidget);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(180, 190, 181, 181));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix2/images/tmp1icon.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton->setIcon(icon1);
        commandLinkButton->setIconSize(QSize(181, 181));
        commandLinkButton_3 = new QCommandLinkButton(centralwidget);
        commandLinkButton_3->setObjectName(QStringLiteral("commandLinkButton_3"));
        commandLinkButton_3->setGeometry(QRect(470, 190, 181, 181));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix2/images/tmp2icon.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_3->setIcon(icon2);
        commandLinkButton_3->setIconSize(QSize(181, 181));
        commandLinkButton_4 = new QCommandLinkButton(centralwidget);
        commandLinkButton_4->setObjectName(QStringLiteral("commandLinkButton_4"));
        commandLinkButton_4->setGeometry(QRect(840, 190, 181, 181));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix2/images/tmp3icon.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_4->setIcon(icon3);
        commandLinkButton_4->setIconSize(QSize(181, 181));
        commandLinkButton_5 = new QCommandLinkButton(centralwidget);
        commandLinkButton_5->setObjectName(QStringLiteral("commandLinkButton_5"));
        commandLinkButton_5->setGeometry(QRect(300, 450, 181, 181));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix2/images/tmap2icon.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_5->setIcon(icon4);
        commandLinkButton_5->setIconSize(QSize(181, 181));
        commandLinkButton_6 = new QCommandLinkButton(centralwidget);
        commandLinkButton_6->setObjectName(QStringLiteral("commandLinkButton_6"));
        commandLinkButton_6->setGeometry(QRect(630, 450, 181, 181));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/prefix2/images/tmp4icon.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_6->setIcon(icon5);
        commandLinkButton_6->setIconSize(QSize(181, 181));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(220, 400, 121, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(500, 400, 151, 31));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(330, 650, 121, 41));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(666, 650, 131, 41));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(870, 390, 111, 41));
        newgame3->setCentralWidget(centralwidget);
        menubar = new QMenuBar(newgame3);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1350, 25));
        newgame3->setMenuBar(menubar);
        statusbar = new QStatusBar(newgame3);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        newgame3->setStatusBar(statusbar);

        retranslateUi(newgame3);

        QMetaObject::connectSlotsByName(newgame3);
    } // setupUi

    void retranslateUi(QMainWindow *newgame3)
    {
        newgame3->setWindowTitle(QApplication::translate("newgame3", "GEEK BIKING", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("newgame3", "<html><head/><body><p><span style=\" font-size:36pt; font-weight:600; text-decoration: underline;\">PRACTICE</span></p><p><br/></p></body></html>", 0));
        commandLinkButton_2->setText(QString());
        commandLinkButton->setText(QString());
        commandLinkButton_3->setText(QString());
        commandLinkButton_4->setText(QString());
        commandLinkButton_5->setText(QString());
        commandLinkButton_6->setText(QString());
        label_3->setText(QApplication::translate("newgame3", "<html><head/><body><p><span style=\" font-size:22pt; font-weight:600; color:#334a96;\">PLUTO</span></p></body></html>", 0));
        label_4->setText(QApplication::translate("newgame3", "<html><head/><body><p><span style=\" font-size:22pt; font-weight:600; color:#36437e;\">SATURN</span></p></body></html>", 0));
        label_5->setText(QApplication::translate("newgame3", "<html><head/><body><p><span style=\" font-size:22pt; font-weight:600; color:#32397c;\">EARTH</span></p></body></html>", 0));
        label_6->setText(QApplication::translate("newgame3", "<html><head/><body><p><span style=\" font-size:22pt; font-weight:600; color:#434494;\">JUPITER</span></p></body></html>", 0));
        label_7->setText(QApplication::translate("newgame3", "<html><head/><body><p><span style=\" font-size:22pt; font-weight:600; color:#2f388a;\">VENUS</span></p><p><br/></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class newgame3: public Ui_newgame3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWGAME3_H
