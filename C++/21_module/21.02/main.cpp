/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 2.
 * Кролик сидит на нулевой ступеньке большой лестницы. Он может прыгать на 1, 2
 * или 3 ступеньки вверх. Кролик хочет допрыгать до n-й ступеньки, но может
 * сделать это большим количеством способов.
 * Напишите рекурсивную функцию, которая принимает число n типа int, а
 * возвращает количество способов, которыми кролик может доскакать до n-й
 * ступеньки.
 * @version   0.1
 * @date      17-03-2021
 * @copyright Copyright (c) 2021
 */

#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int rabbitStep(int32_t n) {
  if (0 == n) return 1;
  int countSteps{};
  for (int i{1}; i <= std::min(n, 3); ++i) countSteps += rabbitStep(n - i);
  return countSteps;
}

int main() {
  cout << "\x1b[2J";
  cout << "Enter the number of steps: ";
  int32_t n;
  cin >> n;
  n = std::abs(n);
  cout << "Number of ways: " << rabbitStep(n) << endl;

  cout << endl;
  return 0;
}