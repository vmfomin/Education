/// Задача 8. Сокращение дроби.
/// Пользователь вводит числа M и N. Напишите программу, которая преобразует
/// дробь M/N к несократимому виду и выдает получившийся результат. Необходимо
/// обеспечить контроль ввода.
/// Например, при введенных числах 4 6 результатом должно быть 2/3.
/// При числах 25 40 результатом должно быть 5/8.

#include <iostream>

int main() {
    int a, b;

    std::cout << "Введите дробь через пробел: ";
    std::cin >> a >> b;

    if (b == 0) {
        std::cout << "Знаменатель не может быть равен 0!\n\n";
        return -1;
    }

    std::cout << "До:    " << a << " / " << b << "\n";

    // Проверка на сокращение числителя и знаменателя.
    bool isReduce = false;

    int denominator = a; // С чего начнем сокращать.

    /// Повел цикл в обратном направлении до нахождения НОД.
    while (denominator > 1) {
        isReduce = (a % denominator == 0) && (b % denominator == 0);

        if (isReduce) {
            a /= denominator;
            b /= denominator;
            denominator = 0; // Для завершения цикла
        }

        denominator--;
    }

    if (isReduce)
        std::cout << "После: " << a << " / " << b << "\n";
    else
        std::cout << "Нельзя сократить!\n";

    return 0;
}