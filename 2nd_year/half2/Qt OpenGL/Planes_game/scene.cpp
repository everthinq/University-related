#include <QMatrix4x4>
#include "Scene.h"
#include <cstdlib>
#include <math.h>

Scene::Scene( QWidget *parent ) :
    QOpenGLWidget( parent )
{
    setFocusPolicy( Qt::StrongFocus );
    connect( &m_timer, SIGNAL( timeout() ), this, SLOT( RandomInitEnemy() ) );
    m_timer.start( 3000 );
}

Scene::~Scene()
{
    delete m_square;
    delete m_bullet;    delete bullet_ptr;
    delete m_enemy;     delete enemy_ptr;
}

void Scene::initializeGL()
{
    glClearColor( 0.87f, 1.0f, 1.0f, 1.0f );

    QOpenGLShader vShader( QOpenGLShader::Vertex );
    vShader.compileSourceFile( ":/Shaders/vShader.glsl" );

    QOpenGLShader fShader( QOpenGLShader::Fragment );
    fShader.compileSourceFile( ":/Shaders/fShader.glsl" );

    m_program.addShader( &vShader );
    m_program.addShader( &fShader );

    if ( !m_program.link() )
    {
        qWarning( "Error: unable to link a shader program." );
        return;
    }

    m_vertexAttr = m_program.attributeLocation( "vertexAttr" );
    m_colorAttr = m_program.attributeLocation( "colorAttr" );
    m_matrixUniform = m_program.uniformLocation( "matrix" );

    m_square = new Square( &m_program, m_vertexAttr, m_colorAttr, -0.3f, -2.0f, 0.7f );

    RandomInitEnemy();
}

void Scene::RandomInitEnemy()
{
       float rand;
       rand = (qrand() % 32 - 16) / 10.0;
       m_enemy = new Square( &m_program, m_vertexAttr, m_colorAttr, rand, 2.0f, 0.5f );

       enemy_list.append(m_enemy);
}

void Scene::InitBullet()
{
    m_bullet = new Square( &m_program, m_vertexAttr, m_colorAttr, m_square->x0() + 0.3f, m_square->y0() + 0.7f, 0.07f );

    bullet_list.append(m_bullet);
}


void Scene::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT );
    if ( !m_program.bind() )
        return;

    QMatrix4x4 matrix;
    matrix.ortho( -2.0f, 2.0f, -2.0f, 2.0f, 2.0f, -2.0f );
    m_program.setUniformValue( m_matrixUniform, matrix );

    m_square->draw();

    PrintAndMove();
    CheckCollision();
}

void Scene::PrintAndMove()
{
    for(int i = 0; i < enemy_list.length(); i++)
    {
        enemy_ptr = enemy_list.at(i);
        if (enemy_ptr)
        {
            enemy_ptr->draw();
            enemy_ptr->setY0 (enemy_ptr->y0() - enemy_step);
            update();
        }
    }

    for(int j = 0; j < bullet_list.length(); j++)
    {
        bullet_ptr = bullet_list.at(j);
        if(bullet_ptr)
        {
            bullet_ptr->draw();
            bullet_ptr->setY0 (bullet_ptr->y0() + bullet_step);
        }
    }
}

void Scene::CheckCollision()
{
    for(int i = 0, j = 0; i < enemy_list.length(), j < bullet_list.length(); i++, j++)
    {
       if( (bullet_ptr->y0() >= enemy_ptr->y0()) && (bullet_ptr->x0() + 0.1f >= enemy_ptr->x0()) && (bullet_ptr->x0() <= enemy_ptr->x0() + 0.4f) )
        {
            bullet_ptr->setX0(2.0);
            enemy_ptr->setX0(2.0);
        }
    }
}

void Scene::resizeGL( int w, int h )
{
    glViewport( 0, 0, w, h );
}

void Scene::keyPressEvent( QKeyEvent *event )
{
    switch( event->key() )
    {
       case Qt::Key_Left:
         if((m_square->x0() - p1_step) >= -2.1f)
             m_square->setX0( m_square->x0() - p1_step );
            break;
       case Qt::Key_Right:
         if((m_square->x0() + p1_step) <= 1.4f)
             m_square->setX0( m_square->x0() + p1_step );
            break;
       case Qt::Key_Space:
          InitBullet();
            break;
    }
    update();
}



