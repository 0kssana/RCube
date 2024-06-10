//
// Created by oksana on mew/mew/24.
//
#include "glcube.h"
#include <iostream>
#include <cstring>

//--CUBIE--
std::vector<std::vector<int>> d_state = {
        {0,0,0,0,0,0,0,0,0},
        {4,4,4,4,4,4,4,4,4},
        {1,1,1,1,1,1,1,1,1},
        {5,5,5,5,5,5,5,5,5},
        {3,3,3,3,3,3,3,3,3},
        {2,2,2,2,2,2,2,2,2},
};

void Glcubie::setColor(position newPos, int newColor){
    color[newPos] = newColor;
}

// поворот на плоскости X0Y
void Glcubie::rotateZ()
{
    int tmp = color[right];
    color[right] = color[up];
    color[up] = color[left];
    color[left] = color[down];
    color[down] = tmp;
}

// поворот на плоскости X0Z
void Glcubie::rotateY()
{
    int tmp = color[right];
    color[right] = color[front];
    color[front] = color[left];
    color[left] = color[back];
    color[back] = tmp;
}

// поворот на плоскости Y0Z
void Glcubie::rotateX()
{
    int tmp = color[back];
    color[back] = color[up];
    color[up] = color[front];
    color[front] = color[down];
    color[down] = tmp;
}

void Glcubie::setColor(position pos) {

    static const GLfloat colors[7][3] =
            {   { 0.8f, 0.8f, 1.0f }, //(white)
                { 1.0f, 0.3f, 0.3f }, //(red)
                { 0.3f, 0.3f, 1.0f }, //(blue)
                {0.0f, 1.0f, 0.0f }, //(green)
                { 1.0f, 1.0f, 0.0f }, //(yellow)
                { 1.0f, 0.5f, 0.0f }, //(orange)
                { 0.0f, 0.0f, 0.0f },  // frame
            };

    const GLfloat* C = colors[color[pos]];
    glColor3fv(C);

}

void Glcubie::drawCubie(GLenum type = GL_QUADS) {
    glPushMatrix();
    glBegin(type);

    setColor(up);
    glNormal3f(0, 1, 0);
    glVertex3f(size, size, 0);
    glVertex3f(0, size, 0);
    glVertex3f(0, size, size);
    glVertex3f(size, size, size);

    setColor(down);
    glNormal3f(0, -1, 0);
    glVertex3f(size, 0, size);
    glVertex3f(0, 0, size);
    glVertex3f(0, 0, 0);
    glVertex3f(size, 0, 0);

    setColor(front);
    glNormal3f(0, 0, 1);
    glVertex3f(size, size, size);
    glVertex3f(0, size, size);
    glVertex3f(0, 0, size);
    glVertex3f(size, 0, size);

    setColor(back);
    glNormal3f(0, 0, -1);
    glVertex3f(size, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, size, 0);
    glVertex3f(size, size, 0);

    setColor(left);
    glNormal3f(-1, 0, 0);
    glVertex3f(0, size, size);
    glVertex3f(0, size, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, size);

    setColor(right);
    glNormal3f(1, 0, 0);
    glVertex3f(size, size, 0);
    glVertex3f(size, size, size);
    glVertex3f(size, 0, size);
    glVertex3f(size, 0, 0);

    glEnd();
    glPopMatrix();
}

void Glcubie::drawCubie(double x, double y, double z) {
    glPushMatrix();
    glTranslated(x, y, z);
    drawCubie();
    glPopMatrix();
}
