/********************************************************************************
** Form generated from reading UI file 'scores.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCORES_H
#define UI_SCORES_H

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

class Ui_scores
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QCommandLinkButton *commandLinkButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *scores)
    {
        if (scores->objectName().isEmpty())
            scores->setObjectName(QStringLiteral("scores"));
        scores->resize(600, 400);
        centralwidget = new QWidget(scores);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 2, 591, 371));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/12")));
        label->setScaledContents(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 10, 181, 41));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(170, 82, 211, 241));
        label_3->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 127);\n"
"font: italic 22pt \"Monotype Corsiva\";"));
        commandLinkButton = new QCommandLinkButton(centralwidget);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(420, 270, 151, 71));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        commandLinkButton->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/images/10"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton->setIcon(icon);
        commandLinkButton->setIconSize(QSize(50, 50));
        scores->setCentralWidget(centralwidget);
        menubar = new QMenuBar(scores);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 21));
        scores->setMenuBar(menubar);
        statusbar = new QStatusBar(scores);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        scores->setStatusBar(statusbar);

        retranslateUi(scores);

        QMetaObject::connectSlotsByName(scores);
    } // setupUi

    void retranslateUi(QMainWindow *scores)
    {
        scores->setWindowTitle(QApplication::translate("scores", "MainWindow", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("scores", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600;\">HIGH SCORES</span></p></body></html>", 0));
        label_3->setText(QString());
        commandLinkButton->setText(QApplication::translate("scores", "BACK", 0));
    } // retranslateUi

};

namespace Ui {
    class scores: public Ui_scores {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCORES_H
