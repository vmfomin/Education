/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 2.
 * Написать функцию, которая принимает указатель на тип int, по которому
 * размещены 10 переменных типа int. Функция должна вернуть другой указатель на
 * int, по которому лежат те же элементы, но в обратном порядке
 * @version   0.1
 * @date      17-03-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int* reverse(int* p_i, const size_t& length) {
  for (int i{}; i < length / 2; ++i)
    std::swap(*(p_i + i), *(p_i + length - i - 1));
  return p_i;
}

int main() {
  cout << "\x1b[2J";

  int array[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  size_t length{sizeof(array) / sizeof(array[0])};
  int* pArray{array};

  for (const auto& i : array) cout << i << " ";
  cout << endl;

  int* pReversedArray{reverse(pArray, length)};

  for (const auto& i : array) cout << i << " ";
  // ? Я похоже не правильно понял задачу, но что-то как-то смысла в возврате
  // ? указателя нет. Одно дело сохраняем один массив и в другой пишем.
  // ? Но раз надо -- значит надо.
  cout << "\npArray = " << *pArray << "\npReversedArray = " << *pReversedArray
       << endl;

  cout << "\x1b[0m" << endl;
  return 0;
}