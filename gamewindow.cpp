#include <QVector3D>
#include <QVector>

#include "gamewindow.h"

GameWindow::GameWindow()
{


}

GameWindow::~GameWindow()
{
}

void GameWindow::initialize()
{
}

void GameWindow::render(){
    const qreal retinaScale = devicePixelRatio();
    glViewport(0, 0, width() * retinaScale, height() * retinaScale);

    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);

    glClearColor(0.1, 0.1, 0.1, 1.0);

}


void GameWindow::keyPressEvent(QKeyEvent *event)
{

}

void GameWindow::keyReleaseEvent(QKeyEvent *event)
{

}
