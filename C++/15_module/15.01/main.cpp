/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 1
 * Вам даётся массив целых чисел. Необходимо найти такие два индекса i и j в
 * этом массиве, что сумма a[i], a[i+1], a[i+2], … a[j] будет максимально
 * возможной и вывести их.
 * Пример:
 * a = {-2,1,-3,4,-1,2,1,-5,4}
 * Тогда наибольшая сумма последовательных элементов находится между индексами 3
 * и 6: {4,-1,2,1}, сумма = 6. Необходимо вывести 3 и 6
 * @version   0.1
 * @date      03-03-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <vector>

int main() {
  using std::cout;
  using std::vector;
  cout << "\x1b[2J";

  vector<int> vec{-2, 1, -3, 4, -1, 2, 1, -5, 4};

  int maxSum{};
  int indexStart{};
  int indexEnd{};
  for (int i{}; i < vec.size(); ++i) {
    for (int j{}; j < vec.size() - i; ++j) {
      int sum{};
      for (int k{j}; k <= vec.size() - i; ++k) sum += vec[k];
      if (sum > maxSum) {
        maxSum = sum;
        indexStart = j;
        indexEnd = vec.size() - i;
      }
    }
  }

  cout << "Start index = " << indexStart << ". End index = " << indexEnd
       << ". Sum = " << maxSum << ".\n";

  return 0;
}