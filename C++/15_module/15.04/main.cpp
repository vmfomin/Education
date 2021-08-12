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

int main() {
  std::cout << "\x1b[2J";

  std::vector<int32_t> vec{-100, -50, -5, 1, 10, 15};
  std::cout << "Before sorting:\n";
  std::copy(vec.begin(), vec.end(),
            std::ostream_iterator<int32_t>(std::cout, " "));

  std::cout << "\n\nSorting with std::sort() and lambda expresion:\n";
  std::sort(vec.begin(), vec.end(),
            [](int32_t a, int32_t b) { return std::abs(a) < std::abs(b); });
  std::copy(vec.begin(), vec.end(),
            std::ostream_iterator<int32_t>(std::cout, " "));

  std::cout << "\n";
}