/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     User vector test
 * @version   0.1
 * @date      20-05-2021
 * @copyright Copyright (c) 2021
 */

#include "UserVector2.h"

int main() {
  system("cls");

  std::cout << "Enter vector size: ";
  size_t size;
  std::cin >> size;
  UserVector2 user_v2(size);
  for (size_t i{}; i < user_v2.size(); ++i) {
    size_t size{user_v2.size() + i};
    for (size_t j{}; j < size; ++j) user_v2[i].push_back(i * j + 1);
  }
  for (size_t i{}; i < user_v2.size(); ++i) std::cout << user_v2[i] << "\n";
  std::cout << std::endl;

  std::cout << "vector of vectors with initializer list:\n";
  UserVector2 user_initList_v2{{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                               {5, 6, 7, 8, 9, 10},
                               {2, 3, 100, 10, 20, 13}};

  for (size_t i{}; i < user_initList_v2.size(); ++i)
    std::cout << user_initList_v2[i]
              << " normalize = " << user_initList_v2[i].normalize() << "\n";
  std::cout << std::endl;

  std::cout << "Push back 2 vectors:\n";
  UserVector v{3, 4, 2, 1, -1, -1, -1, 7, 8, 10};
  user_initList_v2.push_back(v);
  v[3] = -1050;
  user_initList_v2.push_back(v);
  for (size_t i{}; i < user_initList_v2.size(); ++i)
    std::cout << user_initList_v2[i]
              << " normalize = " << user_initList_v2[i].normalize() << "\n";
  std::cout << std::endl;

  std::cout << "1 pop back\n";
  user_initList_v2.pop_back();
  for (size_t i{}; i < user_initList_v2.size(); ++i)
    std::cout << user_initList_v2[i]
              << " normalize = " << user_initList_v2[i].normalize() << "\n";
  std::cout << std::endl;

  std::cout << "sorting\n";
  user_initList_v2.sort();
  for (size_t i{}; i < user_initList_v2.size(); ++i)
    std::cout << user_initList_v2[i]
              << " normalize = " << user_initList_v2[i].normalize() << "\n";
  std::cout << std::endl;

  return 0;
}
