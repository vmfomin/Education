/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 3
 * С клавиатуры вводятся числа. Когда пользователь вводит -1 -- необходимо
 * выводить на экран пятое по возрастанию число среди введённых. Когда
 * пользователь вводит -2 -- программа завершает работу.
 * Пример:
 * ввод: 7 5 3 1 2 4 6 -1
 * вывод: 5 (в отсортированном виде массив выглядит так: {1,2,3,4,5,6,7})
 * ввод: 1 1 1 -1
 * вывод: 2 (в отсортированном виде массив выглядит так: {1,1,1,1,2,3,4,5,6,7})
 * ввод -2
 * завершение программы
 * @version   0.1
 * @date      03-03-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <vector>

/**
 * @brief     Quick sorting
 * @tparam    T             Input class
 * @param     array         sorting vector
 * @param     last          length of part
 * Реализовал для практики через итератор на вход.
 */
template <class T>
void quickSort(T array, int64_t last) {
  int64_t i{};
  int64_t j{last};
  auto pivot = *(array + (last >> 1));

  while (i <= j) {
    while (*(array + i) < pivot) ++i;
    while (*(array + j) > pivot) --j;
    if (i <= j) std::swap(*(array + i++), *(array + j--));
  }
  if (j > 0) quickSort(array, j);
  if (last > i) quickSort(array + i, last - i);
}

int main() {
  using std::cout;
  using std::vector;
  cout << "\x1b[2J";

  vector<int32_t> vec;
  cout << "Enter numbers: ";
  do {
    int32_t temp;
    std::cin >> temp;
    if (-1 == temp && vec.size() > 4) {
      quickSort(vec.begin(), vec.size() - 1);
      cout << "number at index [4]: " << vec[4] << "\n";
      cout << "Enter numbers: ";
      continue;
    }

    if (-2 == temp) {
      cout << "Shutdown\n";
      break;
    }

    if (temp != -1) vec.push_back(temp);
  } while (true);

  cout << "\n";

  return 0;
}