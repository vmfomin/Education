/**
 * @file main.cpp
 * @author vmf0min (vlifom@yandex.ru)
 * @brief Задание 1
 * С помощью push_back() реализуйте очередь из роботов-андроидов. Роботы
 * приходят в очередь и называют(вводят с клавиатуры) свои порядковые номера
 * (целые положительные). Последний робот в очереди всегда имеет номер -1. Когда
 * он пришёл, необходимо вывести на экран все номера в очереди.
 * @version 0.1
 * @date 20-01-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <vector>

int main() {
  std::cout << "\e[2JHow many robots: ";
  std::vector<int> vectorInt{3, 5, 7, 10, 11, 12};
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

    vectorInt.push_back(num);
  }

  // удаление -1.
  vectorInt.pop_back();

  std::cout << "\e[36mQueue robots: ";
  for (const auto &i : vectorInt) std::cout << i << " ";

  std::cout << "\e[37m";

  return 0;
}