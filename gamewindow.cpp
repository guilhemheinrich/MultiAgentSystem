#include <QVector3D>
#include <QVector>

#include "gamewindow.h"

GameWindow::GameWindow() : _playerProgram(0), _borderProgram(0)
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
        initBorderShaderPrograme();


}

void GameWindow::initPlayerShaderPrograme()
{
    _playerProgram = new QOpenGLShaderProgram(this);

    _playerProgram->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/player.vert");
    _playerProgram->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/player.frag");

    _playerProgram->link();


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


void GameWindow::initBorderShaderPrograme()
{

    QVector<QVector3D> vec;
    vec<<(QVector3D) _border.bottomLeft <<(QVector3D) _border.upperLeft << (QVector3D) _border.upperRight << (QVector3D) _border.bottomRight;
    size_t borderSize = vec.size()*sizeof(QVector3D);

    _borderProgram = new QOpenGLShaderProgram(this);

    _borderProgram->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/border.vert");
    _borderProgram->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/border.frag");

    _borderProgram->link();
    _borderProgram->bind();


    _borderPosAttr = _borderProgram->attributeLocation("posAttr");
    _borderColUni = _borderProgram->uniformLocation("colUni");
    _matrixUniform = _borderProgram->uniformLocation("matrix");


    _borderVao.create();
    _borderVao.bind();

    _borderVbo.create();
    _borderVbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
    _borderVbo.bind();

    _borderProgram->setAttributeBuffer(_borderPosAttr, GL_FLOAT, 0, 3, 0);
    _borderProgram->enableAttributeArray(_borderPosAttr);

    _borderVbo.allocate(borderSize);
    _borderVbo.write(0,vec.constData(), borderSize);


    _borderVao.release();
    _borderProgram->release();


}

void GameWindow::render(){
    QMatrix4x4 matrix;

    const qreal retinaScale = devicePixelRatio();
    glViewport(0, 0, width() * retinaScale, height() * retinaScale);

    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
    glEnable(GL_POINT_SMOOTH);

    glClearColor(0.1, 0.1, 0.1, 1.0);

    _borderProgram->bind();

    _borderProgram->setUniformValue(_matrixUniform, matrix);
    _borderProgram->setUniformValue(_borderColUni, QVector4D(1.0,0.0,0.0,1.0));

    _borderVao.bind();
    _borderVbo.bind();

    _borderProgram->enableAttributeArray(_borderPosAttr);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDrawArrays(GL_POLYGON, 0, 4);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        _borderProgram->disableAttributeArray(_borderPosAttr);

            qDebug()<<_borderPosAttr << _borderColUni;
    _borderVao.release();
    _borderProgram->release();

    QVector<QVector3D> vec;
//    vec.clear(); // Already declared upper
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

    _playerProgram->enableAttributeArray(_playerPosAttr);
    _playerProgram->enableAttributeArray(_playerTeamAttr);

    size_t playerSize = vec.size()*sizeof(QVector3D), teamSize = team.size()*sizeof(int);
    _playerProgram->setAttributeBuffer(_playerPosAttr, GL_FLOAT, 0, 3, 0);
    _playerProgram->setAttributeBuffer(_playerTeamAttr, GL_FLOAT, playerSize, 1, 0);

    _playerVbo.allocate(playerSize + teamSize);
    _playerVbo.write(0, vec.constData(), playerSize);
    _playerVbo.write(playerSize, team.constData(), teamSize);

    glDrawArrays(GL_POINTS, 0, vec.size());

    _playerProgram->disableAttributeArray(_playerPosAttr);
    _playerProgram->disableAttributeArray(_playerTeamAttr);
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
    case Qt::Key_R:
        _overMind->initializeSimulation();
        break;
    }
}

void GameWindow::keyReleaseEvent(QKeyEvent *event)
{

}
