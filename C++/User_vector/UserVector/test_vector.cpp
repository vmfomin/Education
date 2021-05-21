/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     User vector test
 * @version   0.1
 * @date      20-05-2021
 * @copyright Copyright (c) 2021
 */

#include "UserVector.h"

int main() {
  system("cls");

  std::cout << "Enter vector size: ";
  size_t size;
  std::cin >> size;
  UserVector user_v(size);

  std::cout << "Enter values of vector: ";
  for (size_t i{}; i < user_v.size(); ++i) std::cin >> user_v[i];
  std::cout << "Your vector: " << user_v << "\n";
  std::cout << "Vectors normalize: " << user_v.normalize() << "\n";

  UserVector user_initList_v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << "\nVector with std::initializer_list: " << user_initList_v
            << "\n";
  std::cout << "Vectors normalize: " << user_initList_v.normalize() << "\n";

  user_initList_v.push_back(2000);
  std::cout << "push_back 2000\n";
  user_initList_v.push_back(5000);
  std::cout << "push_back 5000\n";
  std::cout << user_initList_v << "\n";

  user_initList_v.pop_back();
  std::cout << user_initList_v << " pop_back\n";

  UserVector user_v_copy(user_initList_v);
  std::cout << "\nVector as a copy of user_initList_v: " << user_v_copy << "\n";
  std::cout << "Vectors normalize: " << user_v_copy.normalize() << "\n";

  user_v_copy.push_back(10000);
  std::cout << "push_back 10000\n";
  user_v_copy.push_back(100500);
  std::cout << "push_back 100500\n";

  UserVector user_v_move(std::move(user_v_copy));
  std::cout << "\nVector as std::move of user_v_copy: " << user_v_move << "\n";
  std::cout << "Vectors normalize: " << user_v_move.normalize() << "\n";

  return 0;
}
