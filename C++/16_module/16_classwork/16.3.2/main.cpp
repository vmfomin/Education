/**
 * @file main.cpp
 * @author vmf0min (vlifom@yandex.ru)
 * @brief Задание 2
 * Представим, что роботов могут не только покупать, забирая с витрины, но и
 * “выставлять” в конец витрины. Пусть с клавиатуры вводят число K, а потом -- K
 * запросов вида “1 n” и “2 m”. Запрос вида “1 n” означает, что в конец витрины
 * поставили робота номер n. Запрос “2 m” означает, что из витрины забрали
 * робота по индексу m. Необходимо смоделировать такое взаимодействие и после
 * проведения всех запросов вывести на экран оставшихся на витрине роботов.
 * @version 0.1
 * @date 20-01-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>

#include "vector_user.h"

int main() {
  std::cout << "\e[34m\e[2JThe robots in the store:\t";
  std::vector<int> vectorInt{100, 200, 300, 400, 500};
  for (const auto &i : vectorInt) std::cout << i << " ";
  std::cout << "\e[37m\n";
  int num{};
  size_t index_remove{};
  while (true) {
    std::cout << "\e[37mEnter your registration index:\t\e[32m";
    std::cin >> num;

    if (num == -1) break;

    add(vectorInt, num);

    std::cout << "\e[37mRobots with an added one:\t";
    for (const auto &i : vectorInt) std::cout << i << " ";

    std::cout << "\e[37m\nWhich robot you want to buy?\t\e[32m";
    std::cin >> index_remove;

    if (index_remove > vectorInt.size()) {
      std::cout << "\e[31mThis brand of robot is no longer on sale.\n";
      continue;
    }
    --index_remove;

    vectorInt = remove_index(vectorInt, index_remove);

    std::cout << "\e[37mRobots after selecting one:\t";
    for (const auto &i : vectorInt) std::cout << i << " ";
    std::cout << "\n";
  }

  std::cout << "\e[35mRobots after the store closes:\t";
  for (const auto &i : vectorInt) std::cout << i << " ";
  std::cout << "\e[37m\n";

  return 0;
}