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
