//
// Created by oksana on mew/mew/24.
//

#ifndef RCUBE_SOLVER_H
#define RCUBE_SOLVER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include "glcube.h"

typedef std::vector<int> cubestate;

class solver {
public:
    solver()=default;
    solver(std::vector<std::vector<int>>&);
    ~solver() = default;
private:
    std::vector<std::vector<int>> cv;
    std::string ColortoSide(int c);

    void mainSolve(int, std::vector<std::string>);
    cubestate id(cubestate);
    int inverse(int);
    cubestate applyMove(int, cubestate);
    std::string convertCubeState();
};

class algorithm {
public:
    void solveCube(std::vector<std::vector<int>>&);

};
#endif //RCUBE_SOLVER_H
