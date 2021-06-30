/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 1.
 * Написать функцию, принимающую два указателя на int и меняет местами
 * содержимое данных указателей.
 * @version   0.1
 * @date      16-03-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <memory>

#include "Timer.h"

using std::cin;
using std::cout;
using std::endl;

template <typename T>
void swap(T* a, T* b) {
  T temp = std::move(*a);
  *a = std::move(*b);
  *b = std::move(temp);
}

int main() {
  cout << "\x1b[2J";

  int* a{new int{15}};
  int* b{new int{7}};
  cout << "Before:\n";
  cout << "a = " << *a << "; b = " << *b << "\n" << endl;

  {
    cout << "After user swap:\n";
    Timer t;  // Measuring the execution time (timing) of the code
    swap(a, b);
    cout << "a = " << *a << "; b = " << *b << endl;
    cout << "Time elapsed: " << t.elapsed() << "\n" << endl;
  }

  {
    cout << "After std::swap:\n";
    Timer t;  // Measuring the execution time (timing) of the code
    std::swap(a, b);
    cout << "a = " << *a << "; b = " << *b << endl;
    cout << "Time elapsed: " << t.elapsed() << "\n" << endl;
  }

  a = nullptr;
  b = nullptr;

  return 0;
}
