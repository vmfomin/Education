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
#include <limits>
#include <vector>

int32_t MaxSubArray(std::vector<int>& nums) {
  int32_t max_sum{INT_MIN};
  int32_t sum{};
  for (size_t i{}; i < nums.size(); ++i) {
    sum += nums[i];
    if (sum > max_sum) max_sum = sum;
    if (sum < 0) sum = 0;
  }

  return max_sum;
}

int main() {
  system("cls");
  std::vector<int32_t> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};

  std::cout << "Sum = " << MaxSubArray(nums) << ".\n";
}