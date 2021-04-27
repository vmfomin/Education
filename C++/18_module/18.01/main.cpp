/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 1.
 * Напишите функцию swapvec, принимающую std::vector<int> и указатель на массив
 * переменных типа int (одного размера) и обменивающую значения этих массивов.
 * @version   0.1
 * @date      17-03-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

template <typename T>
void swap(vector<T>& v, T* ptr) {
  for (size_t i{}; i < v.size(); ++i) std::swap(v[i], *(ptr + i));
}

int main() {
  cout << "\x1b[2J";
  vector<int16_t> vec{1, 2, 3, 4};
  int16_t array[]{2, 4, 6, 8};
  cout << "Before:\n";
  for (const auto& i : vec) cout << i << " ";
  cout << endl;
  for (const auto& i : array) cout << i << " ";
  cout << "\n" << endl;

  swap(vec, array);
  cout << "After:\n";
  for (const auto& i : vec) cout << i << " ";
  cout << endl;
  for (const auto& i : array) cout << i << " ";
  cout << endl;

  return 0;
}