#ifndef NEWGAME1_H
#define NEWGAME1_H

#include <QMainWindow>
#include "newgame2.h"

namespace Ui {
class newgame1;
}

class newgame1 : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit newgame1(QWidget *parent = 0);
    ~newgame1();
    
private slots:
    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_clicked();

    void on_commandLinkButton_3_clicked();

    void on_commandLinkButton_4_clicked();

    void on_commandLinkButton_5_clicked();

private:
    Ui::newgame1 *ui;
};

#endif // NEWGAME1_H
