/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 3.
 * Написать функцию, которая принимаем указатель на char, по которому лежит
 * строка. Функция должна возвращать true, если вторая строка является
 * подстрокой первой.
 * @version   0.1
 * @date      17-03-2021
 * @copyright Copyright (c) 2021
 */

#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/**
 * @brief     substring search
 * @param     str           string
 * @param     sub           substring
 * @return    true          substring found
 * @return    false
 */
bool substr(char* str, char* sub) {
  int subpos{};
  int i{};
  while (*(str + i) != '\0') {
    if (*(str + i) == *sub) {
      ++sub;
      ++subpos;
      if ('\0' == *sub) return true;
    } else if (subpos != 0) {
      sub -= subpos;
      subpos = 0;
    }
    ++i;
  }
  return false;
}

int main() {
  cout << "\x1b[2J";
  char a[]{"Hello world!!  !!!"};
  char b[]{"wor"};
  char c[]{"banana"};
  char d[]{"o w"};
  char e[]{"! "};
  char f[]{"!!!"};
  char g[]{"h"};

  cout << std::boolalpha;
  cout << a << " \"" << b << "\" \t" << substr(a, b) << "\n"
       << a << " \"" << c << "\" \t" << substr(a, c) << "\n"
       << a << " \"" << d << "\" \t" << substr(a, d) << "\n"
       << a << " \"" << e << "\" \t" << substr(a, e) << "\n"
       << a << " \"" << f << "\" \t" << substr(a, f) << "\n"
       << a << " \"" << g << "\" \t\t" << substr(a, g) << "\n";

  cout << "\x1b[0m" << endl;
  return 0;
}