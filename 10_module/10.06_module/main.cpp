/// Задача 6. Рамка.
/// Напишите программу, которая рисует с помощью символьной графики прямоугольную
/// рамку. Для вертикальных линий используйте символ вертикального штриха “|”,
/// а для горизонтальных - дефис “-”. Пусть пользователь вводит ширину и высоту рамки.

#include <iostream>

int main() {
    std::cout << "Введите ширину и высоту рамки: ";
    int16_t a{}, b{};
    std::cin >> a >> b;

    for (int i = 0; i < b; i++) {
        std::cout << "|";
        for (int j = 0; j < a; j++) {
            if (i == 0 || i == b - 1)
                std::cout << "-";
            else
                std::cout << " ";
            if (j == a - 1)
                std::cout << "|";
        }
        std::cout << "\n";
    }

    return 0;
}
