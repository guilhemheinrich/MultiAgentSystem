#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QtGui/QOpenGLShaderProgram>
#include <QtGui>
#include <QTimer>
#include "cpplinq.hpp"

#include "openglwindow.h"



class GameWindow : public OpenGLWindow
{
    Q_OBJECT
private:

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

public:
    GameWindow();
    ~GameWindow();
    void render();
    void initialize();


public slots:

};

#endif // GAMEWINDOW_H
