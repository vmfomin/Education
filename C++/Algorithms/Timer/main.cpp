/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Measuring the execution time (timing) of the code
 * @version   0.1
 * @date      02-03-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>

#include "Timer.h"

using std::cout;

int main() {
  cout << "\x1b[2J";

  Timer t;

  cout << "\nTime elapsed: " << t.elapsed() << "\n";

  cout << "\x1b[37m" << std::endl;

  return 0;
}