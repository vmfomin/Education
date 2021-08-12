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
#include <unordered_map>
#include <vector>

std::pair<size_t, size_t> SumTwoDigitsInArray(const std::vector<int32_t>& vec,
                                              const int32_t target) {
  std::unordered_map<int32_t, size_t> hash_map;
  std::pair<size_t, size_t> ans;

  for (size_t i{}; i < vec.size(); ++i) {
    auto iter{hash_map.find(target - vec[i])};
    if (iter != hash_map.end()) ans = std::make_pair(iter->second, i);
    hash_map[vec[i]] = i;
  }
  return ans;
}

int main() {
  system("cls");

  std::vector<int32_t> vec{11, 2, 15, 13, 7, 12};
  int32_t result{9};
  auto ans{SumTwoDigitsInArray(vec, result)};

  std::cout << ans.first << " " << ans.second << "\n";
}