/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 1.	Дан файл вещественных чисел a.txt. Найти количество
 * нулевых элементов и произведение элементов меньших 1 и больших 0.
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

  int16_t nZeros = 0;
  double multiply = 1;
  double number = 0;
  while (aFile) {
    std::string numberStr;
    aFile >> numberStr;
    if (!numberStr.empty()) {
      number = std::stod(numberStr);
      if (0 == number) ++nZeros;
      if (number < 1 && number > 0) multiply *= number;
    }
  }

  cout << "Count of zeros = " << nZeros
       << "; Multiplication of numbers = " << multiply;

  aFile.close();
  cout << std::endl;
  return 0;
}