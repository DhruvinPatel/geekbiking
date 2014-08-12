#ifndef CREDITS_H
#define CREDITS_H

#include <QMainWindow>

namespace Ui {
class credits;
}

class credits : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit credits(QWidget *parent = 0);
    ~credits();
    
private slots:
    void on_back_clicked();

private:
    Ui::credits *ui;
};

#endif // CREDITS_H
