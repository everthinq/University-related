#ifndef SQUARE_H
#define SQUARE_H

#include <QOpenGLShaderProgram>
#include <vector>

class Square
{
public:
    Square( QOpenGLShaderProgram *program,
            int vertexAttr,
            int colorAttr,
            float M_x0,
            float M_y0,
            float M_size);
    ~Square();

    void draw();

    void setX0( float x );
    void setY0( float y );

    float x0() const;
    float y0() const;


private:
    void initVertices();
    void initColors();

    std::vector <float> m_vertices;
    std::vector <float> m_colors;

    QOpenGLShaderProgram *m_program;
    int m_vertexAttr;
    int m_colorAttr;

    float m_x0;
    float m_y0;
    const float m_size;
};

#endif // SQUARE_H
