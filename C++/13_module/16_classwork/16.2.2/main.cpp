/**
 * @file main.cpp
 * @author vmf0min (vlifom@yandex.ru)
 * @brief Задание 2. Лечебница
 * Напишите программу для картотеки пациентов лечебницы. С клавиатуры вводится
 * неизвестное количество целых положительных чисел - возрастов пациентов. Когда
 * пациенты заканчиваются, медсестра вводит число -1. Это говорит программе о
 * том, что пора заканчивать с приемом пациентов и переходить к расчету
 * статистики. Напишите программу, складывающую в вектор целые положительные
 * числа, пока не поступит отрицательное число. После этого выведите среднее
 * значение всех введенных чисел и их количество.
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
  std::cout << "\e[2J";
  std::vector<int> vectorInt;
  for (const auto &i : vectorInt) std::cout << i << " ";
  std::cout << "\n";

  int num{};
  while (num != -1) {
    std::cout << "Enter your age: ";
    std::cin >> num;
    vectorInt = addToEnd(vectorInt, num);
  }

  // vectorInt.erase(vectorInt.end() - 1);
  // удаление -1.
  vectorInt.pop_back();
  float averageAge{};
  for (const auto &i : vectorInt) averageAge += i;
  averageAge /= vectorInt.size();

  std::cout << "The average age of patients: " << averageAge;

  return 0;
}