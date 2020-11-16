/// Задача 10. Угадай число - наоборот.
/// Напишите программу, которая угадывает число, задуманное пользователем. Число
/// загадывается в диапазоне от 0 до 63. Программа задает вопросы вида “ваше
/// число больше такого-то?” и на основе ответов пользователя “да” или “нет”
/// угадывает число.

#include <iostream>

int main() {
    int minValue = 0;
    int lastValue = 64;
    int x;

    std::cout << "Отвечайте \"да\" или \"нет\" в зависимотсти от числа.\nКак только программа"
                 " отгадает -- ответьте \"отгадали\"\n";
    std::string answer;

    bool isFound = false;
    while (!isFound) {
        x = (minValue + lastValue) / 2;
        std::cout << "Ваше число больше? " << x << " ";
        std::cin >> answer;

        if ("да" == answer) {
            minValue = x;
        } else if ("нет" == answer) {
            lastValue = x;
        } else isFound = true;
    }

    return 0;
}
