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
 * @version   0.1
 * @date      25-03-2021
 * @copyright Copyright (c) 2021
 */

#include <fstream>
#include <iostream>
#include <iterator>

using std::cin;
using std::cout;

int main() {
  cout << "\x1b[2J";
  cout << "Enter the path to the text file: ";
  std::string path{};
  cin >> path;
  cout << std::endl;

  std::ifstream file(path, std::ios::binary);
  if (!file) {
    cout << "Error: could not be opened for reading!";
    return 1;
  }

  // std::copy(std::istream_iterator<std::string>(file),
  //           std::istream_iterator<std::string>(),
  //           std::ostream_iterator<std::string>(cout, " "));

  char text[50];
  while (file) {
    file.read(text, sizeof(text));
    for (int64_t i{}; i < file.gcount(); ++i) cout << text[i];
  }

  file.close();
  cout << std::endl;
  return 0;
}