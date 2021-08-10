/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Pow
 * @version   0.1
 * @date      29-07-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>

template <typename T>
constexpr T pow(T x, uint64_t n) {
  if (n == 0) return static_cast<T>(1);
  if (n & 1) return pow(x, n - 1) * x;
  T y{pow(x, n / 2)};
  return y * y;
}

int main() {
  system("cls");

  std::cout << pow(2l, 12) << std::endl;

  return 0;
}
