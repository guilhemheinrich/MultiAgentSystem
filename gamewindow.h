#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QtGui/QOpenGLShaderProgram>
#include <QtGui>
#include <QTimer>

#include "openglwindow.h"
#include "overmind.h"
#include "tools.h"
#include "border.h"

class GameWindow : public OpenGLWindow
{
    Q_OBJECT
private:
    QOpenGLShaderProgram *_playerProgram;
    QOpenGLVertexArrayObject _playerVao;
    QOpenGLBuffer _playerVbo;

    QOpenGLShaderProgram *_borderProgram;
    QOpenGLVertexArrayObject _borderVao;
    QOpenGLBuffer _borderVbo;

    GLuint _playerPosAttr, _playerTeamAttr, _playerCenterUni;
    GLuint _borderPosAttr, _borderColUni;
    GLuint _matrixUniform;

    OverMind *_overMind;

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    void initPlayerShaderPrograme();
    void initBorderShaderPrograme();

    QTimer *_renderTimer;
    QTimer *_tick;

public:
    GameWindow();
    ~GameWindow();
    void render();
    void initialize();


public slots:
};

#endif // GAMEWINDOW_H
