/**
 * @file main.cpp
 * @author vmf0min (vlifom@yandex.ru)
 * @brief Задание 3. Роботы и коррупция*
 * Улучшите электронную очередь для роботов. К нам приходят роботы разного
 * социального статуса. Каждый робот вводит не только свой уникальный номер, но
 * и свое место в очереди. Например, пусть в нашей очереди 10 роботов и к нам
 * приходит 11-й. Сначала он вводит свой номер, как и раньше, а затем свое место
 * в очереди - например, 5. В этом случае он должен оказаться в очереди пятым, а
 * все остальные, начиная со старого пятого - подвинуться дальше в конец
 * очереди.
 * Реализуйте функцию
 * std::vector<int> add_to_position(std::vector vec, int val, int position)
 * @version 0.2
 * @date 18-01-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <vector>

/**
 * @brief Добавление в вектор нового значения в указанную позицию.
 * @param vecIn вектор, который надо изменить.
 * @param val значение для вектора.
 * @param pos позиция в очереди.
 * @return std::vector<int> новый вектор с измененным значением.
 */
std::vector<int> add_to_possition(const std::vector<int> &vecIn, const int &val,
                                  const int &pos) {
  std::vector<int> newVec(vecIn.size() + 1);
  // Копирование в новый вектор до текущей позиции.
  std::copy(vecIn.begin(), vecIn.begin() + pos, newVec.begin());

  // Добавление значения в вектор на указанную позицию.
  newVec[pos] = val;

  // Копирование остатка.
  std::copy(vecIn.begin() + pos, vecIn.end(), &newVec[pos + 1]);

  return newVec;
}

int main() {
  std::cout << "\e[2JValues in the vector: ";
  std::vector<int> vectorInt{3, 5, 7, 10, 11, 12};
  for (const auto &i : vectorInt) std::cout << i << " ";
  std::cout << "\n";

  int num{};
  size_t queue{};
  while (true) {
    std::cout << "Enter your registration index: ";
    std::cin >> num;
    if (num == -1) break;

    std::cout << "Enter your place in the queue: ";
    std::cin >> queue;

    if (0 == queue)
      std::cout
          << "The queue starts at 1.\nYou were directed to the end of the "
             "queue.\n";
    --queue;

    // Если ввести отрицательный индекс, то добавит в конец очереди.
    if (queue > vectorInt.size()) {
      std::cout << "You're the last one in line.\n";
      queue = vectorInt.size();
    }

    vectorInt = add_to_possition(vectorInt, num, queue);

    for (const auto &i : vectorInt) std::cout << i << " ";
    std::cout << "\n\n";
  }

  std::cout << "The queue is finished\n";
  return 0;
}