#include "Square.h"

Square::Square( QOpenGLShaderProgram *program,
                int vertexAttr,
                int colorAttr,
                float M_x0,
                float M_y0,
                float M_size) :
    m_program( program ),
    m_vertexAttr( vertexAttr ),
    m_colorAttr( colorAttr ),
    m_x0( M_x0 ),    //-0.3f
    m_y0( M_y0 ),    //-2.0f
    m_size( M_size ) //0.7f
{
    initVertices();
    initColors();
}

Square::~Square()
{
}

void Square::initVertices()
{
    m_vertices.resize( 18 );

    // 0
    m_vertices[0] = m_x0;
    m_vertices[1] = m_y0;
    m_vertices[2] = 0.0f;

    // 1
    m_vertices[3] = m_x0 + m_size;
    m_vertices[4] = m_y0;
    m_vertices[5] = 0.0f;

    // 2
    m_vertices[6] = m_x0;
    m_vertices[7] = m_y0 + m_size;
    m_vertices[8] = 0.0f;

    // 3
    m_vertices[9] = m_x0;
    m_vertices[10] = m_y0 + m_size;
    m_vertices[11] = 0.0f;

    // 4
    m_vertices[12] = m_x0 + m_size;
    m_vertices[13] = m_y0;
    m_vertices[14] = 0.0f;

    // 5
    m_vertices[15] = m_x0 + m_size;
    m_vertices[16] = m_y0 + m_size;
    m_vertices[17] = 0.0f;
}

void Square::initColors()
{
    m_colors.resize( 18 );

    // 0
    m_colors[0] = 1.0f;
    m_colors[1] = 0.0f;
    m_colors[2] = 0.0f;

    // 1
    m_colors[3] = 0.0f;
    m_colors[4] = 1.0f;
    m_colors[5] = 0.0f;

    // 2
    m_colors[6] = 0.0f;
    m_colors[7] = 0.0f;
    m_colors[8] = 1.0f;

    // 3
    m_colors[9] = 1.0f;
    m_colors[10] = 0.0f;
    m_colors[11] = 0.0f;

    // 4
    m_colors[12] = 0.0f;
    m_colors[13] = 1.0f;
    m_colors[14] = 0.0f;

    // 5
    m_colors[15] = 0.0f;
    m_colors[16] = 0.0f;
    m_colors[17] = 1.0f;
}

void Square::draw()
{
    m_program->setAttributeArray( m_vertexAttr, m_vertices.data(), 3 );
    m_program->setAttributeArray( m_colorAttr, m_colors.data(), 3 );

    m_program->enableAttributeArray( m_vertexAttr );
    m_program->enableAttributeArray( m_colorAttr );

    glDrawArrays( GL_TRIANGLES, 0, 6 );

    m_program->disableAttributeArray( m_vertexAttr );
    m_program->disableAttributeArray( m_colorAttr );
}

void Square::setX0( float x )
{
    m_x0 = x;
    initVertices();
}

void Square::setY0( float y )
{
    m_y0 = y;
    initVertices();
}

float Square::x0() const
{
    return m_x0;
}

float Square::y0() const
{
    return m_y0;
}

