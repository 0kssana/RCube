/**
 * \file main.cpp
 * \brief Главный файл программы. Точка входа для приложения отображения куба. Обрабатывает инициализацию и ввод для класса Cube.
 */
#include "cube.h"
Cube my_cube;

/**
 * \brief Обрабатывает специальные клавиши.
 * \param key Код клавиши.
 * \param x Координата x курсора мыши.
 * \param y Координата y курсора мыши.
 */
void specialKeys(int key, int x, int y){
    my_cube.specialKeys_f(key, x, y);
}

/**
 * \brief Обрабатывает обычные клавиши.
 * \param key Код клавиши.
 * \param x Координата x курсора мыши.
 * \param y Координата y курсора мыши.
 */
void normalKeys(unsigned char key, int x, int y){
    my_cube.normalKeys_f(key, x, y);
}

/**
 * \brief Функция отображения.
 */
void display(){
    my_cube.display_f();
}

/**
 * \brief Инициализация параметров OpenGL.
 */
void init()
{
    glClearColor(0.2,0.2,0.2,1);
    // освещение
    float mat_specular[] = { 0.3, 0.3, 0.3, 0 };
    float diffuseLight[] = { 0.2, 0.2, 0.2, 1 };
    float ambientLight[] = { 0.9, 0.9, 0.9, 1.0 };
    glShadeModel(GL_SMOOTH);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMateriali(GL_FRONT, GL_SHININESS, 128);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT);
    glEnable(GL_DEPTH_TEST);
}

/**
 * \brief Главная функция. Точка входа в программу.
 * \param argc Количество аргументов командной строки.
 * \param argv Массив аргументов командной строки.
 * \return Код завершения программы.
 */
int main(int argc, char* argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800,800);
    glutCreateWindow("Cube");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(normalKeys);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;

}