/**
 * @file main.cpp
 * @author vmf0min (vlifom@yandex.ru)
 * @brief Задание 1
 * На витрине стоят несколько роботов, у каждого есть свой номер. Они задаются с
 * клавиатуры (сначала вводится число n, потом -- n номеров роботов). Далее
 * вводится число m и после этого -- m индексов (от 0 до количества оставшихся
 * роботов на витрине). Когда введён очередной индекс -- робота покупают, то
 * есть он покидает витрину, а остальные роботы “группируются”, смещаясь на один
 * шаг назад. Необходимо вывести список оставшихся, после всех покупок, роботов.
 * Пример: на витрине стояли роботы {100, 200, 250, 300}. Сначала забрали робота
 * с индексом 1, то есть с номером 200, осталось {100,250,300}. Потом забрали
 * робота с индексом 1, то есть с номером 250, осталось {100,300}
 * @version 0.1
 * @date 18-01-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>

#include "vector_user.h"

int main() {
  std::cout << "\e[2JEnter the robot indexes in the store:\n";
  std::vector<int> vectorInt;

  int num{};
  while (num != -1) {
    std::cout << "Enter your registration index: ";
    std::cin >> num;
    add(vectorInt, num);
  }
  // удаление -1.
  remove_index(vectorInt);

  std::cout << "The robots in the store: ";
  for (const auto &i : vectorInt) std::cout << i << " ";
  std::cout << "\n";

  size_t index_remove{};
  while (true) {
    std::cout << "Enter which robot you want to buy?: ";
    std::cin >> index_remove;

    if (index_remove > vectorInt.size()) {
      std::cout << "This brand of robot is no longer on sale.\n";
      continue;
    }
    --index_remove;

    vectorInt = remove_index(vectorInt, index_remove);

    if (!vectorInt.empty()) {
      std::cout << "Robots: ";
      for (const auto &i : vectorInt) std::cout << i << " ";
      std::cout << "\n";
    } else {
      std::cout << "\nAll the robots were sold.\n";
      break;
    }
  }

  return 0;
}