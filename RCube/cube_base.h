/**
 * \file cube_base.h
 * \brief Заголовочный файл.
 */

#pragma once
#include <vector>
#include <stdexcept>
#include <fstream>

/**
 * \enum Color
 * \brief Цвета кубика Рубика.
 */
enum Color {
    white = 0,    ///< Белый цвет
    red = 1,      ///< Красный цвет
    blue = 2,     ///< Синий цвет
    green = 3,    ///< Зеленый цвет
    yellow = 4,   ///< Желтый цвет
    orange = 5,   ///< Оранжевый цвет
    undef = 6,    ///< Неопределенный цвет
};

/**
 * \enum position
 * \brief Позиции сторон кубика Рубика.
 */
enum position {
    front,  ///< Передняя сторона
    back,   ///< Задняя сторона
    up,     ///< Верхняя сторона
    down,   ///< Нижняя сторона
    left,   ///< Левая сторона
    right,  ///< Правая сторона
};

extern std::vector<std::vector<int>> d_state;

/**
 * \struct cubie
 * \brief Базовая структура для представления маленького кубика в составе большого кубика Рубика.
 */
struct cubie {
    /**
     * \brief Устанавливает цвет на указанной позиции.
     * \param[in] pos Позиция на кубике.
     * \param[in] color Цвет.
     */
    virtual void setColor(position pos, int color) = 0;

    /**
     * \brief Поворот на плоскости X0Y.
     */
    virtual void rotateZ() = 0;

    /**
     * \brief Поворот на плоскости X0Z.
     */
    virtual void rotateY() = 0;

    /**
     * \brief Поворот на плоскости Y0Z.
     */
    virtual void rotateX() = 0;
};

/**
 * \class Cube
 * \brief Базовый абстрактный класс для кубика Рубика.
 */
class Cube {
private:

public:
    /**
     * \brief Устанавливает состояние кубика.
     * \param[in] state Новое состояние кубика.
     */
    virtual void setCube(const std::vector<std::vector<int>>& state) = 0;

    /**
     * \brief Сохраняет текущее состояние кубика.
     */
    virtual void saveCube() = 0;

    /**
     * \brief Загружает состояние кубика из файла.
     * \param[in] in Входной файловый поток.
     */
    virtual void fsetCube(std::ifstream& in) = 0;

    /**
     * \brief Сохраняет текущее состояние кубика в файл.
     * \param[in] out Выходной файловый поток.
     */
    virtual void fsaveCube(std::ofstream& out) = 0;

    /**
     * \brief Поворачивает сторону кубика на 90 градусов.
     * \param[in] side Сторона для поворота.
     * \param[in] direction Направление поворота.
     */
    virtual void rotate90(int side, int direction) = 0;
};
