/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 2. Сшиватель дробных чисел.
 * Надо написать небольшую программу. Из целой и дробной частей числа, которые в
 * отдельности вводит пользователь надо составить новое число с плавающей точкой
 * (типа double) и вывести это число обратно в консоль, для проверки. Целая
 * часть - это та, часть числа, которая находится до точки (запятой), дробная -
 * после.
 * @version   0.1
 * @date      09-03-2021
 * @copyright Copyright (c) 2021
 */

#include <iomanip>
#include <iostream>

/**
 * @brief     Check the input number for validity
 * @param     number        input number
 * @return    true          correct number
 */
bool isNumber(std::string& number) {
  for (const auto& c : number)
    if (std::isdigit(c) == 0) return false;
  return true;
}

int main() {
  using std::cout;
  cout << "\x1b[2J";

  std::string realNumber;
  std::string temp;
  cout << "Enter integer part of the number:\t";
  std::cin >> temp;
  if (!isNumber(temp)) {
    cout << "Error: NaN found!\n";
    return 1;
  }

  realNumber = temp + '.';

  cout << "Enter fractional part of the number:\t";
  std::cin >> temp;
  if (!isNumber(temp)) {
    cout << "Error: NaN found!\n";
    return 1;
  }

  realNumber += temp;

  cout << "Real number is " << std::setprecision(15) << std::stod(realNumber);

  cout << "\n";
  return 0;
}