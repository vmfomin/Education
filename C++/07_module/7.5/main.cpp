/// Задача 5. Кратность числа.

#include <iostream>

int main() {
    int a, b;

    std::cout << "Проверка деления на целое\n"
              << "Введите делимое: ";
    std::cin >> a;

    std::cout << "Введите делитель: ";
    std::cin >> b;

    if (a % b == 0) std::cout << "Делится без остатка: " << a / b << " целых\n";
    else std::cout << "Делится c остатком: " << a / b << " целых и " << a % b << " в остатке\n";

    return 0;
}
