/**
 * @file main.cpp
 * @author vmf0min (vlifom@yandex.ru)
 * @brief Задание 2
 * Пользователь вводит с клавиатуры число n, а затем -- n действительных
 * (дробных) чисел. Необходимо вывести их все в обратном порядке (то есть
 * сначала то число, которые пользователь ввёл последним и так далее).
 * @version 0.1
 * @date 15-01-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <vector>

int main() {
  std::cout << "\e[2JHow many real numbers do you want to enter? ";
  int n;
  std::cin >> n;

  std::vector<float> vectorFloat(n);
  std::cout << "Enter floats:\n";
  for (auto &vec : vectorFloat) std::cin >> vec;

  std::cout << "Output a vector using a constant reverse_iterator\n";
  for (auto iter{vectorFloat.crbegin()}; iter != vectorFloat.crend(); ++iter)
    std::cout << *iter << " ";

  return 0;
}