#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QtGui/QOpenGLShaderProgram>
#include <QtGui>
#include <QTimer>

#include "openglwindow.h"
#include "overmind.h"
#include "tools.h"

struct Border{
    QVector2D upperRight = QVector2D(1.0, 1.0);
    QVector2D bottomRight = QVector2D(1.0,-1.0);
    QVector2D bottomLeft = QVector2D(-1.0,-1.0);
    QVector2D upperLeft = QVector2D(-1.0,1.0);
};


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
    Border _border;

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    void initPlayerShaderPrograme();

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
