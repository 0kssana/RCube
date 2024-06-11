/**
 * \file glcube.h
 * \brief Заголовочный файл для классов Glcubie и GlCube.
 */
#ifndef RCUBE_GLCUBE_H
#define RCUBE_GLCUBE_H

#include "cube_base.h"

#include <GL/freeglut.h>
#include <GLFW/glfw3.h>
#include <GL/glut.h>



/**
 * \class Glcubie
 * \brief Класс для представления одного маленького кубика в кубике Рубика.
 * Наследуется от cubie.
 */
struct Glcubie : public cubie {
    int color[6]; ///< Цвета сторон маленького кубика.
    float size; ///< Размер маленького кубика.

    /**
     * \brief Конструктор по умолчанию.
     */
    Glcubie();

    /**
     * \brief Устанавливает цвет на указанной позиции.
     * \param[in] newPos Позиция на кубике.
     * \param[in] newColor Новый цвет.
     */
    void setColor(position newPos, int newColor) override;

    /**
     * \brief Поворот кубика на плоскости X0Y.
     */
    void rotateZ() override;

    /**
     * \brief Поворот кубика на плоскости X0Z.
     */
    void rotateY() override;

    /**
     * \brief Поворот кубика на плоскости Y0Z.
     */
    void rotateX() override;

    /**
     * \brief Устанавливает цвет для указанной позиции.
     * \param[in] pos Позиция на кубике.
     */
    void setColor(position pos);

    /**
     * \brief Отрисовывает маленький кубик.
     * \param[in] type Тип примитива OpenGL для отрисовки.
     */
    void drawCubie(GLenum type);

    /**
     * \brief Отрисовывает маленький кубик с заданными координатами.
     * \param[in] x Координата X.
     * \param[in] y Координата Y.
     * \param[in] z Координата Z.
     */
    void drawCubie(double x, double y, double z);
};


/**
 * \class GlCube
 * \brief Класс для представления кубика Рубика.
 * Наследуется от Cube.
 */
class GlCube : public Cube {
private:
    float size; ///< Размер кубика.
    std::vector<std::vector<std::vector<Glcubie>>> cube; ///< 3D массив маленьких кубиков.
    bool solved; ///< Флаг решенного состояния.
    bool correct; ///< Флаг правильности состояния.

    // Helper storage
    std::vector<std::vector<Glcubie>> slice; ///< Временное хранилище для поворотов.
    std::vector<std::vector<int>> f_format; ///< Формат кубика.

    // Drawing storage
    bool ok[4][4][4]; ///< Массив для отслеживания корректности отрисовки.
    std::vector<int> rotate; ///< Векторы поворотов.

public:
    int clock; ///< Часы для анимации.
    int current; ///< Текущий поворот.
    int i = 0; ///< Счетчик операций.

    /**
     * \brief Конструктор куба.
     * \param[in] s Размер куба.
     */
    explicit GlCube(float s);

    // File work

    /**
     * \brief Устанавливает состояние кубика.
     * \param[in] newCube Новое состояние кубика.
     * \throw std::length_error Если размер нового состояния некорректен.
     */
    void setCube(const std::vector<std::vector<int>>& newCube) override;

    /**
     * \brief Сохраняет текущее состояние кубика.
     */
    void saveCube() override;

    /**
     * \brief Устанавливает состояние кубика из файла.
     * \param[in] fin Входной файловый поток.
     * \throw std::runtime_error Если формат файла некорректен.
     */
    void fsetCube(std::ifstream& fin) override;

    /**
     * \brief Сохраняет состояние кубика в файл.
     * \param[in] fo Выходной файловый поток.
     */
    void fsaveCube(std::ofstream& fo) override;

    /**
     * \brief Возвращает текущее сохраненное состояние кубика.
     * \return Ссылка на вектор состояния.
     */
    std::vector<std::vector<int>>& saved();

    // Rotation

    /**
     * \brief Поворачивает грань кубика на 90 градусов.
     * \param[in] pos Позиция грани.
     * \param[in] sign Знак направления поворота.
     * \throw std::runtime_error Если значение знака некорректно.
     */
    void rotate90(int pos, int sign) override;

    /**
     * \brief Поворачивает грань кубика на заданный угол.
     * \param[in] idx Индекс грани.
     * \param[in] angle Угол поворота.
     * \param[in] angle90 Флаг, указывающий, что поворот должен быть на 90 градусов.
     */
    void Rotate(int idx, int angle, int angle90);

    /**
     * \brief Изменяет направление вращения.
     */
    void changeDir();

    /**
     * \brief Поворачивает кубик по последовательности из файла.
     * \param[in] fin Входной файловый поток.
     */
    void rotate_seq(std::ifstream& fin);

    // Drawing

    /**
     * \brief Отрисовывает кубик Рубика.
     */
    void drawCube();

    /**
     * \brief Сбрасывает состояние кубика.
     */
    void reset();
};

#endif // RCUBE_GLCUBE_H
