#include <QVector3D>
#include <QVector>

#include "gamewindow.h"

GameWindow::GameWindow() : _playerProgram(0)
{
    _overMind = new OverMind();

    _renderTimer = new QTimer();
    connect(_renderTimer, SIGNAL(timeout()), this, SLOT(renderNow()));
    _renderTimer->start(30);

    _tick = new QTimer();
    connect(_tick, SIGNAL(timeout()), _overMind, SLOT(updateAgent()));
    _tick->start(60);
}

GameWindow::~GameWindow()
{
}

void GameWindow::initialize()
{
    initPlayerShaderPrograme();
}

void GameWindow::initPlayerShaderPrograme()
{
    _playerProgram = new QOpenGLShaderProgram(this);

    _playerProgram->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/player.vert");
    _playerProgram->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/player.frag");

    _playerProgram->link();

    _playerProgram->bind();

    _playerPosAttr = _playerProgram->attributeLocation("posAttr");
    _playerTeamAttr = _playerProgram->attributeLocation("teamAttr");
    _matrixUniform = _playerProgram->uniformLocation("matrix");

    _playerVao.create();
    _playerVao.bind();

    _playerVbo.create();
    _playerVbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
    _playerVbo.bind();

    _playerProgram->enableAttributeArray(_playerPosAttr);
    _playerProgram->enableAttributeArray(_playerTeamAttr);

    _playerVao.release();
    _playerProgram->release();
}

void GameWindow::render(){
    QMatrix4x4 matrix;

    const qreal retinaScale = devicePixelRatio();
    glViewport(0, 0, width() * retinaScale, height() * retinaScale);

    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);

    glClearColor(0.1, 0.1, 0.1, 1.0);

    QVector<QVector3D> vec;
    QVector<float> team;
    for (AbstractAgent * agent : _overMind->allAgents())
    {
        vec << agent->position();
        team << (float) agent->team();
    }

    _playerProgram->bind();
    _playerProgram->setUniformValue(_matrixUniform, matrix);

    _playerVao.bind();
    _playerVbo.bind();

    size_t playerSize = vec.size()*sizeof(QVector3D), teamSize = team.size()*sizeof(int);
    _playerProgram->setAttributeBuffer(_playerPosAttr, GL_FLOAT, 0, 3, 0);
    _playerProgram->setAttributeBuffer(_playerTeamAttr, GL_FLOAT, playerSize, 1, 0);

    _playerVbo.allocate(playerSize + teamSize);
    _playerVbo.write(0, vec.constData(), playerSize);
    _playerVbo.write(playerSize, team.constData(), teamSize);

    glDrawArrays(GL_POINTS, 0, vec.size());

    _playerVao.release();
    _playerProgram->release();
}


void GameWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Escape:
        close();
        break;
    }
}

void GameWindow::keyReleaseEvent(QKeyEvent *event)
{

}
