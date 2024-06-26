/**
 * \file cube.h
 * \brief Заголовочный файл со структурами.
 */

#pragma once

#include <GL/glut.h>
#include <vector>
#include <iostream>

using std::cout;
using std::vector;


/**
 * \enum colors
 * \brief Цвета кубика Рубика.
 */

enum colors {
    GREEN,
    WHITE,
    BLUE,
    YELLOW,
    ORANGE,
    RED
};


/**
 * \class Cube
 * \brief Базовый абстрактный класс для кубика Рубика.
 * Этот класс представляет собой кубик Рубика с методами для управления его состоянием и выполнения операций.
 * Включает методы для вращений, алгоритмов решения, заполнения цветами и графического отображения.
 */
class Cube{
private:
    friend class CubeTest;
    friend class MockCube;
    int const size = 3;
    vector<vector<colors>> left;
    vector<vector<colors>> front;
    vector<vector<colors>> right;
    vector<vector<colors>> back;
    vector<vector<colors>> up;
    vector<vector<colors>> down;
    struct palette {
        float RED;
        float GREEN;
        float BLUE;
    };
    struct x_y_z {
        float x;
        float y;
        float z;
    };
    float rotate_x = 0;
    float rotate_y = 0;
public:

    /**
     * \brief Конструктор для класса Cube.
     *
     * Инициализирует кубик Рубика начальными цветами.
     */
    Cube(){
        for(int i = 0; i < size; i++){
            left.push_back({});
            front.push_back({});
            right.push_back({});
            back.push_back({});
            up.push_back({});
            down.push_back({});
            for (int j = 0; j < size; j++) {
                left[i].push_back(GREEN);
                front[i].push_back(WHITE);
                right[i].push_back(BLUE);
                back[i].push_back(YELLOW);
                up[i].push_back(ORANGE);
                down[i].push_back(RED);
            }
        }
    }

    void random_situation();

    void fill_from_the_file(const char *name_of_the_file);

    void show(std::string file = "");

    void show_to_concol();

    virtual bool has_all_colors();

    virtual bool check();

    void right_rotation_90();

    void right_rotation_against_90();

    void left_rotation_90();

    void left_rotation_against_90();

    void front_rotation_90();

    void front_rotation_against_90();


    void back_rotation_90();

    void back_rotation_against_90();

    void down_rotation_90();

    void down_rotation_against_90();

    void up_rotation_90();

    void up_rotation_against_90();

    void front_pif_paf();

    void back_pif_paf();

    void right_pif_paf();

    void left_pif_paf();

    void flower();

    void right_cross();

    void first_layer();

    void second();

    bool check_orange_right_cross();

    bool assembly_check();

    void third();

    bool check_upper_edges();

    bool orange_cross_check();

    void first_corner();

    void second_corner();

    void third_corner();

    void fourth_corner();

    void main_solver();

    bool check_solved();

    void check_solved_answer_for_cout();

    void check_answer_for_cout();

    void call_coloring();

    void coloring(vector<vector<colors>> &side, int k);

    void square_mini(palette tmp, x_y_z a);

    void square(float x, float y, float z, float rotate, vector<palette> tmp);

    void display_f();

    void specialKeys_f(int key, int x, int y);

    void normalKeys_f(unsigned char key, int x, int y);
};
