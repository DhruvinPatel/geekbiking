#ifndef NAME_H
#define NAME_H
#include <string>
#include <QMainWindow>


extern QString text;
extern int score;


namespace Ui {

class name;

}

class name : public QMainWindow
{
    Q_OBJECT

public:
    explicit name(QWidget *parent = 0);

    ~name();
    


public slots:
    void on_pushButton_clicked();

private:
    Ui::name *ui;
};

#endif // NAME_H
