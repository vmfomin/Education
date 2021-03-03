/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 2
 * Вам даётся массив целых чисел и одно число -- результат. Необходимо найти в
 * массиве 2 числа, сумма которых будет давать результат, и вывести их на экран.
 * Гарантируется, что только одна пара чисел в массиве даёт в сумме результат.
 * Пример:
 * a = {2, 7, 11, 15}. Результат = 9
 * 2 + 7 = 9, так что надо вывести числа 2 и 7
 * @version   0.1
 * @date      03-03-2021
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

/**
 * @brief     The sum of two digits in the array
 * @tparam    T             type of vector
 * @param     vec           vector<T>
 * @param     result        the sum need to find
 */
template <typename T>
void sumTwoDigitsInArray(const vector<T>& vec, const T& result) {
  for (size_t i{}; i < vec.size() - 1; ++i)
    for (size_t j{i + 1}; j < vec.size(); ++j)
      if (vec[i] + vec[j] == result) {
        cout << vec[i] << " + " << vec[j] << " = " << result << "\n";
        return;
      }
  cout << "No matching condition found!\n";
}

int main() {
  cout << "\x1b[2J";

  vector<int32_t> vec_1{11, 15, 2, 7};
  int32_t result_1{9};
  cout << "vec_1: ";
  sumTwoDigitsInArray(vec_1, result_1);

  vector<int32_t> vec_2{11, 15, 2, 3};
  int32_t result_2{7};
  cout << "vec_2: ";
  sumTwoDigitsInArray(vec_2, result_2);

  vector<double> vec_3{11.5, 2.5, 110.1, 2.45, 2.44, 3.175, 22.3};
  double result_3{5.615};
  cout << "vec_3: ";
  sumTwoDigitsInArray(vec_3, result_3);

  cout << "\n";

  return 0;
}