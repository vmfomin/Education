/**
 * @file main.cpp
 * @author vmf0min (vlifom@yandex.ru)
 * @brief Задача 3.
 * В базу данных, являющуюся вектором, с клавиатуры приходят целочисленные
 * значения, и помещаются в конец. Однако, эта база может хранить только 20
 * элементов, а дальше необходимо будет удалять элементы, которые лежат в базе
 * дольше всех.
 * При вводе -1 с клавиатуры необходимо вывести всё содержимое базы данных (то
 * есть 20 или менее элементов). При выводе элементы должны быть в том порядке,
 * в котором они добавлялись в базу данных. Попробуйте написать максимально
 * оптимизированное решение данной задачи, чтобы совершалось как можно меньше
 * расширений и перемещений элементов внутри вектора.
 * @version 0.1
 * @date 25-01-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <vector>

int main() {
  std::cout << "\e[2J";
  std::vector<int> vectorInt;

  int num{};
  while (true) {
    std::cout << "\e[37mEnter the numbers in the vector: \e[32m";
    std::cin >> num;
    std::cout << "\e[37m";

    if (-1 == num) {
      if (vectorInt.empty()) {
        std::cout << "\e[31mThe vector is empty!\e[37m\n";
        continue;
      }

      std::cout << "All elements of the vector: \e[32m";
      for (const auto& vec : vectorInt) std::cout << vec << " ";
      std::cout << "\e[37m";
      break;
    }

    if (vectorInt.size() < 20) {
      vectorInt.push_back(num);
    } else {
      vectorInt.erase(vectorInt.begin());
      vectorInt.push_back(num);
      vectorInt.shrink_to_fit();
    }
  }

  std::cout << "\n";

  return 0;
}