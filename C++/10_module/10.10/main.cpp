/* Задача 10. Ёлочка.
Напишите программу, которая выводит на экран равнобедренный треугольник,
заполненный символами решётки ‘#”. Пусть высота треугольника вводится
пользователем. Обеспечьте контроль ввода.
   #
  ###
 ##### */

#include <iostream>

int main() {
  std::cout << "\e[0mВведите высоту равнобедренного треугольника: ";
  int16_t height{10};
  std::cin >> height;
  std::cout << "\n";

  int16_t baseTriangle = height * 2;  // Основание равнобедренного треугольника.
  int16_t centerTriangle = baseTriangle / 2;

  int16_t countSharps{};

  for (int i = 0; i < height; ++i) {
    // Высчитываю сколько должно быть # в строке
    int16_t sharpInLine = i * 2 + 1;
    for (int j = 0; j < baseTriangle; ++j) {
      if (j < centerTriangle - sharpInLine || j > centerTriangle + sharpInLine)
        std::cout << " ";
      else {
        if (countSharps < sharpInLine)
          if (countSharps == 0 && i == 0) {
            std::cout << "\e[33;1m"
                      << "*\e[0m";
          } else if (countSharps == 0 || countSharps == sharpInLine - 1 ||
                     countSharps % 4 == 0) {
            std::cout << "\e[31;1m"
                      << "o\e[0m";
          } else
            std::cout << "\e[36;1m"
                      << "#\e[0m";
        else
          std::cout << " ";
        countSharps++;
      }
    }
    countSharps = 0;
    centerTriangle++;
    std::cout << "\e[0m\n";
  }

  return 0;
}
