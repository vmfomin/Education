/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 4. Равенство матриц.
 * Требуется реализовать небольшую программу для сравнения двух двумерных матриц
 * размерами 4х4 на предмет их полного равенства. Программа принимает на вход
 * две целочисленные матрицы A и B, которые вводятся с помощью std::cin и
 * сравнивает их на предмет полного равенства. Если матрицы равны, то об этом
 * сообщается в стандартном выводе. Алгоритм должен быть по возможности
 * оптимальным и не проводить лишних операций.
 * @version   0.1
 * @date      15-02-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <iterator>
#include <vector>

/**
 * @brief     writing the values of a vector of vectors
 * @param     vec           vector of int type vectors
 */
void inputVector(std::vector<std::vector<int>>& vec) {
  for (size_t i{}; i < vec.size(); ++i) {
    for (size_t j{}; j < vec.size(); ++j) {
      int temp;
      std::cin >> temp;
      vec[i].push_back(temp);
    }
  }
  std::cout << "\x1b[37m";
}

/**
 * @brief     output of a vector of vectors to the console
 * @param     vec           vector of int type vectors
 */
void outputVector(const std::vector<std::vector<int>>& vec) {
  std::cout << "\x1b[37m";
  for (auto iter{vec.begin()}; iter != vec.end(); ++iter) {
    std::copy((*iter).begin(), (*iter).end(),
              std::ostream_iterator<int>(std::cout, "\t"));
    std::cout << "\n";
  }
  std::cout << "\n";
}

int main() {
  std::cout << "\x1b[2J";

  std::cout << "Enter the first matrix:\x1b[32m\n";
  std::vector<std::vector<int>> first(4);
  inputVector(first);

  std::cout << "Enter the second matrix:\x1b[32m\n";
  std::vector<std::vector<int>> second(4);
  inputVector(second);

  std::cout << "The first matrix:\n";
  outputVector(first);
  std::cout << "The second matrix:\n";
  outputVector(second);

  std::cout << "\x1b[36m";
  std::cout << (first == second ? "Equal.\n" : "Not equal.\n");
  std::cout << "\x1b[37m";

  return 0;
}