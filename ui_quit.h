/********************************************************************************
** Form generated from reading UI file 'quit.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUIT_H
#define UI_QUIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_quit
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *yes;
    QPushButton *Cancel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *quit)
    {
        if (quit->objectName().isEmpty())
            quit->setObjectName(QStringLiteral("quit"));
        quit->resize(400, 200);
        centralwidget = new QWidget(quit);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, -10, 391, 191));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/quit.jpg")));
        label->setScaledContents(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 15, 361, 31));
        QFont font;
        font.setFamily(QStringLiteral("MV Boli"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        yes = new QPushButton(centralwidget);
        yes->setObjectName(QStringLiteral("yes"));
        yes->setGeometry(QRect(90, 80, 75, 23));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        yes->setFont(font1);
        Cancel = new QPushButton(centralwidget);
        Cancel->setObjectName(QStringLiteral("Cancel"));
        Cancel->setGeometry(QRect(180, 80, 75, 23));
        Cancel->setFont(font1);
        quit->setCentralWidget(centralwidget);
        menubar = new QMenuBar(quit);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 21));
        quit->setMenuBar(menubar);
        statusbar = new QStatusBar(quit);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        quit->setStatusBar(statusbar);

        retranslateUi(quit);

        QMetaObject::connectSlotsByName(quit);
    } // setupUi

    void retranslateUi(QMainWindow *quit)
    {
        quit->setWindowTitle(QApplication::translate("quit", "GEEK BIKING", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("quit", "Are you sure you want to exit ?", 0));
        yes->setText(QApplication::translate("quit", "Yes", 0));
        Cancel->setText(QApplication::translate("quit", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class quit: public Ui_quit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUIT_H
