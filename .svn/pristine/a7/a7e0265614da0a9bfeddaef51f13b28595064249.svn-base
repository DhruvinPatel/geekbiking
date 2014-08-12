#ifndef BUTTONS_H
#define BUTTONS_H

#include <QMainWindow>
#include "quit.h"
#include "credits.h"
#include "newgame1.h"
#include "scores.h"
#include "help.h"
#include "name.h"

namespace Ui {
class buttons;
}

class buttons : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit buttons(QWidget *parent = 0);
    ~buttons();
    
private slots:

    void on_quit_clicked();

    void on_CREDITS_clicked();

    void on_newgame_clicked();

    void on_commandLinkButton_clicked();

    void on_help_clicked();

private:
    Ui::buttons *ui;
};

#endif // BUTTONS_H
