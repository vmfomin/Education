/// Задача 1. Минимум из двух чисел.
#include <iostream>

int main() {
    std::cout << "Программа вычисления минимум из двух чисел.\n";
    int x, y;

    std::cout << "Введите число X: ";
    std::cin >> x;

    std::cout << "Введите число Y: ";
    std::cin >> y;

    if (x < y) std::cout << "X = " << x << "\n";
    else if (x == y) std::cout << "X равен Y = " << x << "\n";
    else std::cout << "Y = " << y << "\n";

    std::cout << "Проверка функцией min(): " << std::min(x, y) << "\n";

    return 0;
}
