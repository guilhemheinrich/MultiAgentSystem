#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QtGui/QOpenGLShaderProgram>
#include <QtGui>
#include <QTimer>

#include "openglwindow.h"
#include "overmind.h"


class GameWindow : public OpenGLWindow
{
    Q_OBJECT
private:
    QOpenGLShaderProgram *_playerProgram;
    QOpenGLVertexArrayObject _playerVao;
    QOpenGLBuffer _playerVbo;

    GLuint _playerPosAttr, _playerTeamAttr, _playerCenterUni;
    GLuint _matrixUniform;
    OverMind *_overMind;

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    void initPlayerShaderPrograme();

    QTimer *_tick;

public:
    GameWindow();
    ~GameWindow();
    void render();
    void initialize();


public slots:
};

#endif // GAMEWINDOW_H
