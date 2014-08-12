#ifndef QUIT_H
#define QUIT_H

#include <QMainWindow>


namespace Ui {
class quit;
}

class quit : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit quit(QWidget *parent = 0);
    ~quit();
    
private slots:


    void on_yes_clicked();

    void on_Cancel_clicked();

private:
    Ui::quit *ui;
};

#endif // QUIT_H
