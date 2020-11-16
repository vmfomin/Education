/// Задача 10. Угадай число - наоборот.
/// Напишите программу, которая угадывает число, задуманное пользователем. Число
/// загадывается в диапазоне от 0 до 63. Программа задает вопросы вида “ваше
/// число больше такого-то?” и на основе ответов пользователя “да” или “нет”
/// угадывает число.

#include <iostream>

int main() {
    #pragma region Старый код с использованием rand()
/*
    int minValue = 0;
    int lastValue = 64;
    int x;

    std::cout << "Отвечайте \"да\" или \"нет\" в зависимотсти от числа.\nКак только программа"
                 " отгадает -- ответьте \"отгадали!\"\n";
    std::string answer;

    bool isFound = false;
    while (!isFound) {
        x = rand() % lastValue;

        if (x <= minValue || x == lastValue)
            continue;

        isFound = x == minValue || x == lastValue;

        std::cout << "Ваше число больше? " << x << " ";
        std::cin >> answer;

        if ("да" == answer) {
            minValue = x;
        } else if ("нет" == answer) {
            lastValue = x;
        } else isFound = true;
    }
 */
#pragma endregion

    int questionNumber[]{10, 20, 30, 40, 50, 60};
    int firstValue = 0, lastValue = -1;

    std::cout << "Отвечайте \"y\" или \"n\" в зависимотсти от числа.\nКак только программа"
                 " отгадает -- ответьте \"f\"\n";
    std::string answer;

    int counterNumbers = 0;
    bool isFound = false;
    bool isRange = false;
    while (!isRange) {
        isRange = firstValue < lastValue;

        if (!isRange) {
            std::cout << "Ваше число больше? " << questionNumber[counterNumbers] << " ";
            std::cin >> answer;

            if ("y" == answer) {
                firstValue = questionNumber[counterNumbers];
            } else if ("n" == answer) {
                lastValue = questionNumber[counterNumbers];
            }

            counterNumbers++;
            if (6 == counterNumbers)
                counterNumbers = 0;
        } else {
            std::cout << "Нашли диапазон: от " << firstValue
                      << " до " << lastValue << "\n";
            isRange = true;
        }
    }

    while (!isFound) {
        std::cout << "Ваше число больше? " << firstValue << " ";
        std::cin >> answer;

        if ("y" == answer) {
            firstValue++;
        } else if ("n" == answer) {
            lastValue--;
        } else if ("f" == answer) {
            isFound = true;
            std::cout << "\nНашли.\n";
        }
    }

    return 0;
}
