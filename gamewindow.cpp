#include <QVector3D>
#include <QVector>

#include "gamewindow.h"

GameWindow::GameWindow() : _playerProgram(0)
{
    _overMind = new OverMind();
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

    _playerVao.bind();

    _playerProgram->setAttributeBuffer(_playerPosAttr, GL_FLOAT, 0, 3, 0);

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
    QVector<int> team;
    for (AbstractAgent * agent : _overMind->allAgents()) {vec<<agent->position();team<<agent->team();}


    _playerProgram->bind();
    _playerProgram->setUniformValue(_matrixUniform, matrix);


    _playerVao.bind();
    _playerVbo.bind();

    size_t playerSize = vec.size()*sizeof(QVector3D), teamSize = team.size()*sizeof(int);
    _playerProgram->setAttributeBuffer(_playerPosAttr, GL_FLOAT, 0, 3, 0);
    _playerProgram->setAttributeBuffer(_playerTeamAttr, GL_FLOAT, playerSize, 1, 0);

    _playerVbo.allocate(playerSize + teamSize);
    _playerVbo.write(0, vec.constData(), playerSize);
    _playerVbo.write(teamSize, team.constData(), playerSize + teamSize);


    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glDrawArrays(GL_POINTS, 0, vec.size());
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

    _playerVao.release();
    _playerProgram->release();



}


void GameWindow::keyPressEvent(QKeyEvent *event)
{

}

void GameWindow::keyReleaseEvent(QKeyEvent *event)
{

}
