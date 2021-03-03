/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 4
 * Вам даётся массив целых чисел, отсортированных по возрастанию. Необходимо
 * вывести его на экран отсортированным в порядке возрастания модуля чисел
 * Пример:
 * Массив {-100,-50, -5, 1, 10, 15}
 * Вывод: 1, -5, 10, 15, -50, -100
 * Задание со звёздочкой: оптимизировать решение четвёртой задачи, чтобы оно
 * совершало как можно меньше операций
 * @version   0.1
 * @date      03-03-2021
 * @copyright Copyright (c) 2021
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

/**
 * @brief     Quick sorting with using abs
 * @tparam    T             Input class
 * @param     array         sorting vector
 * @param     last          length of part
 */
template <class T>
void quickSort(T array, int64_t last) {
  int64_t i{};
  int64_t j{last};
  auto pivot = std::abs(*(array + (last >> 1)));

  while (i <= j) {
    while (std::abs(*(array + i)) < pivot) ++i;
    while (std::abs(*(array + j)) > pivot) --j;
    if (i <= j) std::swap(*(array + i++), *(array + j--));
  }
  if (j > 0) quickSort(array, j);
  if (last > i) quickSort(array + i, last - i);
}

int main() {
  using std::cout;
  using std::vector;
  cout << "\x1b[2J";

  vector<int32_t> vec{-100, -50, -5, 1, 10, 15};
  cout << "Before sorting:\n";
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<int32_t>(cout, " "));

  cout << "\n\nSorting with my quickSort() function:\n";
  vector<int32_t> vecQuickSort(vec);
  quickSort(vecQuickSort.begin(), vecQuickSort.size() - 1);
  std::copy(vecQuickSort.begin(), vecQuickSort.end(),
            std::ostream_iterator<int32_t>(cout, " "));

  cout << "\n\nSorting with std::sort() and lambda expresion:\n";
  vector<int32_t> vecLambda(vec);
  std::sort(vecLambda.begin(), vecLambda.end(),
            [](const int32_t& a, const int32_t& b) {
              return std::abs(a) < std::abs(b);
            });
  std::copy(vecLambda.begin(), vecLambda.end(),
            std::ostream_iterator<int32_t>(cout, " "));

  cout << "\n";

  return 0;
}