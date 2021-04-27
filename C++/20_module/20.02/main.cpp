/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задание 2. Реализация рисования случайных картин.
 * С помощью генератора случайных чисел рисуется картинка из нулей и единиц. На
 * вход от пользователя принимается размер картины: высота и ширина в пикселях.
 * На выходе нужно создать файл pic.txt, содержимое которого будет наполнено
 * случайными нулями и единицами в рамках размера картины.
 * @version   0.1
 * @date      30-03-2021
 * @copyright Copyright (c) 2021
 */

#include <ctime>
#include <fstream>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
  cout << "\x1b[2J";
  cout << "Enter the height and width: ";
  int16_t height, width;
  cin >> height >> width;

  std::ofstream pic("../pic.txt", std::ios::binary);
  if (!pic) {
    cout << "Error: could not be opened for writing!";
    return 1;
  }

  std::srand(std::time(nullptr));
  for (size_t i{}; i < height; ++i) {
    for (size_t j{}; j < width; ++j) pic << rand() % 2 << " ";
    pic << endl;
  }

  pic.close();
  cout << "\x1b[0m" << endl;
  return 0;
}