/**
 * @file main.cpp
 * @author vmf0min (vlifom@yandex.ru)
 * @brief Задание 2
 * Робот приходит в очередь и заставляет уходить из конца очереди всех, чей
 * номер меньше, чем у него, а потом становится в очередь сам. Последний робот
 * будет иметь номер -1 (и, соответственно, не сможет никого выгнать, так как
 * остальные имеют положительные номера). Когда он пришёл, нужно вывести все
 * номера в очереди на экран.
 * @version 0.1
 * @date 21-01-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <vector>

int main() {
  std::cout << "\e[2J\e[37mHow many robots: ";
  std::vector<int> vectorInt{10, 5, 7, 10, 11, 8};
  for (const auto &i : vectorInt) std::cout << i << " ";
  std::cout << "\n";

  int num{};
  while (num != -1) {
    std::cout << "Enter your registration index: \e[32m";
    std::cin >> num;

    if (num <= 0 && num != -1) {
      std::cout << "\e[31mError: registration index must be positive!\e[37m\n";
      continue;
    }
    std::cout << "\e[37m";

    for (auto iter{vectorInt.rbegin()}; iter != vectorInt.rend(); ++iter) {
      if (num > *iter)
        vectorInt.pop_back();
      else
        break;
    }

    vectorInt.push_back(num);

    std::cout << "\e[36mQueue robots: ";
    for (const auto &i : vectorInt) std::cout << i << " ";

    std::cout << "\e[37m\n";
  }

  return 0;
}