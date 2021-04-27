/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 2.
 * Разработайте простейший просмотрщик текстовых файлов. В начале программы
 * пользователь вводит путь к текстовому файлу, который требуется открыть и
 * просмотреть. Внутренности файла необходимо вывести в стандартный вывод.
 * Программа должна работать для любых текстовых файлов в формате TXT, но вы
 * можете создать и свой отдельный файл для теста. Главное, чтобы файл был
 * англоязычным, дабы избежать проблем с кодировками.
 * @version   0.2
 * @date      25-03-2021
 * @copyright Copyright (c) 2021
 */

#include <fstream>
#include <iostream>

using std::cin;
using std::cout;

int main() {
  cout << "\x1b[2J";
  cout << "Enter the path to the text file: ";
  std::string path{"../words.txt"};
  cin >> path;
  cout << std::endl;

  std::ifstream file(path, std::ios::binary);
  if (!file) {
    cout << "Error: could not be opened for reading!";
    return 1;
  }

  while (file) {
    char text[20];
    file.read(text, sizeof(text));
    text[file.gcount()] = '\0';
    cout << text;
  }

  file.close();
  cout << std::endl;
  return 0;
}