/**
 * @file main.cpp
 * @author vmf0min (vlifom@yandex.ru)
 * @brief Задание 1
 * Пользователь вводит с клавиатуры число n, а затем -- n целых чисел.
 * Необходимо вычислить их среднее арифметическое и вывести на экран.
 * @version 0.1
 * @date 15-01-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <vector>

int main() {
  std::cout << "\e[2JHow many integers do you want to enter? ";
  int n;
  std::cin >> n;

  std::vector<int> vectorInt(n);
  std::cout << "Enter integers: ";
  for (auto &vec : vectorInt) std::cin >> vec;

  float average{};
  for (const auto &vec : vectorInt) average += vec;

  average /= vectorInt.size();

  std::cout << "Average integers: " << average << "\n";

  return 0;
}