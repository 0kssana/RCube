#include <iostream>
#include "glcube.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cstring>

#define CUBE_SIZE 13
#define TIMER 3
// координаты источника света
GLfloat lightPos[] = { 0, 100, 200, 0 };
// проекции угла поворота на оси
int xRot = 24, yRot = -34, zRot = 0;
// отдаление
double translateZ = -35.0;
// кубик-рубик
GlCube cube(CUBE_SIZE);
// флаг того, крутится куб сам, или нет (будет переключаться правой кнопкой мыши)
int timerOn = 0;
bool solveB = false;
std::vector<std::pair<int,int>> seq(0);
std::string fi,fo;

void display()
{
    glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 0, 0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glTranslatef(0, 0, translateZ);
    glRotatef(xRot, 1, 0, 0);
    glRotatef(yRot, 0, 1, 0);
    glTranslatef(CUBE_SIZE / -2.0, CUBE_SIZE / -2.0, CUBE_SIZE / -2.0);
    cube.drawCube();
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLfloat fAspect = (GLfloat)w / (GLfloat)h;
    gluPerspective(60, fAspect, 1, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void init()
{
    glClearColor(0.1, 0.7, 0.6, 1.5);
    // инициализируем случайные числа
    srand(time(0));

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
    glEnable(GL_LIGHTING);
}


int main(int argc, char** argv)
{
    for (int i = 1; i < argc && i < 6; i+=2) {
        if (argc-i>=1 && strcmp(argv[i], "-i") == 0) {
            fi = argv[i+1];
        }
        if (argc-i>=1 && strcmp(argv[i], "-o") == 0) {
            fo = argv[i+1];
        }
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 700);
    glutInitWindowPosition(1, 1);
    glutCreateWindow("Cube");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keys);
    glutMouseFunc(mouse);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}