/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 4.
 * Разработайте программу, которая получает на вход, в стандартный ввод, путь к
 * файлу. На выходе программа должна определить, является ли данный файл
 * PNG-изображением. Данная процедура не просто должна смотреть на расширение
 * файла, но и произвести минимальный анализ его внутренностей, в бинарном
 * режиме.
 * Внутренности валидного бинарного файла начинаются со специального 8-байтового
 * заголовка. Нас будут интересовать первые четыре байта. Первый байт всегда
 * имеет значение −119 (число со знаком минус), а следующие — это просто символы
 * ‘P’, ‘N’, ‘G’, расположенные друг за другом. Обратите внимание, что все они в
 * верхнем регистре.
 * @version   0.1
 * @date      25-03-2021
 * @copyright Copyright (c) 2021
 */

#include <fstream>
#include <iostream>

using std::cin;
using std::cout;

int main() {
  cout << "\x1b[2J";
  cout << "Enter filename with path: ";
  std::string filename;
  cin >> filename;

  std::string sub{filename.substr(filename.size() - 4)};
  if (sub != ".png") {
    cout << "Error: incorrect format of file!\n";
    return 1;
  }

  std::ifstream pngFile(filename, std::ios::binary);
  if (!pngFile) {
    cout << "Error: could not be opened for reading!\n";
    return 1;
  }

  char buf[4];
  pngFile.read(buf, sizeof(buf));
  cout << (-119 == buf[0] && 'P' == buf[1] && 'N' == buf[2] && 'G' == buf[3]
               ? "png file is valid.\n"
               : "Error: png file is invalid.\n");

  pngFile.close();
  cout << std::endl;
  return 0;
}