/********************************************************************************
** Form generated from reading UI file 'name.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAME_H
#define UI_NAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_name
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *name)
    {
        if (name->objectName().isEmpty())
            name->setObjectName(QStringLiteral("name"));
        name->resize(450, 300);
        centralwidget = new QWidget(name);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(180, 90, 121, 20));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 271, 51));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(290, 130, 41, 23));
        name->setCentralWidget(centralwidget);
        menubar = new QMenuBar(name);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 450, 21));
        name->setMenuBar(menubar);
        statusbar = new QStatusBar(name);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        name->setStatusBar(statusbar);

        retranslateUi(name);

        QMetaObject::connectSlotsByName(name);
    } // setupUi

    void retranslateUi(QMainWindow *name)
    {
        name->setWindowTitle(QApplication::translate("name", "GEEK BIKING", 0));
        label->setText(QApplication::translate("name", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600;\">ENTER YOUR NAME -</span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("name", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class name: public Ui_name {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAME_H
