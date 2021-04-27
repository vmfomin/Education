/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Solving the gcd by the recurrent and iterative method
 * @version   0.1
 * @date      18-03-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>

#include "Timer.h"

using std::cin;
using std::cout;
using std::endl;

int64_t gcd(int64_t a, int64_t b) {
  while (b) {
    a %= b;
    std::swap(a, b);
  }
  return a;
}

int64_t fast_gcd(int64_t a, int64_t b) { return !b ? a : fast_gcd(b, a % b); }

int main() {
  cout << "\x1b[2J";
  int64_t n, m;
  cout << "Enter the numbers for gdc: ";
  cin >> n >> m;

  {
    cout << "Iteration gcd:\t";
    Timer t;
    int64_t devisor{gcd(n, m)};
    cout << n / devisor << "/" << m / devisor << endl;
    cout << "Time elapsed: " << t.elapsed() << endl;
  }
  cout << endl;
  {
    cout << "Recursive gcd:\t";
    Timer t;
    int64_t devisor{fast_gcd(n, m)};
    cout << n / devisor << "/" << m / devisor << endl;
    cout << "Time elapsed: " << t.elapsed() << endl;
  }
  return 0;
}
