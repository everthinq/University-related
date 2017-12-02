#ifndef SCENE_H
#define SCENE_H

#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <QTimer>
#include <QKeyEvent>
#include "Square.h"
#include <QList>
#include <iterator>

class Scene : public QOpenGLWidget
{
    Q_OBJECT

public:
    Scene( QWidget *parent = 0 );
    ~Scene();


private slots:
      void RandomInitEnemy();  //enemy

private:
    void initializeGL();
    void paintGL();
    void resizeGL( int w, int h );

      void PrintAndMove();
        void InitBullet();  //bullet
    void CheckCollision();          //if (e == b) delete e;

    void keyPressEvent( QKeyEvent *event );

    QOpenGLShaderProgram m_program;
    int m_vertexAttr;
    int m_colorAttr;
    int m_matrixUniform;

    Square *m_square;
    Square *m_bullet;
    Square *m_enemy;

    Square *enemy_ptr;
    Square *bullet_ptr;

    QList <Square *> bullet_list;
    QList <Square *> enemy_list;

        static const float p1_step = 0.1f;   //m_square step
     static const float enemy_step = 0.001f;
    static const float bullet_step = 0.01f;

    QTimer m_timer;

};

#endif // SCENE_H

