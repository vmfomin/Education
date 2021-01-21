/**
 * @file main.cpp
 * @author vmf0min (vlifom@yandex.ru)
 * @brief Задание 3 (необязательное)
 * Роботы приходят в очередь и называют(вводят с клавиатуры) свои порядковые
 * номера (целые положительные). Комната, в которой роботы-андроиды занимают
 * своё место, имеет ограниченный размер (который равен capacity вектора, в
 * который вы их записываете). Когда комната заполняется, роботам приходится
 * “переходить” в другую комнату, чуть больше (но вы этого не видите).
 * Необходимо отследить, когда в комнате будет оставаться всего 2 свободных
 * места для роботов, и вывести сообщение об этом на экран. Последний робот
 * будет иметь номер -1.
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
  std::cout << "\e[37m\nCapacity = " << vectorInt.capacity() << ".\n";

  int num{};
  while (num != -1) {
    std::cout << "Enter your registration index: \e[32m";
    std::cin >> num;

    if (num <= 0 && num != -1) {
      std::cout << "\e[31mError: registration index must be positive!\e[37m\n";
      continue;
    }

    vectorInt.push_back(num);

    if (vectorInt.size() == vectorInt.capacity() - 1) {
      std::cout << "The queue is almost full.\n";
      num = -1;
      vectorInt.push_back(num);
    }

    std::cout << "\e[37mCapacity = " << vectorInt.capacity() << ".\n";

    std::cout << "\e[36mQueue robots: ";
    for (const auto &i : vectorInt) std::cout << i << " ";

    std::cout << "\e[37m\n";
  }
  std::cout << "\e[37mCapacity = " << vectorInt.capacity() << ".\n";
  return 0;
}