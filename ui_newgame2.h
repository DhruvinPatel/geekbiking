/********************************************************************************
** Form generated from reading UI file 'newgame2.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWGAME2_H
#define UI_NEWGAME2_H

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

class Ui_newgame2
{
public:
    QWidget *centralwidget;
    QCommandLinkButton *commandLinkButton;
    QLabel *label;
    QLabel *label_2;
    QCommandLinkButton *commandLinkButton_2;
    QCommandLinkButton *commandLinkButton_3;
    QCommandLinkButton *commandLinkButton_4;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *newgame2)
    {
        if (newgame2->objectName().isEmpty())
            newgame2->setObjectName(QStringLiteral("newgame2"));
        newgame2->resize(1350, 750);
        centralwidget = new QWidget(newgame2);
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
        commandLinkButton_3->setGeometry(QRect(300, 200, 181, 181));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix2/images/tmap2icon.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_3->setIcon(icon2);
        commandLinkButton_3->setIconSize(QSize(181, 181));
        commandLinkButton_4 = new QCommandLinkButton(centralwidget);
        commandLinkButton_4->setObjectName(QStringLiteral("commandLinkButton_4"));
        commandLinkButton_4->setGeometry(QRect(610, 200, 181, 181));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix2/images/tmap8icon.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_4->setIcon(icon3);
        commandLinkButton_4->setIconSize(QSize(181, 181));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(340, 400, 111, 41));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(650, 400, 121, 41));
        newgame2->setCentralWidget(centralwidget);
        label->raise();
        commandLinkButton->raise();
        label_2->raise();
        commandLinkButton_2->raise();
        commandLinkButton_3->raise();
        commandLinkButton_4->raise();
        label_3->raise();
        label_4->raise();
        menubar = new QMenuBar(newgame2);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1350, 25));
        newgame2->setMenuBar(menubar);
        statusbar = new QStatusBar(newgame2);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        newgame2->setStatusBar(statusbar);

        retranslateUi(newgame2);

        QMetaObject::connectSlotsByName(newgame2);
    } // setupUi

    void retranslateUi(QMainWindow *newgame2)
    {
        newgame2->setWindowTitle(QApplication::translate("newgame2", "GEEK BIKING", 0));
        commandLinkButton->setText(QString());
        label->setText(QString());
        label_2->setText(QApplication::translate("newgame2", "<html><head/><body><p><span style=\" font-size:36pt; font-weight:600; text-decoration: underline;\">HARD</span></p><p><br/></p></body></html>", 0));
        commandLinkButton_2->setText(QString());
        commandLinkButton_3->setText(QString());
        commandLinkButton_4->setText(QString());
        label_3->setText(QApplication::translate("newgame2", "<html><head/><body><p><span style=\" font-size:22pt; font-weight:600; color:#3553a3;\">EARTH</span></p></body></html>", 0));
        label_4->setText(QApplication::translate("newgame2", "<html><head/><body><p><span style=\" font-size:22pt; font-weight:600; color:#404d9f;\">MOON</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class newgame2: public Ui_newgame2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWGAME2_H
