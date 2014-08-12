#ifndef SCORES_H
#define SCORES_H

#include <QMainWindow>
#include "name.h"

namespace Ui {
class scores;
}

class scores : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit scores(QWidget *parent = 0);
    ~scores();
    






private slots:
    void on_commandLinkButton_clicked();

private:
    Ui::scores *ui;
};

#endif // SCORES_H
