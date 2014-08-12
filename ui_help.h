/********************************************************************************
** Form generated from reading UI file 'help.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_H
#define UI_HELP_H

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

class Ui_help
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QCommandLinkButton *commandLinkButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *help)
    {
        if (help->objectName().isEmpty())
            help->setObjectName(QStringLiteral("help"));
        help->resize(800, 600);
        help->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(help);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 90, 511, 341));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(-5, 0, 811, 591));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/sports_bike-wide.jpg")));
        label_2->setScaledContents(true);
        commandLinkButton = new QCommandLinkButton(centralwidget);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(500, 490, 131, 61));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        commandLinkButton->setFont(font);
        help->setCentralWidget(centralwidget);
        label_2->raise();
        label->raise();
        commandLinkButton->raise();
        menubar = new QMenuBar(help);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        help->setMenuBar(menubar);
        statusbar = new QStatusBar(help);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        help->setStatusBar(statusbar);

        retranslateUi(help);

        QMetaObject::connectSlotsByName(help);
    } // setupUi

    void retranslateUi(QMainWindow *help)
    {
        help->setWindowTitle(QApplication::translate("help", "GEEK BIKING", 0));
        label->setText(QApplication::translate("help", "<html><head/><body><p><span style=\" font-size:26pt; font-weight:600; text-decoration: underline; color:#ffffff;\">KEYBOARD COMMANDS :</span></p><p><span style=\" color:#ffffff;\"><br/></span></p><p><span style=\" font-size:20pt; font-weight:600; color:#ffffff;\">UP - Move Forward</span></p><p><span style=\" font-size:20pt; font-weight:600; color:#ffffff;\">DOWN - Move Backward</span></p><p><span style=\" font-size:20pt; font-weight:600; color:#ffffff;\">LEFT - Turn Left</span></p><p><span style=\" font-size:20pt; font-weight:600; color:#ffffff;\">RIGHT - Turn Right</span></p><p><span style=\" font-size:20pt; font-weight:600; color:#ffffff;\">SPACEBAR - High Jump</span></p></body></html>", 0));
        label_2->setText(QString());
        commandLinkButton->setText(QApplication::translate("help", "BACK", 0));
    } // retranslateUi

};

namespace Ui {
    class help: public Ui_help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
