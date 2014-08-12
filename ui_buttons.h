/********************************************************************************
** Form generated from reading UI file 'buttons.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUTTONS_H
#define UI_BUTTONS_H

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
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_buttons
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QCommandLinkButton *newgame;
    QCommandLinkButton *help;
    QCommandLinkButton *quit;
    QLabel *label_2;
    QCommandLinkButton *CREDITS;
    QCommandLinkButton *commandLinkButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *buttons)
    {
        if (buttons->objectName().isEmpty())
            buttons->setObjectName(QStringLiteral("buttons"));
        buttons->resize(1350, 750);
        buttons->setAutoFillBackground(false);
        centralWidget = new QWidget(buttons);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, -10, 1341, 721));
        label->setAcceptDrops(false);
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/2.jpg")));
        label->setScaledContents(true);
        newgame = new QCommandLinkButton(centralWidget);
        newgame->setObjectName(QStringLiteral("newgame"));
        newgame->setGeometry(QRect(1010, 360, 221, 71));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        newgame->setFont(font);
        newgame->setCursor(QCursor(Qt::PointingHandCursor));
        newgame->setMouseTracking(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix3/images/Actions media playback start.ico"), QSize(), QIcon::Normal, QIcon::Off);
        newgame->setIcon(icon);
        newgame->setIconSize(QSize(80, 55));
        help = new QCommandLinkButton(centralWidget);
        help->setObjectName(QStringLiteral("help"));
        help->setGeometry(QRect(1010, 440, 181, 61));
        help->setFont(font);
        help->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix3/images/h.ico"), QSize(), QIcon::Normal, QIcon::Off);
        help->setIcon(icon1);
        help->setIconSize(QSize(60, 50));
        quit = new QCommandLinkButton(centralWidget);
        quit->setObjectName(QStringLiteral("quit"));
        quit->setGeometry(QRect(1010, 600, 201, 61));
        quit->setFont(font);
        quit->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix3/images/Exit.ico"), QSize(), QIcon::Normal, QIcon::Off);
        quit->setIcon(icon2);
        quit->setIconSize(QSize(60, 60));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(-10, 0, 801, 91));
        QFont font1;
        font1.setFamily(QStringLiteral("Goudy Stout"));
        font1.setPointSize(36);
        font1.setBold(false);
        font1.setItalic(true);
        font1.setWeight(50);
        label_2->setFont(font1);
        CREDITS = new QCommandLinkButton(centralWidget);
        CREDITS->setObjectName(QStringLiteral("CREDITS"));
        CREDITS->setGeometry(QRect(20, 600, 191, 61));
        CREDITS->setFont(font);
        CREDITS->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/images/13"), QSize(), QIcon::Normal, QIcon::Off);
        CREDITS->setIcon(icon3);
        CREDITS->setIconSize(QSize(60, 60));
        commandLinkButton = new QCommandLinkButton(centralWidget);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(1010, 520, 251, 61));
        commandLinkButton->setFont(font);
        commandLinkButton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix3/images/sc2.ico"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton->setIcon(icon4);
        commandLinkButton->setIconSize(QSize(60, 50));
        buttons->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(buttons);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1350, 21));
        buttons->setMenuBar(menuBar);
        mainToolBar = new QToolBar(buttons);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        buttons->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(buttons);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        buttons->setStatusBar(statusBar);

        retranslateUi(buttons);

        QMetaObject::connectSlotsByName(buttons);
    } // setupUi

    void retranslateUi(QMainWindow *buttons)
    {
        buttons->setWindowTitle(QApplication::translate("buttons", "GEEK BIKING", 0));
        label->setText(QString());
        newgame->setText(QApplication::translate("buttons", "NEW GAME", 0));
        help->setText(QApplication::translate("buttons", "HELP", 0));
        quit->setText(QApplication::translate("buttons", "QUIT", 0));
        label_2->setText(QApplication::translate("buttons", "<html><head/><body><p><span style=\" font-size:48pt; color:#6f3700;\">geek biking</span></p></body></html>", 0));
        CREDITS->setText(QApplication::translate("buttons", "CREDITS", 0));
        commandLinkButton->setText(QApplication::translate("buttons", "HIGH SCORES", 0));
    } // retranslateUi

};

namespace Ui {
    class buttons: public Ui_buttons {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUTTONS_H
