/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 4.
 * Напишите рекурсивную функцию, которая принимает большое число n типа long
 * long и переменную ans, а возвращает void. После завершения работы функции в
 * переменной ans должно оказаться количество чётных цифр в записи числа n.
 * @version   0.1
 * @date      18-03-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>

#include "Timer.h"

using std::cin;
using std::cout;
using std::endl;

/**
 * @brief     Recursive method
 * @param     n             input number
 * @param     count         count of even numbers
 */
void isEven(int64_t n, int16_t& count) {
  if (!n) return;
  if (0 == (n & 1)) ++count;
  return isEven(n / 10, count);
}

/**
 * @brief     Iteration method
 * @param     n             input number
 * @return    int16_t       count of even numbers
 */
int16_t isEven(int64_t n) {
  int16_t count{};
  while (n) {
    if (0 == (n & 1)) ++count;
    n /= 10;
  }
  return count;
}

int main() {
  cout << "\x1b[2J";
  int64_t n{9223372036854775806};

  {
    cout << "Recursive even number count " << n << endl;
    int16_t count{};
    Timer t;
    isEven(n, count);
    cout << "Even numbers: " << count << endl;
    cout << "Time elapsed: " << t.elapsed() << endl;
  }
  cout << endl;

  {
    cout << "Iteration even number count: " << n << endl;
    Timer t;
    cout << "Even numbers: " << isEven(n) << endl;
    cout << "Time elapsed: " << t.elapsed() << endl;
  }

  return 0;
}