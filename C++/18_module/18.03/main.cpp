/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 3.
 * Кролик сидит на нулевой ступеньке большой лестницы. Он может прыгать на одну
 * или более ступенек вверх, но не далее чем на k. Кролик хочет допрыгать до n-й
 * ступеньки, но может сделать это большим количеством способов. Напишите
 * рекурсивную функцию, которая принимает число n типа int и число k —
 * максимальную длину прыжка, а возвращает количество способов, которым кролик
 * может доскакать до n-й ступеньки. Если максимальная длина прыжка не задана —
 * считать её равной трём.
 * @version   0.1
 * @date      17-03-2021
 * @copyright Copyright (c) 2021
 */

#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int rabbitStep(int32_t n, int32_t k = 3) {
  if (0 == n) return 1;
  int countSteps{};
  for (int i{1}; i <= std::min(n, k); ++i) countSteps += rabbitStep(n - i, k);
  return countSteps;
}

int main() {
  cout << "\x1b[2J";
  cout << "Enter the number of steps: ";
  int32_t n;
  cin >> n;
  n = std::abs(n);
  cout << "Number of ways with default k:\t" << rabbitStep(n) << endl;
  cout << endl;
  
  cout << "Enter max step: ";
  int32_t k;
  cin >> k;
  cout << "Number of ways with k = " << k << ":\t" << rabbitStep(n, k) << endl;

  cout << endl;
  return 0;
}