/**
 * @file vector_user.cpp
 * @author vmf0min (vlifom@yandex.ru)
 * @brief Функции вектора для решения задач после уроков.
 * @version 0.1
 * @date 19-01-2021
 * @copyright Copyright (c) 2021
 */

#include "vector_user.h"

void add(std::vector<int> &vecIn, const int &val) {
  vecIn.resize(vecIn.size() + 1);
  // Добавление в конец вектора значения.
  vecIn[vecIn.size() - 1] = val;
}

std::vector<int> add(const std::vector<int> &vecIn, const int &val,
                     const int &pos) {
  std::vector<int> newVec(vecIn.size() + 1);
  // Копирование в новый вектор до текущей позиции.
  std::copy(vecIn.begin(), vecIn.begin() + pos, newVec.begin());

  // Добавление значения в вектор на указанную позицию.
  newVec[pos] = val;

  // Копирование остатка.
  std::copy(vecIn.begin() + pos, vecIn.end(), &newVec[pos + 1]);

  return newVec;
}

void remove_index(std::vector<int> &vec) { vec.resize(vec.size() - 1); }

std::vector<int> remove_index(std::vector<int> &vec, const int &pos) {
  std::vector<int> newVec(vec.size() - 1);
  // Копирование в новый вектор до текущей позиции.
  std::copy(vec.begin(), vec.begin() + pos, newVec.begin());
  // Копирование остатка.
  std::copy(vec.begin() + pos + 1, vec.end(), &newVec[pos]);

  return newVec;
}
