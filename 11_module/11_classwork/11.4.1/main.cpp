/// Задача 1. Ход конём
/// В рамках разработки шахматного искусственного интеллекта стоит новая задача.
/// По заданным вещественным координатам коня и второй точки программа должна
/// определить, может ли конь ходить в эту точку. Используйте как можно меньше
/// конструкций if и логических операторов. Обеспечьте контроль ввода.
/// Пример:
/*
Ввод:
Введите местоположение коня:
0.071;
0.118.
Введите местоположение точки на доске:
0.213;
0.068.
Вывод:
Конь в клетке (0, 1). Точка в клетке (2, 0).
Да, конь может ходить в эту точку.
*/

#include <iostream>
#include <cmath>

struct Coord {
    float x, y;
};

int main() {
    std::cout << "Ввод:\nВведите местоположение коня: ";
    Coord coordHorse{};
    std::cin >> coordHorse.x >> coordHorse.y;

    std::cout << "Введите местоположение точки на доске: ";
    Coord coordPoint{};
    std::cin >> coordPoint.x >> coordPoint.y;

    // Приведение к целым значениям и с отбрасыванием дробных частей.
    coordHorse.x = std::floor(coordHorse.x *= 10);
    coordHorse.y = std::floor(coordHorse.y *= 10);

    coordPoint.x = std::floor(coordPoint.x *= 10);
    coordPoint.y = std::floor(coordPoint.y *= 10);

    std::cout << "Вывод:\n"
                 "Конь в клетке (" << coordHorse.x << ", " << coordHorse.y << "). "
              << "Точка в клетке (" << coordPoint.x << ", " << coordPoint.y << ").\n";

    if (fabsf(coordPoint.x - coordHorse.x) == 2 && fabsf(coordPoint.y - coordHorse.y) == 1 ||
        fabsf(coordPoint.x - coordHorse.x) == 1 && fabsf(coordPoint.y - coordHorse.y) == 2)
        std::cout << "Да, конь может ходить в эту точку.";
    else
        std::cout << "Нет, конь не может ходить в эту точку.";

    return 0;
}
