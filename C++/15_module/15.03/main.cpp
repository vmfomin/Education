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

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::cout << "\x1b[2J";

  std::vector<int32_t> vec;
  std::cout << "Enter numbers: ";
  do {
    int32_t temp;
    std::cin >> temp;
    if (-1 == temp && vec.size() > 4) {
      std::sort(vec.begin(), vec.end());
      std::cout << "number at index [4]: " << vec[4] << "\n";
      std::cout << "Enter numbers: ";
      continue;
    }

    if (-2 == temp) {
      std::cout << "Shutdown\n";
      break;
    }

    if (temp != -1) vec.push_back(temp);
  } while (true);

  std::cout << std::endl;
}