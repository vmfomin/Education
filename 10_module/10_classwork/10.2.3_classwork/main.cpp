/// Задача 3. Таблица умножения.
/// Первоклассник Вася родился в век высоких технологий и не умеет умножать в уме.
/// Он боится контрольной работы на знание таблицы умножения, поэтому он решил
/// написать на С++ программу-шпаргалку. Вася хочет ввести число, а программа
/// должна выдать таблицу умножения для этого числа. Помогите Васе написать программу.


#include <iostream>

int main() {
    int multiply;

    std::cout << "Введите число для умножения: ";
    std::cin >> multiply;

    for (int i = 0; i < 10; i++)
        std::cout << multiply << " * " << i << " = " << multiply * i << "\n";

    return 0;
}
