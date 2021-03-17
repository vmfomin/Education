/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 2.
 * Написать функцию, которая принимает указатель на тип int, по которому
 * размещены 10 переменных типа int. Функция должна вернуть элементы в обратном
 * порядке
 * @version   0.1
 * @date      17-03-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/**
 * @brief     Reverse array function
 * @tparam    T             type of array
 * @param     ptr           pointer to an array
 * @param     length        array length
 */
template <typename T>
void reverse(T* ptr, const size_t& length) {
  for (int i{}; i < length / 2; ++i)
    std::swap(*(ptr + i), *(ptr + length - i - 1));
}

int main() {
  cout << "\x1b[2J";
  const size_t sizeArray{10};
  int16_t* pArray{new int16_t[sizeArray]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};

  for (size_t i{}; i < sizeArray; ++i) cout << *(pArray + i) << " ";
  cout << endl;

  reverse(pArray, sizeArray);

  for (size_t i{}; i < sizeArray; ++i) cout << *(pArray + i) << " ";
  cout << endl;
  cout << "pArray = " << *pArray;

  delete[] pArray;
  pArray = nullptr;

  cout << "\x1b[0m" << endl;
  return 0;
}