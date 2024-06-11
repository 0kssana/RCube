//
// Created by oksana on mew/mew/24.
//

#include "solver.h"
#include <python3.11/Python.h>
#include <string>
#include <fstream>

/**********************************************************************
 *
 * A cube 'state' is a vector<int> with 40 entries, the first 20
 * are a permutation of {0,...,19} and describe which cubie is at
 * a certain position (regarding the input ordering). The first
 * twelve are for edges, the last eight for corners.
 *
 * The last 20 entries are for the orientations, each describing
 * how often the cubie at a certain position has been turned
 * counterclockwise away from the correct orientation. Again the
 * first twelve are edges, the last eight are corners. The values
 * are 0 or 1 for edges and 0, 1 or 2 for corners.
 *
 **********************************************************************/

int applicableMoves[] = {0, 262143, 259263, 74943, 74898};

int affectedCubies[][8] = {
        { 0, 1, 2, 3, 0, 1, 2, 3 },   // U
        { 4, 7, 6, 5, 4, 5, 6, 7 },   // D
        { 0, 9, 4, 8, 0, 3, 5, 4 },   // F
        { 2, 10, 6, 11, 2, 1, 7, 6 }, // B
        { 3, 11, 7, 9, 3, 2, 6, 5 },  // L
        { 1, 8, 5, 10, 1, 0, 4, 7 },  // R
};

std::string solver::ColortoSide(int c){
    int U,D,F,B,L,R;
    F = cv[front][4];
    B = cv[back][4];
    U = cv[up][4];
    D = cv[down][4];
    L = cv[left][4];
    R = cv[right][4];
    if (c == F)
        return "F";
    else if (c == B)
        return "B";
    else if (c == U)
        return "U";
    else if (c == D)
        return "D";
    else if (c == L)
        return "L";
    else if (c == R)
        return "R";
    else
        throw std::runtime_error("Solver is broken!\n");
}

solver::solver(std::vector<std::vector<int>>& cv0) {
/*    c.saveCube();
    cv = c.saved();*/
    cv = cv0;
    std::vector<std::string> res(21);
    res[0] = "SKIP";
    res[1] = ColortoSide(cv[up][7])+ColortoSide(cv[front][1]);
    res[2] = ColortoSide(cv[up][5]) +ColortoSide(cv[right][1]);
    res[3] = ColortoSide(cv[up][2]) +ColortoSide(cv[back][7]);
    res[4] = ColortoSide(cv[up][3])+ColortoSide(cv[left][1]);
    res[5] = ColortoSide(cv[down][1]) + ColortoSide(cv[front][7]);
    res[6] = ColortoSide(cv[down][5]) + ColortoSide(cv[right][7]);
    res[7] = ColortoSide(cv[down][7])+ColortoSide(cv[back][1]);
    res[8] = ColortoSide(cv[down][3]) + ColortoSide(cv[left][7]);
    res[9] = ColortoSide(cv[front][5])+ColortoSide(cv[right][3]);
    res[10] = ColortoSide(cv[front][3]) + ColortoSide(cv[left][5]);
    res[11] = ColortoSide(cv[back][5])+ColortoSide(cv[right][5]);
    res[12] = ColortoSide(cv[back][3])+ColortoSide(cv[left][3]);
    res[13] = ColortoSide(cv[up][8]) + ColortoSide(cv[front][2]) + ColortoSide(cv[right][0]);
    res[14] = ColortoSide(cv[up][2]) + ColortoSide(cv[right][2]) + ColortoSide(cv[back][8]);
    res[15] = ColortoSide(cv[up][0]) + ColortoSide(cv[back][6]) + ColortoSide(cv[left][0]);
    res[16] = ColortoSide(cv[up][6]) + ColortoSide(cv[left][2]) + ColortoSide(cv[front][0]);
    res[17] = ColortoSide(cv[down][2]) + ColortoSide(cv[right][6]) + ColortoSide(cv[front][8]);
    res[18] = ColortoSide(cv[down][0]) + ColortoSide(cv[front][6]) + ColortoSide(cv[left][8]);
    res[19] = ColortoSide(cv[down][6]) + ColortoSide(cv[left][6]) + ColortoSide(cv[back][0]);
    res[20] = ColortoSide(cv[down][8]) + ColortoSide(cv[back][2]) + ColortoSide(cv[right][8]);
    mainSolve(21, res);

}


cubestate solver::applyMove(int move, cubestate state)
{
    int turns = move % 3 + 1;
    int face = move / 3;

    while (turns--) {
        cubestate oldState = state;

        for (int i = 0; i < 8; i++) {
            int isCorner = i > 3;
            int target = affectedCubies[face][i] + isCorner * 12;
            int killer = affectedCubies[face][(i & 3) == 3 ? i - 3 : i + 1] + isCorner * 12;
            int orientationDelta = (i < 4) ? (face > 1 && face < 4) : (face < 2) ? 0 : 2 - (i & 1);

            state[target] = oldState[killer];
            state[target + 20] = oldState[killer + 20] + orientationDelta;

            if (!turns)
                state[target + 20] %= 2 + isCorner;
        }
    }
    return state;
}

int solver::inverse(int move)
{
    return move + 2 - 2 * (move % 3);
}

int phase;

cubestate solver::id(cubestate state)
{

    //--- Phase 1: Edge orientations.
    if (phase < 2)
        return cubestate(state.begin() + 20, state.begin() + 32);

    //-- Phase 2: Corner orientations, E slice edges.
    if (phase < 3) {
        cubestate result(state.begin() + 31, state.begin() + 40);
        for (int e = 0; e < 12; e++)
            result[0] |= (state[e] / 8) << e;
        return result;
    }

    //--- Phase 3: Edge slices M and S, corner tetrads, overall parity.
    if (phase < 4) {
        cubestate result(3);
        for (int e = 0; e < 12; e++)
            result[0] |= ((state[e] > 7) ? 2 : (state[e] & 1)) << (2 * e);
        for (int c = 0; c < 8; c++)
            result[1] |= ((state[c + 12] - 12) & 5) << (3 * c);
        for (int i = 12; i < 20; i++)
            for (int j = i + 1; j < 20; j++)
                result[2] ^= state[i] > state[j];
        return result;
    }

    //--- Phase 4: The rest.
    return state;
}


void solver::mainSolve(int argc, std::vector<std::string> argv)
{
    std::ofstream storage("storage.txt");
    //--- Define the goal.
    std::string goal[] = { "UF", "UR", "UB", "UL", "DF", "DR", "DB", "DL", "FR", "FL", "BR", "BL",
                           "UFR", "URB", "UBL", "ULF", "DRF", "DFL", "DLB", "DBR" };

    //--- Prepare current (start) and goal state.
    cubestate currentState(40), goalState(40);
    for (int i = 0; i < 20; i++) {

        //--- Goal state.
        goalState[i] = i;

        //--- Current (start) state.
        std::string cubie = argv[i + 1];
        while ((currentState[i] = find(goal, goal + 20, cubie) - goal) == 20) {
            cubie = cubie.substr(1) + cubie[0];
            currentState[i + 20]++;
        }
    }

    //--- Dance the funky Thistlethwaite...
    while (++phase < 5) {

        //--- Compute ids for current and goal state, skip phase if equal.
        cubestate currentId = id(currentState), goalId = id(goalState);
        if (currentId == goalId)
            continue;

        //--- Initialize the BFS queue.
        std::queue<cubestate> q;
        q.push(currentState);
        q.push(goalState);

        //--- Initialize the BFS tables.
        std::map<cubestate, cubestate> predecessor;
        std::map<cubestate, int> direction, lastMove;
        direction[currentId] = 1;
        direction[goalId] = 2;

        //--- Dance the funky bidirectional BFS...
        while (1) {

            //--- Get state from queue, compute its ID and get its direction.
            cubestate oldState = q.front();
            q.pop();
            cubestate oldId = id(oldState);
            int& oldDir = direction[oldId];

            //--- Apply all applicable moves to it and handle the new state.
            for (int move = 0; move < 18; move++) {
                if (applicableMoves[phase] & (1 << move)) {

                    //--- Apply the move.
                    cubestate newState = applyMove(move, oldState);
                    cubestate newId = id(newState);
                    int& newDir = direction[newId];

                    //--- Have we seen this state (id) from the other direction already?
                    //--- I.e. have we found a connection?
                    if (newDir && newDir != oldDir) {

                        //--- Make oldId represent the forwards and newId the backwards search state.
                        if (oldDir > 1) {
                            swap(newId, oldId);
                            move = inverse(move);
                        }

                        //--- Reconstruct the connecting algorithm.
                        cubestate algorithm(1, move);
                        while (oldId != currentId) {
                            algorithm.insert(algorithm.begin(), lastMove[oldId]);
                            oldId = predecessor[oldId];
                        }
                        while (newId != goalId) {
                            algorithm.push_back(inverse(lastMove[newId]));
                            newId = predecessor[newId];
                        }

                        //--- Print and apply the algorithm.
                        for (int i = 0; i < (int)algorithm.size(); i++) {
                            storage << "230145"[algorithm[i] / 3] << algorithm[i] % 3 + 1;
                            currentState = applyMove(algorithm[i], currentState);
                        }

                        //--- Jump to the next phase.
                        goto nextPhase;
                    }

                    //--- If we've never seen this state (id) before, visit it.
                    if (!newDir) {
                        q.push(newState);
                        newDir = oldDir;
                        lastMove[newId] = move;
                        predecessor[newId] = oldId;
                    }
                }
            }
        }
        nextPhase:;
    }
    storage.close();
}

void algorithm::solveCube(std::vector<std::vector<int>> & cubeFormat) {
    std::ofstream out ("algorithm.txt");
    std::vector<char> colorMap = {'U', 'R', 'B', 'L', 'F', 'D'};

    if (cubeFormat.size() != 6 || cubeFormat[0].size() != 9) {
        throw std::invalid_argument("Invalid cube state format");
    }

    std::string cubeState;

    // Преобразуем состояние в строку
    for (const auto& face : cubeFormat) {
        for (int color : face) {
            cubeState += colorMap[color];
        }
    }
    Py_Initialize();

    // Импортируем модуль kociemba
    PyObject* pName = PyUnicode_DecodeFSDefault("kociemba");
    PyObject* pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != nullptr) {
        // Получаем ссылку на функцию solve из модуля kociemba
        PyObject* pFunc = PyObject_GetAttrString(pModule, "solve");

        if (pFunc && PyCallable_Check(pFunc)) {
            // Подготавливаем аргументы для функции solve
            PyObject* pArgs = PyTuple_Pack(1, PyUnicode_FromString(cubeState.c_str()));

            // Вызываем функцию solve
            PyObject* pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);

            if (pValue != nullptr) {
                // Получаем результат и преобразуем его в std::string
                std::string result = PyUnicode_AsUTF8(pValue);
                Py_DECREF(pValue);
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                // Завершаем работу интерпретатора Python
                Py_Finalize();
                out << result;
            } else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                PyErr_Print();
                Py_Finalize();
                throw std::runtime_error("Failed to call function solve");
            }
        } else {
            if (PyErr_Occurred())
                PyErr_Print();
            Py_DECREF(pModule);
            Py_Finalize();
            throw std::runtime_error("Cannot find function solve");
        }
    } else {
        PyErr_Print();
        Py_Finalize();
        throw std::runtime_error("Failed to load kociemba module");
    }

}

