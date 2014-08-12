/********************************************************************************
** Form generated from reading UI file 'credits.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDITS_H
#define UI_CREDITS_H

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

class Ui_credits
{
public:
    QWidget *centralwidget;
    QCommandLinkButton *back;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *credits)
    {
        if (credits->objectName().isEmpty())
            credits->setObjectName(QStringLiteral("credits"));
        credits->resize(800, 600);
        centralwidget = new QWidget(credits);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        back = new QCommandLinkButton(centralwidget);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(20, 230, 71, 61));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        back->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix3/images/b2.ico"), QSize(), QIcon::Normal, QIcon::Off);
        back->setIcon(icon);
        back->setIconSize(QSize(200, 150));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 190, 301, 51));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(250, 270, 321, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(250, 340, 341, 41));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(-50, -20, 911, 651));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/32")));
        label_4->setScaledContents(true);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(60, 110, 421, 41));
        credits->setCentralWidget(centralwidget);
        label_4->raise();
        back->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_5->raise();
        menubar = new QMenuBar(credits);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        credits->setMenuBar(menubar);
        statusbar = new QStatusBar(credits);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        credits->setStatusBar(statusbar);

        retranslateUi(credits);

        QMetaObject::connectSlotsByName(credits);
    } // setupUi

    void retranslateUi(QMainWindow *credits)
    {
        credits->setWindowTitle(QApplication::translate("credits", "GEEK BIKING", 0));
        back->setText(QString());
        label->setText(QApplication::translate("credits", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600; color:#ff0000;\">ROHIT PRUTHI - 2012CS50296</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("credits", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600; color:#ff0000;\">DHRUVIN PATEL - 2012CS50293</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("credits", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600; color:#ff0000;\">KHUSHBOO GUPTA - 2012CS50288</span></p></body></html>", 0));
        label_4->setText(QString());
        label_5->setText(QApplication::translate("credits", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600;\">Design /Programming /Graphics :</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class credits: public Ui_credits {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDITS_H
