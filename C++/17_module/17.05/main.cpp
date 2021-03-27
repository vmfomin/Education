/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 5. Диагональная матрица.
 * Задание. Для вещественной матрицы M размером 4х4 надо осуществить её
 * преобразование в диагональную. Напомню, что диагональная матрица — это такая
 * матрица, у которой все элементы вне диагонали равны нулю. Диагональ матрицы,
 * в свою очередь — это все элементы, расположенные по диагонали от первого
 * элемента первой строки до последнего элемента последней строки. Матрица M
 * вводится пользователем через стандартный ввод, как и раньше. Итоговую
 * диагональную матрицу можно расположить на месте прежней матрицы M, не
 * используя дополнительных переменных. Результат требуется вывести в консоль
 * для проверки. Ищите именно оптимальное решение — оно довольно простое.
 * @version   0.1
 * @date      15-02-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <iterator>
#include <vector>

/**
 * @brief     writing the values of a vector of vectors
 * @tparam    T             type of vector of vectors
 * @param     vec           vector of vectors
 */
template <typename T>
void inputVector(std::vector<std::vector<T>>& vec) {
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
 * @tparam    T             type of vector of vectors
 * @param     vec           vector of vectors
 */
template <typename T>
void outputVector(const std::vector<std::vector<T>>& vec) {
  std::cout << "\x1b[37m";
  for (auto iter{vec.begin()}; iter != vec.end(); ++iter) {
    std::copy(iter->begin(), iter->end(),
              std::ostream_iterator<T>(std::cout, " "));
    std::cout << "\n";
  }
  std::cout << "\n";
}

int main() {
  std::cout << "\x1b[2J";

  std::cout << "Enter the matrix:\x1b[32m\n";
  std::vector<std::vector<int>> matrix(4);
  inputVector(matrix);
  
  std::cout << "\x1b[2JThe matrix:\n";
  outputVector(matrix);

  for (size_t i{}; i < matrix.size(); ++i) {
    for (size_t j{}; j < matrix.size(); ++j) {
      if (i == j) continue;
      matrix[i][j] = 0;
    }
  }
  std::cout << "The diagonal matrix:\n";
  outputVector(matrix);

  std::cout << "\x1b[37m";

  return 0;
}