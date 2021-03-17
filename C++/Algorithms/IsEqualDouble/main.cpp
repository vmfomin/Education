/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     comparison of fractional numbers
 * @version   0.1
 * @date      02-03-2021
 * @copyright Copyright (c) 2021
 */

#include <iomanip>
#include <iostream>
#include <iterator>
#include <vector>

using std::cout;
using std::vector;

/**
 * @brief     comparison of fractional numbers
 * @param     a             first number
 * @param     b             second number
 * @param     absEpsilon    absolute epsilon
 * @param     relEpsilon    relative epsilon
 * @return    true          equal
 */
bool isEqualFloat(double a, double b, double absEpsilon = 1e-12,
                  double relEpsilon = 1e-8) {
  using std::abs;
  double diff = abs(a - b);
  if (diff <= absEpsilon) return true;

  // Knuth algorithm
  return diff <= ((abs(a) < abs(b) ? abs(b) : abs(a)) * relEpsilon);
}

int main() {
  cout << "\x1b[2J";

  double a = 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1;

  cout << "isEqualFloat algorithm: " << std::boolalpha
       << isEqualFloat(a - 1.0, 0.0) << "\n ";

  cout << "\x1b[37m" << std::endl;

  return 0;
}