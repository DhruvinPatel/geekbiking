#include "buttons.h"
#include <QApplication>
#include <GL/freeglut.h>
#include "Game.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    glutInit(&argc, argv);


    buttons w;
    w.show();
    
    return a.exec();
}
