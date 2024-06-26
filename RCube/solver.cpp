/**
 * \file solver.cpp
 * \brief Реализация решений.
 */
#include "cube.h"

/**
 * \brief Выполняет комбинацию движений "пиф-паф" на передней грани кубика.
 * 
 * Метод выполняет следующую последовательность действий:
 * 1. Поворот передней грани на 90 градусов по часовой стрелке.
 * 2. Поворот верхней грани на 90 градусов по часовой стрелке.
 * 3. Поворот передней грани на 90 градусов против часовой стрелки.
 * 4. Поворот верхней грани на 90 градусов против часовой стрелки.
 */
void Cube::front_pif_paf() {
    front_rotation_90();
    up_rotation_90();
    front_rotation_against_90();
    up_rotation_against_90();
}

/**
 * \brief Выполняет комбинацию движений "пиф-паф" на задней грани кубика.
 */
void Cube::back_pif_paf() {
    back_rotation_90();
    up_rotation_90();
    back_rotation_against_90();
    up_rotation_against_90();
}

/**
 * \brief Выполняет комбинацию движений "пиф-паф" на правой грани кубика.
 */
void Cube::right_pif_paf() {
    right_rotation_90();
    up_rotation_90();
    right_rotation_against_90();
    up_rotation_against_90();
}

/**
 * \brief Выполняет комбинацию движений "пиф-паф" на левой грани кубика.
 */
void Cube::left_pif_paf() {
    left_rotation_90();
    up_rotation_90();
    left_rotation_against_90();
    up_rotation_against_90();
}

/**
 * \brief Собирает "цветок" на верхней грани кубика Рубика.
 * 
 * Метод перемещает красные элементы с других граней на центральные позиции верхней грани.
 * Алгоритм продолжает выполняться до тех пор, пока все центральные позиции верхней грани не будут красными.
 */
void Cube::flower() {
    while (up[0][1] != RED or up[1][0] != RED or up[1][2] != RED or up[2][1] != RED) {

        if (front[1][2] == RED and up[1][2] != RED) {
            right_rotation_90();
        } else if (front[1][2] == RED) {
            while (up[1][2] == RED) {
                up_rotation_90();
            }
            right_rotation_90();
        }

        if (front[1][0] == RED and up[1][0] != RED) {
            left_rotation_against_90();
        } else if (front[1][0] == RED) {
            while (up[1][0] == RED) {
                up_rotation_90();
            }
            left_rotation_against_90();
        }

        if (down[1][0] == RED and up[1][0] != RED) {
            for (int i = 0; i < 2; i++) left_rotation_against_90();
        } else if (down[1][0] == RED) {
            while (up[1][0] == RED) {
                up_rotation_90();
            }
            for (int i = 0; i < 2; i++) left_rotation_against_90();
        }

        if (down[1][2] == RED and up[1][2] != RED) {
            for (int i = 0; i < 2; i++) right_rotation_90();
        } else if (down[1][2] == RED) {
            while (up[1][2] == RED) {
                up_rotation_90();
            }
            for (int i = 0; i < 2; i++) right_rotation_90();
        }

        if (left[1][0] == RED and up[0][1] != RED) {
            back_rotation_against_90();
        } else if (left[1][0] == RED) {
            while (up[0][1] == RED) {
                up_rotation_90();
            }
            back_rotation_against_90();
        }

        if (left[1][2] == RED and up[2][1] != RED) {
            front_rotation_90();
        } else if (left[1][2] == RED) {
            while (up[2][1] == RED) {
                up_rotation_90();
            }
            front_rotation_90();
        }

        if (right[1][0] == RED and up[2][1] != RED) {
            front_rotation_against_90();
        } else if (right[1][0] == RED) {
            while (up[2][1] == RED) {
                up_rotation_90();
            }
            front_rotation_against_90();
        }

        if (right[1][2] == RED and up[0][1] != RED) {
            back_rotation_90();
        } else if (right[1][2] == RED) {
            while (up[0][1] == RED) {
                up_rotation_90();
            }
            back_rotation_90();
        }

        if (back[1][0] == RED and up[1][2] != RED) {
            right_rotation_against_90();
        } else if (back[1][0] == RED) {
            while (up[1][2] == RED) {
                up_rotation_90();
            }
            right_rotation_against_90();
        }

        if (back[1][2] == RED and up[1][0] != RED) {
            left_rotation_90();
        } else if (back[1][2] == RED) {
            while (up[1][0] == RED) {
                up_rotation_90();
            }
            left_rotation_90();
        }

        if (front[0][1] == RED and up[1][2] != RED) {
            for (int i = 0; i < 2; i++) front_rotation_90();
        } else if (front[0][1] == RED) {
            while (up[1][2] == RED) {
                up_rotation_90();
            }
            front_rotation_90();
            right_rotation_90();
        }

        if (front[2][1] == RED and up[1][2] != RED) {
            front_rotation_against_90();
            right_rotation_90();
        } else if (front[2][1] == RED) {
            while (up[1][2] == RED) {
                up_rotation_90();
            }
            front_rotation_against_90();
            right_rotation_90();
        }

        if (left[0][1] == RED and up[2][1] != RED) {
            left_rotation_90();
            front_rotation_90();
        } else if (left[0][1] == RED) {
            while (up[2][1] == RED) {
                up_rotation_90();
            }
            left_rotation_90();
            front_rotation_90();
        }

        if (left[2][1] == RED and up[0][1] != RED) {
            left_rotation_90();
            back_rotation_against_90();
        } else if (left[2][1] == RED) {
            while (up[0][1] == RED) {
                up_rotation_90();
            }
            left_rotation_90();
            back_rotation_against_90();
        }

        if (right[0][1] == RED and up[0][1] != RED) {
            right_rotation_90();
            back_rotation_90();
        } else if (right[0][1] == RED) {
            while (up[0][1] == RED) {
                up_rotation_90();
            }
            right_rotation_90();
            back_rotation_90();
        }

        if (right[2][1] == RED and up[1][2] != RED) {
            right_rotation_90();
        } else if (right[2][1] == RED) {
            while (up[1][2] == RED) {
                up_rotation_90();
            }
            right_rotation_90();
        }

        if (back[0][1] == RED and up[0][1] != RED) {
            back_rotation_90();
        } else if (back[0][1] == RED) {
            while (up[0][1] == RED) {
                up_rotation_90();
            }
            back_rotation_90();
        }

        if (back[2][1] == RED and up[0][1] != RED) {
            back_rotation_90();
        } else if (back[2][1] == RED) {
            while (up[0][1] == RED) {
                up_rotation_90();
            }
            back_rotation_90();
        }

        if (down[0][1] == RED and up[2][1] != RED) {
            for (int i = 0; i < 2; i++) front_rotation_90();
        } else if (down[0][1] == RED) {
            while (up[2][1] == RED) {
                up_rotation_90();
            }
            for (int i = 0; i < 2; i++) front_rotation_90();
        }

        if (down[2][1] == RED and up[0][1] != RED) {
            for (int i = 0; i < 2; i++) back_rotation_90();
        } else if (down[2][1] == RED) {
            while (up[0][1] == RED) {
                up_rotation_90();
            }
            for (int i = 0; i < 2; i++) back_rotation_90();
        }

    }
}

/**
 * \brief Функция создания правильного креста на нижней грани.
 *
 * Метод right_cross создает правильный крест красного цвета на нижней грани кубика Рубика.
 * В каждом шаге проверяется наличие нужных цветов на определенных позициях кубика.
 * Если цвета совпадают, выполняются необходимые повороты для создания креста.
 */
void Cube::right_cross() {
    // Делаем центр и 01 одного цвета
    if (front[0][1] != WHITE or up[2][1] != RED) {
        while (front[0][1] != WHITE or up[2][1] != RED) {
            up_rotation_90();
        }
        // Опускаем вниз две одинаковые клетки
        for (int i = 0; i < 2; i++) front_rotation_90();

    }  // Если уже одного цвета просто опускаем вниз
    else if (up[2][1] == RED or front[0][1] == WHITE) {
        for (int i = 0; i < 2; i++) front_rotation_90();
    }

    if (up[1][2] != RED or right[0][1] != BLUE) {
        while (up[1][2] != RED or right[0][1] != BLUE) {
            up_rotation_90();
        }
        for (int i = 0; i < 2; i++) right_rotation_90();
    } else if (up[1][2] == RED or right[0][1] == BLUE) {
        for (int i = 0; i < 2; i++) right_rotation_90();
    }

    if (up[0][1] != RED or back[0][1] != YELLOW) {
        while (up[0][1] != RED or back[0][1] != YELLOW) {
            up_rotation_90();
        }
        for (int i = 0; i < 2; i++) back_rotation_90();
    } else if (up[0][1] == RED or back[0][1] == YELLOW) {
        for (int i = 0; i < 2; i++) back_rotation_90();
    }

    if (up[1][0] != RED or left[0][1] != GREEN) {
        while (up[1][0] != RED or left[0][1] != GREEN) {
            up_rotation_90();
        }
        for (int i = 0; i < 2; i++) left_rotation_90();
    } else if (up[1][0] == RED or left[0][1] == GREEN) {
        for (int i = 0; i < 2; i++) left_rotation_90();
    }
    // Получаем внизу правильный крест красного цвета
}

/**
 * \brief Функция сборки углов для нижнего красного креста.
 *
 * Метод second_corner собирает углы вокруг нижнего красного креста кубика Рубика.
 * Для каждого угла проверяется совпадение цветов и выполняются необходимые вращения,
 * чтобы установить угол на правильное место.
 */
void Cube::second_corner() {
    // Обработка первого угла
    if ((right[0][2] == RED and back[0][0] == BLUE and up[0][2] == WHITE) or
        (right[0][2] == RED and back[0][0] == WHITE and up[0][2] == BLUE)
        or (right[0][2] == WHITE and back[0][0] == RED and up[0][2] == BLUE) or
        (right[0][2] == WHITE and back[0][0] == BLUE and up[0][2] == RED)
        or (right[0][2] == BLUE and back[0][0] == RED and up[0][2] == WHITE) or
        (right[0][2] == BLUE and back[0][0] == WHITE and up[0][2] == RED)) {
        up_rotation_90();
        while (front[2][2] != WHITE or right[2][0] != BLUE or down[0][2] != RED) {
            right_pif_paf();
        }
    }

    // Обработка второго угла
    if ((right[0][2] == WHITE and back[0][0] == GREEN and up[0][2] == RED) or
        (right[0][2] == WHITE and back[0][0] == RED and up[0][2] == GREEN)
        or (right[0][2] == RED and back[0][0] == WHITE and up[0][2] == GREEN) or
        (right[0][2] == RED and back[0][0] == GREEN and up[0][2] == WHITE)
        or (right[0][2] == GREEN and back[0][0] == RED and up[0][2] == WHITE) or
        (right[0][2] == GREEN and back[0][0] == WHITE and up[0][2] == RED)) {
        for (int i = 0; i < 2; i++) up_rotation_90();
        while (front[2][0] != WHITE or left[2][2] != GREEN or down[0][0] != RED) {
            front_pif_paf();
        }
    }

    // Обработка третьего угла
    if ((right[0][2] == BLUE and back[0][0] == YELLOW and up[0][2] == RED) or
        (right[0][2] == BLUE and back[0][0] == RED and up[0][2] == YELLOW)
        or (right[0][2] == RED and back[0][0] == BLUE and up[0][2] == YELLOW) or
        (right[0][2] == RED and back[0][0] == YELLOW and up[0][2] == BLUE)
        or (right[0][2] == YELLOW and back[0][0] == BLUE and up[0][2] == RED) or
        (right[0][2] == YELLOW and back[0][0] == RED and up[0][2] == BLUE)) {
        while (back[2][0] != YELLOW or right[2][2] != BLUE or down[2][2] != RED) {
            back_pif_paf();
        }
    }

    // Обработка четвертого угла
    if ((right[0][2] == GREEN and back[0][0] == RED and up[0][2] == YELLOW) or
        (right[0][2] == YELLOW and back[0][0] == RED and up[0][2] == GREEN) or
        (right[0][2] == RED and back[0][0] == GREEN and up[0][2] == YELLOW) or
        (right[0][2] == RED and back[0][0] == YELLOW and up[0][2] == GREEN) or
        (right[0][2] == GREEN and back[0][0] == YELLOW and up[0][2] == RED) or
        (right[0][2] == YELLOW and back[0][0] == GREEN and up[0][2] == RED)) {
        up_rotation_against_90();
        while (back[2][2] != YELLOW or left[2][0] != GREEN or down[2][0] != RED) {
            left_pif_paf();
        }
    }
}

/**
 * \brief Функция предназначена для решения первого углового элемента кубика Рубика, используя алгоритмы на основе цвета и позиции.
 */
void Cube::first_corner() {
    // Первый угол: RED-BLUE-WHITE или аналогичные комбинации
    if ((front[0][2] == RED and right[0][0] == BLUE and up[2][2] == WHITE) or
        (front[0][2] == RED and right[0][0] == WHITE and up[2][2] == BLUE)
        or (front[0][2] == WHITE and right[0][0] == RED and up[2][2] == BLUE) or
        (front[0][2] == WHITE and right[0][0] == BLUE and up[2][2] == RED)
        or (front[0][2] == BLUE and right[0][0] == RED and up[2][2] == WHITE) or
        (front[0][2] == BLUE and right[0][0] == WHITE and up[2][2] == RED)) {
        while (front[2][2] != WHITE or right[2][0] != BLUE or down[0][2] != RED) {
            right_pif_paf(); // Выполняем алгоритм "правый пиф-паф" до достижения нужного состояния
        }
    }

    // Второй угол: WHITE-GREEN-RED или аналогичные комбинации
    if ((front[0][2] == WHITE and right[0][0] == GREEN and up[2][2] == RED) or
        (front[0][2] == WHITE and right[0][0] == RED and up[2][2] == GREEN)
        or (front[0][2] == RED and right[0][0] == WHITE and up[2][2] == GREEN) or
        (front[0][2] == RED and right[0][0] == GREEN and up[2][2] == WHITE)
        or (front[0][2] == GREEN and right[0][0] == RED and up[2][2] == WHITE) or
        (front[0][2] == GREEN and right[0][0] == WHITE and up[2][2] == RED)) {
        up_rotation_90();
        while (front[2][0] != WHITE or left[2][2] != GREEN or down[0][0] != RED) {
            front_pif_paf();
        }
    }

    // Третий угол: BLUE-YELLOW-RED или аналогичные комбинации
    if ((front[0][2] == BLUE and right[0][0] == YELLOW and up[2][2] == RED) or
        (front[0][2] == BLUE and right[0][0] == RED and up[2][2] == YELLOW)
        or (front[0][2] == RED and right[0][0] == BLUE and up[2][2] == YELLOW) or
        (front[0][2] == RED and right[0][0] == YELLOW and up[2][2] == BLUE)
        or (front[0][2] == YELLOW and right[0][0] == BLUE and up[2][2] == RED) or
        (front[0][2] == YELLOW and right[0][0] == RED and up[2][2] == BLUE)) {
        up_rotation_against_90();
        while (back[2][0] != YELLOW or right[2][2] != BLUE or down[2][2] != RED) {
            back_pif_paf();
        }
    }

    // Четвертый угол: RED-GREEN-YELLOW или аналогичные комбинации
    if ((front[0][2] == RED and right[0][0] == GREEN and up[2][2] == YELLOW) or
        (front[0][2] == RED and right[0][0] == YELLOW and up[2][2] == GREEN)
        or (front[0][2] == YELLOW and right[0][0] == RED and up[2][2] == GREEN) or
        (front[0][2] == YELLOW and right[0][0] == GREEN and up[2][2] == RED)
        or (front[0][2] == GREEN and right[0][0] == YELLOW and up[2][2] == RED) or
        (front[0][2] == GREEN and right[0][0] == RED and up[2][2] == YELLOW)) {
        for (int i = 0; i < 2; i++) up_rotation_90();
        while (back[2][2] != YELLOW or left[2][0] != GREEN or down[2][0] != RED) {
            left_pif_paf();
        }
    }
}

/**
 * \brief Функция предназначена для решения первого углового элемента кубика Рубика, используя алгоритмы на основе цвета и позиции.
 */
void Cube::third_corner() {

    if ((back[0][2] == RED and left[0][0] == BLUE and up[0][0] == WHITE) or
        (back[0][2] == RED and left[0][0] == WHITE and up[0][0] == BLUE)
        or (back[0][2] == WHITE and left[0][0] == RED and up[0][0] == BLUE) or
        (back[0][2] == WHITE and left[0][0] == BLUE and up[0][0] == RED)
        or (back[0][2] == BLUE and left[0][0] == RED and up[0][0] == WHITE) or
        (back[0][2] == BLUE and left[0][0] == WHITE and up[0][0] == RED)) {
        for (int i = 0; i < 2; i++) up_rotation_against_90();
        while (front[2][2] != WHITE or right[2][0] != BLUE or down[0][2] != RED) {
            right_pif_paf();
        }
    }

    if ((back[0][2] == WHITE and left[0][0] == GREEN and up[0][0] == RED) or
        (back[0][2] == WHITE and left[0][0] == RED and up[0][0] == GREEN)
        or (back[0][2] == RED and left[0][0] == WHITE and up[0][0] == GREEN) or
        (back[0][2] == RED and left[0][0] == GREEN and up[0][0] == WHITE)
        or (back[0][2] == GREEN and left[0][0] == RED and up[0][0] == WHITE) or
        (back[0][2] == GREEN and left[0][0] == WHITE and up[0][0] == RED)) {
        up_rotation_against_90();
        while (front[2][0] != WHITE or left[2][2] != GREEN or down[0][0] != RED) {
            front_pif_paf();
        }
    }

    if ((back[0][2] == BLUE and left[0][0] == YELLOW and up[0][0] == RED) or
        (back[0][2] == BLUE and left[0][0] == RED and up[0][0] == YELLOW)
        or (back[0][2] == RED and left[0][0] == BLUE and up[0][0] == YELLOW) or
        (back[0][2] == RED and left[0][0] == YELLOW and up[0][0] == BLUE)
        or (back[0][2] == YELLOW and left[0][0] == BLUE and up[0][0] == RED) or
        (back[0][2] == YELLOW and left[0][0] == RED and up[0][0] == BLUE)) {
        up_rotation_90();
        while (back[2][0] != YELLOW or right[2][2] != BLUE or down[2][2] != RED) {
            back_pif_paf();
        }
    }

    if ((back[0][2] == RED and left[0][0] == GREEN and up[0][0] == YELLOW) or
        (back[0][2] == RED and left[0][0] == YELLOW and up[0][0] == GREEN)
        or (back[0][2] == YELLOW and left[0][0] == RED and up[0][0] == GREEN) or
        (back[0][2] == YELLOW and left[0][0] == GREEN and up[0][0] == RED)
        or (back[0][2] == GREEN and left[0][0] == YELLOW and up[0][0] == RED) or
        (back[0][2] == GREEN and left[0][0] == RED and up[0][0] == YELLOW)) {
        while (back[2][2] != YELLOW or left[2][0] != GREEN or down[2][0] != RED) {
            left_pif_paf();
        }
    }
}

/**
 * \brief Функция предназначена для решения первого углового элемента кубика Рубика, используя алгоритмы на основе цвета и позиции.
 */
void Cube::fourth_corner() {

    if ((left[0][2] == RED and front[0][0] == BLUE and up[2][0] == WHITE) or
        (left[0][2] == RED and front[0][0] == WHITE and up[2][0] == BLUE)
        or (left[0][2] == WHITE and front[0][0] == RED and up[2][0] == BLUE) or
        (left[0][2] == WHITE and front[0][0] == BLUE and up[2][0] == RED)
        or (left[0][2] == BLUE and front[0][0] == RED and up[2][0] == WHITE) or
        (left[0][2] == BLUE and front[0][0] == WHITE and up[2][0] == RED)) {
        up_rotation_against_90();
        while (front[2][2] != WHITE or right[2][0] != BLUE or down[0][2] != RED) {
            right_pif_paf();
        }
    }

    if ((left[0][2] == WHITE and front[0][0] == GREEN and up[2][0] == RED) or
        (left[0][2] == WHITE and front[0][0] == RED and up[2][0] == GREEN)
        or (left[0][2] == RED and front[0][0] == WHITE and up[2][0] == GREEN) or
        (left[0][2] == RED and front[0][0] == GREEN and up[2][0] == WHITE)
        or (left[0][2] == GREEN and front[0][0] == RED and up[2][0] == WHITE) or
        (left[0][2] == GREEN and front[0][0] == WHITE and up[2][0] == RED)) {
        while (front[2][0] != WHITE or left[2][2] != GREEN or down[0][0] != RED) {
            front_pif_paf();
        }
    }

    if ((left[0][2] == BLUE and front[0][0] == YELLOW and up[2][0] == RED) or
        (left[0][2] == BLUE and front[0][0] == RED and up[2][0] == YELLOW)
        or (left[0][2] == RED and front[0][0] == BLUE and up[2][0] == YELLOW) or
        (left[0][2] == RED and front[0][0] == YELLOW and up[2][0] == BLUE)
        or (left[0][2] == YELLOW and front[0][0] == BLUE and up[2][0] == RED) or
        (left[0][2] == YELLOW and front[0][0] == RED and up[2][0] == BLUE)) {
        for (int i = 0; i < 2; i++) up_rotation_90();
        while (back[2][0] != YELLOW or right[2][2] != BLUE or down[2][2] != RED) {
            back_pif_paf();
        }
    }

    if ((left[0][2] == RED and front[0][0] == GREEN and up[2][0] == YELLOW) or
        (left[0][2] == RED and front[0][0] == YELLOW and up[2][0] == GREEN)
        or (left[0][2] == YELLOW and front[0][0] == RED and up[2][0] == GREEN) or
        (left[0][2] == YELLOW and front[0][0] == GREEN and up[2][0] == RED)
        or (left[0][2] == GREEN and front[0][0] == YELLOW and up[2][0] == RED) or
        (left[0][2] == GREEN and front[0][0] == RED and up[2][0] == YELLOW)) {
        up_rotation_90();
        while (back[2][2] != YELLOW or left[2][0] != GREEN or down[2][0] != RED) {
            left_pif_paf();
        }
    }
}

/**
 * \brief Сборка первого слоя кубика Рубика.
 *
 * Метод собирает первый слой кубика Рубика, начиная с угловых элементов. Используется последовательность
 * методов `second_corner()`, `first_corner()`, `third_corner()`, `fourth_corner()` для расстановки угловых элементов
 * на свои места. После этого применяются "пиф-пафы" для установки боковых элементов первого слоя.
 * После выполнения этого метода первый слой кубика Рубика будет собран.
 */
void Cube::first_layer() {
    // Cборка углов
    while ((((front[2][0] != WHITE or right[2][0] != BLUE or back[2][0] != YELLOW or left[2][0] != GREEN)
             or (front[2][1] != WHITE or right[2][1] != BLUE or back[2][1] != YELLOW or left[2][1] != GREEN)
             or (front[2][2] != WHITE or right[2][2] != BLUE or back[2][2] != YELLOW or left[2][2] != GREEN))
            and (down[0][0] != RED or down[0][2] != RED or down[2][0] != RED or down[2][2] != RED))) {

        this->second_corner();
        this->first_corner();
        this->third_corner();
        this->fourth_corner();


        // Пиф-пафы

        if (front[2][2] != WHITE or right[2][0] != BLUE or down[0][2] != RED) {
            if (front[2][2] == RED or right[2][0] == RED or down[0][2] == RED) {
                right_pif_paf();
            }
        }

        if (front[2][0] != WHITE or left[2][2] != GREEN or down[0][0] != RED) {
            if (front[2][0] == RED or left[2][2] == RED or down[0][0] == RED) {
                front_pif_paf();
            }
        }

        if (back[2][0] != YELLOW or right[2][2] != BLUE or down[2][2] != RED) {
            if (back[2][0] == RED or right[2][2] == RED or down[2][2] == RED) {
                back_pif_paf();
            }
        }

        if (back[2][2] != YELLOW or left[2][0] != GREEN or down[2][0] != RED) {
            if (back[2][2] == RED or left[2][0] == RED or down[2][0] == RED) {
                left_pif_paf();
            }
        }
    }
}

/**
 * \brief Сборка второго слоя кубика Рубика.
 *
 * Метод собирает второй слой кубика Рубика, устанавливая элементы второго слоя так, чтобы они соответствовали цветам
 * боковых граней и верхней грани кубика. Используется метод "пиф-паф" для установки элементов на свои места.
 * После выполнения этого метода второй слой кубика Рубика будет собран.
 */
void Cube::second() {
    int p, counter;

    while ((front[1][0] != WHITE or front[1][2] != WHITE or right[1][0] != BLUE or right[1][2] != BLUE
            or back[1][0] != YELLOW or back[1][2] != YELLOW or left[1][0] != GREEN or left[1][2] != GREEN)) {
        counter = 0;
        p = -1;

        while (counter > p) {
            p = counter;

            // Находим на 3 слое белый цвет, чтобы 2 кубика по середине на передней гране были одного цвета (на позиции 01 и 11)
            if (front[0][1] == WHITE or right[0][1] == WHITE or back[0][1] == WHITE or left[0][1] == WHITE) {
                if (front[0][1] != WHITE) {
                    while (front[0][1] != WHITE) {
                        up_rotation_90();
                    }
                }

                if (up[2][1] == BLUE) {
                    counter++;
                    up_rotation_90();
                    right_pif_paf();
                    front_rotation_against_90();
                    up_rotation_against_90();
                    front_rotation_90();
                    up_rotation_90();
                } else if (up[2][1] == GREEN) {
                    counter++;
                    up_rotation_against_90();
                    left_rotation_against_90();
                    up_rotation_against_90();
                    left_rotation_90();
                    up_rotation_90();
                    front_pif_paf();
                }
            }

            // Находим на 3 слое белый синий, чтобы 2 кубика по середине на правой гране были одного цвета (на позиции 01 и 11)
            if (front[0][1] == BLUE or right[0][1] == BLUE or back[0][1] == BLUE or left[0][1] == BLUE) {
                if (right[0][1] != BLUE) {
                    while (right[0][1] != BLUE) {
                        up_rotation_90();
                    }
                }

                // Если на верхней гране цвет соседних цветов, то ставим 2 цвета в нужные позиции с помощью пиф пафов
                if (up[1][2] == YELLOW) {
                    counter++;
                    up_rotation_90();
                    back_pif_paf();
                    right_rotation_against_90();
                    up_rotation_against_90();
                    right_rotation_90();
                    up_rotation_90();
                } else if (up[1][2] == WHITE) {
                    counter++;
                    up_rotation_against_90();
                    front_rotation_against_90();
                    up_rotation_against_90();
                    front_rotation_90();
                    up_rotation_90();
                    right_pif_paf();
                }
            }

            if (front[0][1] == YELLOW or right[0][1] == YELLOW or back[0][1] == YELLOW or left[0][1] == YELLOW) {
                if (back[0][1] != YELLOW) {
                    while (back[0][1] != YELLOW) {
                        up_rotation_90();
                    }
                }

                if (up[0][1] == GREEN) {
                    counter++;
                    up_rotation_90();
                    left_pif_paf();
                    back_rotation_against_90();
                    up_rotation_against_90();
                    back_rotation_90();
                    up_rotation_90();
                } else if (up[0][1] == BLUE) {
                    counter++;
                    up_rotation_against_90();
                    right_rotation_against_90();
                    up_rotation_against_90();
                    right_rotation_90();
                    up_rotation_90();
                    back_pif_paf();
                }
            }

            if (front[0][1] == GREEN or right[0][1] == GREEN or back[0][1] == GREEN or left[0][1] == GREEN) {
                if (left[0][1] != GREEN) {
                    while (left[0][1] != GREEN) {
                        up_rotation_90();
                    }
                }

                if (up[1][0] == WHITE) {
                    counter++;
                    up_rotation_90();
                    front_pif_paf();
                    left_rotation_against_90();
                    up_rotation_against_90();
                    left_rotation_90();
                    up_rotation_90();
                } else if (up[1][0] == YELLOW) {
                    counter++;
                    up_rotation_against_90();
                    back_rotation_against_90();
                    up_rotation_against_90();
                    back_rotation_90();
                    up_rotation_90();
                    left_pif_paf();
                }
            }
        }

        if (front[1][2] != WHITE) {
            right_pif_paf();
            front_rotation_against_90();
            up_rotation_against_90();
            front_rotation_90();
            up_rotation_90();
        }

        if (right[1][2] != BLUE) {
            back_pif_paf();
            right_rotation_against_90();
            up_rotation_against_90();
            right_rotation_90();
            up_rotation_90();
        }

        if (back[1][2] != YELLOW) {
            left_pif_paf();
            back_rotation_against_90();
            up_rotation_against_90();
            back_rotation_90();
            up_rotation_90();
        }

        if (left[1][2] != GREEN) {
            front_pif_paf();
            left_rotation_against_90();
            up_rotation_against_90();
            left_rotation_90();
            up_rotation_90();
        }
        show();
    }

}
// Собраны 2 нижних слоя

/**
 * \brief Проверка полной сборки кубика Рубика.
 *
 * Метод проверяет, все ли грани кубика Рубика полностью собраны. Это означает, что все элементы каждой грани должны
 * быть одного цвета, соответствующего данной грани.
 *
 * \return true, если все грани кубика Рубика полностью собраны, иначе false.
 */
bool Cube::assembly_check() {
    bool flag = true;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (front[i][j] != WHITE or right[i][j] != BLUE or back[i][j] != YELLOW or left[i][j] != GREEN or
                up[i][j] != ORANGE or down[i][j] != RED) {
                flag = false;
            }
        }
    }

    return flag;
}

/**
 * \brief Проверка наличия оранжевого креста на верхней грани.
 *
 * Метод проверяет, что средние элементы верхней грани (крест) имеют оранжевый цвет.
 *
 * \return true, если крест из оранжевых элементов собран на верхней грани, иначе false.
 */
bool Cube::orange_cross_check() {
    bool flag = 1;

    if (up[0][1] != ORANGE or up[1][2] != ORANGE or up[2][1] != ORANGE or up[1][0] != ORANGE) {
        flag = 0;
    }

    return flag;
}

/**
 * \brief Проверка правильного расположения рёбер креста на верхней грани.
 *
 * Метод проверяет, что крест на верхней грани собран правильно, и что цвета рёбер соответствуют соседним граням.
 *
 * \return true, если крест на верхней грани собран правильно и рёбра имеют правильные цвета, иначе false.
 */
bool Cube::check_orange_right_cross() {
    bool flag = 1;

    flag = orange_cross_check();

    if (front[0][1] != WHITE or right[0][1] != BLUE or back[0][1] != YELLOW or left[0][1] != GREEN) {
        flag = 0;
    }

    return flag;
}

/**
 * \brief Проверка правильности расположения углов верхней грани кубика Рубика.
 *
 * Метод проверяет, находятся ли углы верхней грани в правильных позициях относительно соседних граней. 
 * Проверка выполняется для каждого угла верхней грани и его соседних рёбер.
 *
 * \return true, если все углы верхней грани правильно расположены, иначе false.
 */
bool Cube::check_upper_edges() {
    return ((up[2][2] == ORANGE and front[0][2] == WHITE and right[0][0] == BLUE) or
            (up[2][2] == ORANGE and front[0][2] == BLUE and right[0][0] == WHITE) or
            (up[2][2] == WHITE and front[0][2] == ORANGE and right[0][0] == BLUE) or
            (up[2][2] == WHITE and front[0][2] == BLUE and right[0][0] == ORANGE) or
            (up[2][2] == BLUE and front[0][2] == WHITE and right[0][0] == ORANGE) or
            (up[2][2] == BLUE and front[0][2] == ORANGE and right[0][0] == WHITE)) and
           ((front[0][0] == WHITE and left[0][2] == GREEN and up[2][0] == ORANGE) or
            (front[0][0] == WHITE and left[0][2] == ORANGE and up[2][0] == GREEN) or
            (front[0][0] == GREEN and left[0][2] == ORANGE and up[2][0] == WHITE) or
            (front[0][0] == GREEN and left[0][2] == WHITE and up[2][0] == ORANGE) or
            (front[0][0] == ORANGE and left[0][2] == GREEN and up[2][0] == WHITE) or
            (front[0][0] == ORANGE and left[0][2] == WHITE and up[2][0] == GREEN)) and
           ((up[0][2] == ORANGE and right[0][2] == BLUE and back[0][0] == YELLOW) or
            (up[0][2] == ORANGE and right[0][2] == YELLOW and back[0][0] == BLUE) or
            (up[0][2] == BLUE and right[0][2] == ORANGE and back[0][0] == YELLOW) or
            (up[0][2] == BLUE and right[0][2] == YELLOW and back[0][0] == ORANGE) or
            (up[0][2] == YELLOW and right[0][2] == BLUE and back[0][0] == ORANGE) or
            (up[0][2] == YELLOW and right[0][2] == ORANGE and back[0][0] == BLUE)) and
           ((up[0][0] == ORANGE and back[0][2] == YELLOW and left[0][0] == GREEN) or
            (up[0][0] == ORANGE and back[0][2] == GREEN and left[0][0] == YELLOW) or
            (up[0][0] == GREEN and back[0][2] == YELLOW and left[0][0] == ORANGE) or
            (up[0][0] == GREEN and back[0][2] == ORANGE and left[0][0] == YELLOW) or
            (up[0][0] == YELLOW and back[0][2] == ORANGE and left[0][0] == GREEN) or
            (up[0][0] == YELLOW and back[0][2] == GREEN and left[0][0] == ORANGE));
}

/**
 * \brief Метод для сборки третьего слоя кубика Рубика.
 * 
 * Этот метод собирает третий слой кубика Рубика. Создает оранжевый крест.
 * Проверяет на правильность расположения рёбер оранжевого креста. Исправляет рёбра, если они неправильно расположены.
 */
void Cube::third() {

    // Собираем просто оранжевый крест
    while (!orange_cross_check()) {
        if (up[0][1] == ORANGE and up[1][2] == ORANGE and up[2][1] != ORANGE and up[1][0] != ORANGE) {
            left_rotation_90();
            front_pif_paf();
            left_rotation_against_90();
        } else if (up[0][1] == ORANGE and up[1][2] != ORANGE and up[2][1] == ORANGE and up[1][0] != ORANGE) {
            left_rotation_90();
            front_pif_paf();
            left_rotation_against_90();
        } else if (up[0][1] != ORANGE and up[1][2] == ORANGE and up[2][1] == ORANGE and up[1][0] != ORANGE) {
            back_rotation_90();
            left_pif_paf();
            back_rotation_against_90();
        } else if (up[0][1] == ORANGE and up[1][2] != ORANGE and up[2][1] != ORANGE and up[1][0] == ORANGE) {
            front_rotation_90();
            right_pif_paf();
            front_rotation_against_90();
        } else if (up[0][1] != ORANGE and up[1][2] == ORANGE and up[2][1] != ORANGE and up[1][0] == ORANGE) {
            front_rotation_90();
            right_pif_paf();
            front_rotation_against_90();
        } else if (up[0][1] != ORANGE and up[1][2] != ORANGE and up[2][1] == ORANGE and up[1][0] == ORANGE) {
            right_rotation_90();
            back_pif_paf();
            right_rotation_against_90();
        } else if (up[0][1] != ORANGE and up[1][2] != ORANGE and up[2][1] != ORANGE and up[1][0] != ORANGE) {
            front_rotation_90();
            right_pif_paf();
            front_rotation_against_90();
        }
    }

    // Проверка на правильность (грани нужных цветов)
    bool flag = 0;
    if (check_orange_right_cross())
        flag = 1;
    else {
        up_rotation_90();
        if (check_orange_right_cross()) flag = 1;
        else {
            up_rotation_90();
            if (check_orange_right_cross())
                flag = 1;
            else {
                up_rotation_90();
                if (check_orange_right_cross())
                    flag = 1;
            }
        }
    }

    // Если собрали оранжевый крест, но ребра не тех цветов (неправильный оранжевый крест)
    if (!flag) {
        while (!check_orange_right_cross()) {
            up_rotation_90();
            if (right[0][1] == BLUE and back[0][1] == YELLOW) {
                right_rotation_90();
                up_rotation_90();
                right_rotation_against_90();
                up_rotation_90();
                right_rotation_90();
                up_rotation_90();
                up_rotation_90();
                right_rotation_against_90();
                up_rotation_90();
            } else if (right[0][1] == BLUE and front[0][1] == WHITE) {
                front_rotation_90();
                up_rotation_90();
                front_rotation_against_90();
                up_rotation_90();
                front_rotation_90();
                up_rotation_90();
                up_rotation_90();
                front_rotation_against_90();
                up_rotation_90();
            } else if (front[0][1] == WHITE and left[0][1] == GREEN) {
                left_rotation_90();
                up_rotation_90();
                left_rotation_against_90();
                up_rotation_90();
                left_rotation_90();
                up_rotation_90();
                up_rotation_90();
                left_rotation_against_90();
                up_rotation_90();
            } else if (left[0][1] == GREEN and back[0][1] == YELLOW) {
                back_rotation_90();
                up_rotation_90();
                back_rotation_against_90();
                up_rotation_90();
                back_rotation_90();
                up_rotation_90();
                up_rotation_90();
                back_rotation_against_90();
                up_rotation_90();
            } else if (right[0][1] == BLUE and left[0][1] == GREEN) {
                back_rotation_90();
                up_rotation_90();
                back_rotation_against_90();
                up_rotation_90();
                back_rotation_90();
                up_rotation_90();
                up_rotation_90();
                back_rotation_against_90();
            } else if (front[0][1] == WHITE and back[0][1] == YELLOW) {
                right_rotation_90();
                up_rotation_90();
                right_rotation_against_90();
                up_rotation_90();
                right_rotation_90();
                up_rotation_90();
                up_rotation_90();
                right_rotation_against_90();
            }
        }
    }

    // Постановка праивльно углов 3 слоя
    while (!check_upper_edges()) {
        if ((up[2][2] == ORANGE and front[0][2] == WHITE and right[0][0] == BLUE) or
            (up[2][2] == ORANGE and front[0][2] == BLUE and right[0][0] == WHITE) or
            (up[2][2] == WHITE and front[0][2] == ORANGE and right[0][0] == BLUE) or
            (up[2][2] == WHITE and front[0][2] == BLUE and right[0][0] == ORANGE) or
            (up[2][2] == BLUE and front[0][2] == WHITE and right[0][0] == ORANGE) or
            (up[2][2] == BLUE and front[0][2] == ORANGE and right[0][0] == WHITE)) {
            up_rotation_90();
            right_rotation_90();
            up_rotation_against_90();
            left_rotation_against_90();
            up_rotation_90();
            right_rotation_against_90();
            up_rotation_against_90();
            left_rotation_90();
        } else if ((front[0][0] == WHITE and left[0][2] == GREEN and up[2][0] == ORANGE) or
                   (front[0][0] == WHITE and left[0][2] == ORANGE and up[2][0] == GREEN) or
                   (front[0][0] == GREEN and left[0][2] == ORANGE and up[2][0] == WHITE) or
                   (front[0][0] == GREEN and left[0][2] == WHITE and up[2][0] == ORANGE) or
                   (front[0][0] == ORANGE and left[0][2] == GREEN and up[2][0] == WHITE) or
                   (front[0][0] == ORANGE and left[0][2] == WHITE and up[2][0] == GREEN)) {
            up_rotation_90();
            front_rotation_90();
            up_rotation_against_90();
            back_rotation_against_90();
            up_rotation_90();
            front_rotation_against_90();
            up_rotation_against_90();
            back_rotation_90();
        } else if ((up[0][2] == ORANGE and right[0][2] == BLUE and back[0][0] == YELLOW) or
                   (up[0][2] == ORANGE and right[0][2] == YELLOW and back[0][0] == BLUE) or
                   (up[0][2] == BLUE and right[0][2] == ORANGE and back[0][0] == YELLOW) or
                   (up[0][2] == BLUE and right[0][2] == YELLOW and back[0][0] == ORANGE) or
                   (up[0][2] == YELLOW and right[0][2] == BLUE and back[0][0] == ORANGE) or
                   (up[0][2] == YELLOW and right[0][2] == ORANGE and back[0][0] == BLUE)) {
            up_rotation_90();
            back_rotation_90();
            up_rotation_against_90();
            front_rotation_against_90();
            up_rotation_90();
            back_rotation_against_90();
            up_rotation_against_90();
            front_rotation_90();
        } else if ((up[0][0] == ORANGE and back[0][2] == YELLOW and left[0][0] == GREEN) or
                   (up[0][0] == ORANGE and back[0][2] == GREEN and left[0][0] == YELLOW) or
                   (up[0][0] == GREEN and back[0][2] == YELLOW and left[0][0] == ORANGE) or
                   (up[0][0] == GREEN and back[0][2] == ORANGE and left[0][0] == YELLOW) or
                   (up[0][0] == YELLOW and back[0][2] == ORANGE and left[0][0] == GREEN) or
                   (up[0][0] == YELLOW and back[0][2] == GREEN and left[0][0] == ORANGE)) {
            up_rotation_90();
            left_rotation_90();
            up_rotation_against_90();
            right_rotation_against_90();
            up_rotation_90();
            left_rotation_against_90();
            up_rotation_against_90();
            right_rotation_90();
        } else {
            up_rotation_90();
            right_rotation_90();
            up_rotation_against_90();
            left_rotation_against_90();
            up_rotation_90();
            right_rotation_against_90();
            up_rotation_against_90();
            left_rotation_90();
        }
    }

    // Ставим углы (сборка оранжевой грани)
    for (int i = 0; i < 5; i++) {
        if (up[0][0] != ORANGE)
            while (up[0][0] != ORANGE) {
                back_rotation_90();
                down_rotation_90();
                back_rotation_against_90();
                down_rotation_against_90();
            }
        up_rotation_90();
    }

    // Доварачиваем до собранного вида
    while (!assembly_check()) {
        up_rotation_90();
    }

}

/**
 * \brief Основной метод для решения кубика Рубика.
 * 
 * Этот метод выполняет все необходимые шаги для решения кубика Рубика.
 * Он проверяет корректность введённых значений, а затем выполняет последовательность
 * алгоритмов для решения всех слоев кубика.
 * 
 * \details Метод работает следующим образом:
 * 1. Проверяет корректность введённых значений с помощью метода check().
 * 2. Если значения некорректны, выводит сообщение и завершает работу.
 * 3. Если значения корректны, выводит процесс решения.
 * 4. Вызывает методы для решения каждого слоя кубика:
 *    - flower()
 *    - right_cross()
 *    - first_layer()
 *    - second()
 *    - third()
 */
void Cube::main_solver() {
    if (!check()) {
        cout << "try to to reenter values";
        return;
    }
    cout << "Process:" << '\n';
    flower();
    right_cross();
    first_layer();
    second();
    third();
}

