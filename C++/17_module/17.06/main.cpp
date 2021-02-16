/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 6. Умножение матрицы на вектор.
 * Реализуйте частный случай умножения матрицы на матрицу, а именно — умножение
 * вектора на матрицу. Данная операция также весьма распространена в
 * компьютерной индустрии в целом и в компьютерное графике в частности, поэтому
 * это будет хорошим упражнением.
 * Итак, у нас есть 4-х компонентный вектор V представленный с помощью массива,
 * и матрица M размером 4х4, представленная в виде двумерного массива. Их
 * произведением будет новый 4-х компонентный вектор R. Его компоненты будут
 * суммой произведений компонент вектора V на строку матрицы M. Индекс столбца
 * при этом равен индексу соответствующей компоненты вектора R, который мы и
 * рассчитываем в текущий момент времени.
 * Все входные данные, матрица M и вектор V вносятся из пользовательского ввода.
 * Итоговый вектор R надо вывести в консоль (std::cout). Тип данных элементов -
 * всегда float. Желательно реализовать этот алгоритм с помощью вложенного цикла
 * на умножение колонки.
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
    std::copy((*iter).begin(), (*iter).end(),
              std::ostream_iterator<T>(std::cout, " "));
    std::cout << "\n";
  }
  std::cout << "\n";
}

int main() {
  std::cout << "\x1b[2J";

  std::cout << "Enter the matrix:\x1b[32m\n";
  std::vector<std::vector<float>> matrix(4);
  inputVector(matrix);

  std::cout << "Enter the vector:\x1b[32m\n";
  std::vector<float> v(4);
  for (auto& i : v) std::cin >> i;

  // Results
  std::cout << "\x1b[37m\x1b[2JMatrix:\n";
  outputVector(matrix);

  std::cout << "Vector:\n";
  for (const auto& i : v) std::cout << i << "\t";

  std::vector<float> resultVector;
  for (size_t i{}; i < matrix.size(); ++i) {
    float result{};
    for (size_t j{}; j < matrix.size(); ++j) result += matrix[i][j] * v[j];
    resultVector.push_back(result);
  }

  std::cout << "\n\nMultiplying a matrix by a vector:\x1b[36m\n";
  for (const auto& i : resultVector) std::cout << i << "\t";

  std::cout << "\x1b[37m";

  return 0;
}