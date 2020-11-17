/// Задача 8. Автограф разработчика.
/// Напишите программу, которая печатает на экране ваше имя в прямоугольной рамке.
/// Для вертикальных линий используйте символ вертикального штриха “|”, а для
/// горизонтальных - дефис “-”.


#include <iostream>

int main() {
    int16_t nameLength{}; // Длина символов в имени.
    int16_t height{3}; // Высота по умолчанию.
    std::string name{};

    // Заметил, что кириллица в 2 раза длиньше, чем латиница.
    std::cout << "Введите имя разработчика на литинице: ";
    std::cin >> name;

    nameLength = name.length();

    bool isWriteName{}; // Проверка записи имени в консоль.

    for (int i{}; i < height; i++) {
        std::cout << "|";
        for (int j{}; j < nameLength; j++) {
            if (i == 0 || i == height - 1)
                std::cout << "-";
            else if (!isWriteName) {
                std::cout << name;
                isWriteName = true;
            }
            if (j == nameLength - 1)
                std::cout << "|";
        }
        std::cout << "\n";
    }

    return 0;
}
