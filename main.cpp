#include "openglwindow.h"
#include "gamewindow.h"
#include <QtGui/QGuiApplication>


int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);
    QSurfaceFormat format;

    GameWindow window;
    window.setFormat(format);

    window.resize(800, 800);
    window.show();

    window.setAnimating(false);

    return a.exec();
}

