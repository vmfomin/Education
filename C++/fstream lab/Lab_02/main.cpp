/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 2.	Организовать текстовый файл. Удалить в файле все цифры.
 * (создавая новый дополнительный файл)
 * @version   0.1
 * @date      25-03-2021
 * @copyright Copyright (c) 2021
 */

#include <fstream>
#include <iostream>

using std::cin;
using std::cout;

int main() {
  std::ifstream aFile("../a.txt");
  if (!aFile) {
    cout << "Error: could not be opened for reading!";
    return 1;
  }

  std::ofstream bFile("../b.txt");
  if (!bFile) {
    cout << "Error: could not be opened for writing!";
    return 1;
  }

  std::string strWithoutDigits{};
  while (aFile) {
    char textTmp[512];
    aFile.read(textTmp, sizeof(textTmp));
    textTmp[aFile.gcount()] = '\0';

    for (size_t i = 0; i < aFile.gcount(); ++i)
      if (0 == isdigit(textTmp[i])) bFile << textTmp[i];
  }
  
  aFile.close();
  bFile.close();
  cout << std::endl;
  return 0;
}