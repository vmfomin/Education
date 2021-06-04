/**
 * @file main.cpp
 * @author vmf0min (vlifom@yandex.ru)
 * @brief Задача 1.
 * Пользователь вводит с клавиатуры число n, далее -- n целых чисел, которые
 * нужно записать в вектор. Потом пользователь вводит ещё одно значение. Нужно
 * удалить из вектора все элементы, которые равны данному значению, и вывести
 * итоговое состояние вектора Пример: Пользователь ввёл 5, потом числа 1, 3, 3,
 * 5, 1. И потом -- число 3. Необходимо, чтобы в векторе остались числа 1, 5, 1,
 * которые надо вывести их на экран.
 * @version 0.1
 * @date 22-01-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <vector>

int main() {
  std::cout << "\e[2J\e[37mHow many integers? ";
  int num;
  std::cin >> num;

  // Объявление вектора.
  std::vector<int> vectorInt(num);

  std::cout << "Enter the numbers in the vector: ";
  for (auto &vec : vectorInt) std::cin >> vec;

  // Чтобы вывести на экран 2 вида решения.
  std::vector<int> tempVector(vectorInt);

  std::cout << "Enter which number should be erased? ";
  int eraseNumber;
  std::cin >> eraseNumber;

  std::cout << "\e[32mErased by simple algorithm: ";
  auto iterOut{vectorInt.begin()};
  for (auto i{vectorInt.begin()}; i != vectorInt.end(); ++i)
    if (*i != eraseNumber) std::swap(*(iterOut++), *i);
  vectorInt.resize(vectorInt.size() - (vectorInt.end() - iterOut));

  for (const auto &vec : vectorInt) std::cout << vec << " ";

  vectorInt = tempVector;  // Возвращаем исходные значения.

  std::cout << "\nErased by C++20:\t    ";
  std::erase(vectorInt, eraseNumber);

  for (const auto &vec : vectorInt) std::cout << vec << " ";

  std::cout << "\e[37m\n";

  return 0;
}