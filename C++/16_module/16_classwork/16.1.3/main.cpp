/**
 * @file main.cpp
 * @author vmf0min (vlifom@yandex.ru)
 * @brief Задание 3
 * Пользователь вводит с клавиатуры число n, а затем -- n целых чисел.
 * Необходимо отыскать второе по величине из этих чисел и вывести на экран.
 * @version 0.1
 * @date 15-01-2021
 * @copyright Copyright (c) 2021
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main() {
  std::cout << "\e[2JHow many integer numbers do you want to enter? ";
  int n;
  std::cin >> n;

  if (n <= 0) {
    std::cout << "Error\n";
    return -1;
  }

  std::vector<int> vectorInt(n);
  std::cout << "Enter integers:\n";
  for (auto &vec : vectorInt) std::cin >> vec;

  std::sort(vectorInt.begin(), vectorInt.end(), std::greater{});

  std::cout << "The vector is sorted by STL algorithm\n";
  for (const auto &vec : vectorInt) std::cout << vec << " ";

  std::cout << "\nThe second largest number: \e[36m" << vectorInt[1] << "\e[0m";

  return 0;
}