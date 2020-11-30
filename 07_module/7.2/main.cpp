/// Задача 2. Складываем в уме.
#include <iostream>

int main() {
    int a;
    int b;
    int sum;

    std::cout << "Введите 1 число: ";
    std::cin >> a;

    std::cout << "Введите 2 число: ";
    std::cin >> b;

    std::cout << "Введите сумму чисел: ";
    std::cin >> sum;

    if (sum != (a + b)) std::cout << "Неверно. Правильная сумма: " << a + b << "\n";
    else std::cout << "Верно\n";

    return 0;
}
