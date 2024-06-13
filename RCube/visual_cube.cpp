/**
 * \file visual_cube.cpp
 * \brief Реализация методов класса Cube для отрисовки и управления кубом Рубика с использованием OpenGL и GLUT.
 */

#include "cube.h"
#include <GL/glut.h>

/**
 * \brief Вызывает функцию закрашивания для всех сторон куба.
 */
void Cube::call_coloring() {
    coloring(left, 2); ///< Закрашивает левую сторону.
    coloring(right, 3); ///< Закрашивает правую сторону.
    coloring(front, 0); ///< Закрашивает переднюю сторону.
    coloring(back, 1); ///< Закрашивает заднюю сторону.
    coloring(up, 4); ///< Закрашивает верхнюю сторону.
    coloring(down, 5); ///< Закрашивает нижнюю сторону.
}

/**
 * \brief Закрашивает одну из сторон куба.
 * \param side Сторона куба, представленная в виде вектора цветов.
 * \param k Индекс стороны куба.
 */
void Cube::coloring(vector<vector<colors>> &side, int k) {
    vector<palette> tmp;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (side[i][j] == RED) {
                tmp.push_back({1, 0, 0}); ///< Красный цвет.
            } else if (side[i][j] == GREEN) {
                tmp.push_back({0, 1, 0}); ///< Зеленый цвет.
            } else if (side[i][j] == BLUE) {
                tmp.push_back({0, 0, 1}); ///< Синий цвет.
            } else if (side[i][j] == WHITE) {
                tmp.push_back({1, 1, 1}); ///< Белый цвет.
            } else if (side[i][j] == YELLOW) {
                tmp.push_back({1, 1, 0}); ///< Желтый цвет.
            } else if (side[i][j] == ORANGE) {
                tmp.push_back({1, 0.45, 0}); ///< Оранжевый цвет.
            }
        }
    }
    if (k == 0)
        square(0, 0, 0, 0, tmp); ///< front
    else if (k == 1)
        square(0, 1, 0, 180, tmp); ///< back
    else if (k == 2)
        square(0, 1, 0, 90, tmp); ///< left
    else if (k == 3)
        square(0, 1, 0, -90, tmp); ///< right
    else if (k == 4)
        square(1, 0, 0, 90, tmp); ///< up
    else if (k == 5)
        square(1, 0, 0, -90, tmp); ///< down
}

/**
 * \brief Отрисовывает маленький квадрат куба.
 * \param tmp Цвет квадрата.
 * \param a Координаты квадрата.
 */
void Cube::square_mini(palette tmp, x_y_z a) {
    glPushMatrix();
    glTranslatef(a.x, a.y, a.z); ///< Перемещает квадрат в нужное положение.
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(tmp.RED, tmp.GREEN, tmp.BLUE); ///< Устанавливает цвет квадрата.
    glVertex3f(0, 0, 0);
    glVertex3f(-1, 0, 0);
    glVertex3f(-1, 1, 0);
    glVertex3f(0, 1, 0);
    glEnd();
    glPopMatrix();

}

/**
 * \brief Отрисовывает одну сторону куба.
 * \param x Координата x.
 * \param y Координата y.
 * \param z Координата z.
 * \param rotate Угол поворота.
 * \param tmp Вектор цветов для каждой клетки стороны.
 */
void Cube::square(float x, float y, float z, float rotate, vector<palette> tmp) {
    glPushMatrix();
    glRotatef(rotate, x, y, z); ///< Поворачивает сторону.
    glPushMatrix();
    glTranslatef(1.7, -1.7, -0.1);
    glScalef(3.4, 3.4, 1); ///< Увеличивает сторону.
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0, 0, 0); ///< Устанавливает черный цвет для заднего фона.
    glVertex3f(0, 0, -1.6);
    glVertex3f(-1, 0, -1.6);
    glVertex3f(-1, 1, -1.6);
    glVertex3f(0, 1, -1.6);
    glEnd();
    glPopMatrix();
    square_mini(tmp[0], {-0.6, 0.6, -1.71});
    square_mini(tmp[1], {0.5, 0.6, -1.71});
    square_mini(tmp[2], {1.6, 0.6, -1.71});
    square_mini(tmp[3], {-0.6, -0.5, -1.71});
    square_mini(tmp[4], {0.5, -0.5, -1.71});
    square_mini(tmp[5], {1.6, -0.5, -1.71});
    square_mini(tmp[6], {-0.6, -1.6, -1.71});
    square_mini(tmp[7], {0.5, -1.6, -1.71});
    square_mini(tmp[8], {1.6, -1.6, -1.71});
    glPopMatrix();
}

/**
 * \brief Функция отображения куба.
 */
void Cube::display_f() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glRotatef(rotate_x, 1, 0, 0);
    glRotatef(rotate_y, 0, 1, 0);
    glPushMatrix();
    glScalef(0.3, 0.3, 0.3); ///< Масштабирует куб.
    call_coloring();
    glutPostRedisplay();
    glPopMatrix();
    glFlush(); ///< Выполняет все команды OpenGL.
    glutSwapBuffers(); ///< Меняет местами буферы.
}

/**
 * \brief Обрабатывает нажатия специальных клавиш.
 * \param key Код клавиши.
 * \param x Координата x курсора мыши.
 * \param y Координата y курсора мыши.
 */
void Cube::specialKeys_f(int key, int x, int y) {
    if (key == GLUT_KEY_RIGHT)
        rotate_y -= 5; ///< y против часовой стрелки.

    else if (key == GLUT_KEY_LEFT)
        rotate_y += 5; ///< y по часовой стрелки.

    else if (key == GLUT_KEY_UP)
        rotate_x += 5; ///< x по часовой стрелки.

    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 5; ///< x против часовой стрелки.
    glutPostRedisplay();
}

/**
 * \brief Обрабатывает нажатия обычных клавиш.
 * \param key Код клавиши.
 * \param x Координата x курсора мыши.
 * \param y Координата y курсора мыши.
 */
void Cube::normalKeys_f(unsigned char key, int x, int y) {
    if (key == '1')
        right_rotation_90();
    else if (key == '2')
        right_rotation_against_90();
    else if (key == '3')
        left_rotation_90();
    else if (key == '4')
        left_rotation_against_90();

    else if (key == '5')
        front_rotation_90();
    else if (key == '6')
        front_rotation_against_90();
    else if (key == '7')
        back_rotation_90();
    else if (key == '8')
        back_rotation_against_90();

    else if (key == '9')
        down_rotation_90();
    else if (key == '0')
        down_rotation_against_90();
    else if (key == '-')
        up_rotation_90();
    else if (key == '=')
        up_rotation_against_90();
    else if (key == 'r') {
        random_situation();
    } else if (key == 's') {
        Cube::main_solver();
    } else if (key == 'c') {
        check_solved_answer_for_cout();
    } else if (key == 'n') {
        show_to_concol();
    } else if (key == 'o') {
        show("Cubeout.txt");
    } else if (key == 'h') {
        check_answer_for_cout();
    } else if (key == 'i') {
        Cube::fill_from_the_file("cubein.txt");
    }
}
