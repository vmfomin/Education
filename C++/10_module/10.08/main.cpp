/// Задача 8. Автограф разработчика.
/// Напишите программу, которая печатает на экране ваше имя в прямоугольной рамке.
/// Для вертикальных линий используйте символ вертикального штриха “|”, а для
/// горизонтальных - дефис “-”.


#include <iostream>

int main() {
    int16_t height{3}; // Высота по умолчанию.

    // Заметил, что кириллица в 2 раза длиньше, чем латиница.
    std::cout << "Введите имя разработчика на латинице: ";
    std::string name{};
    std::cin >> name;

    int16_t nameLength = name.length(); // Длина символов в имени.

    bool isWriteName{}; // Проверка записи имени в консоль.
    for (int i = 0; i < height; i++) {
        std::cout << "|";
        for (int j = 0; j < nameLength; j++) {
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
