#include "cube.h"
Cube my_cube;

void specialKeys(int key, int x, int y){
    my_cube.specialKeys_f(key, x, y);
}

void normalKeys(unsigned char key, int x, int y){
    my_cube.normalKeys_f(key, x, y);
}

void display(){
    my_cube.display_f();
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
}

int main(int argc, char* argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800,800);
    glutCreateWindow("Cube");
    init();
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.2,0.2,0.2,1);
    glutDisplayFunc(display);
    glutKeyboardFunc(normalKeys);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;

}
