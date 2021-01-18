/**
 * @file main.cpp
 * @author vmf0min (vlifom@yandex.ru)
 * @brief Задание 1. Очередь из роботов
 * Повторите программу из теоретического материала. Напишите электронную очередь
 * для андроидов. Их количество неизвестно заранее. Каждый андроид вводит с
 * клавиатуры свой идентификационный номер - целое число. Нужно сохранить их
 * номера в векторе в том порядке, в котором они записывались в очередь.
 * @version 0.1
 * @date 18-01-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <vector>

/**
 * @brief Добавление в конец вектора нового значения.
 * @note По идее можно обойтись resize(). Если не использовать push_back().
 * @param vecIn вектор, который надо увеличить.
 * @param val значение для вектора.
 * @return std::vector<int> новый вектор с измененным значением.
 */
std::vector<int> addToEnd(const std::vector<int> &vecIn, const int &val) {
  std::vector<int> newVec(vecIn.size() + 1);
  // Копирование в новый вектор, чтобы не гонять цикл.
  std::copy(vecIn.begin(), vecIn.end(), newVec.begin());
  // Добавление в конец вектора значения.
  newVec[vecIn.size()] = val;

  return newVec;
}

int main() {
  std::cout << "\e[2JHow many robots: ";
  std::vector<int> vectorInt{3, 5, 7, 10, 11, 12};
  for (const auto &i : vectorInt) std::cout << i << " ";
  std::cout << "\n";

  int num{};
  while (num != -1) {
    std::cout << "Enter your registration index: ";
    std::cin >> num;
    vectorInt = addToEnd(vectorInt, num);
  }

  // vectorInt.erase(vectorInt.end() - 1);
  // удаление -1.
  vectorInt.pop_back();
  std::cout << "Queue robots: ";
  for (const auto &i : vectorInt) std::cout << i << " ";

  return 0;
}