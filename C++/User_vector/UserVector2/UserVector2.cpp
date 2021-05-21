/**
 * @file      UserVector2.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     User class of vector of vectors
 * @version   0.1
 * @date      20-05-2021
 * @copyright Copyright (c) 2021
 */

#include "UserVector2.h"

void UserVector2::sort() {
  for (size_t i{}; i < size_; ++i) {
    for (size_t j{}; j < size_ - i - 1; ++j) {
      double norm_1{vector2_[j].normalize()};
      double norm_2{vector2_[j + 1].normalize()};
      if (norm_1 > norm_2) {
        UserVector* tmp{new UserVector[size_]};
        for (size_t k{}; k < size_; ++k) {
          if (vector2_[k].normalize() == norm_1) {
            tmp[k] = vector2_[j + 1];
            continue;
          }
          if (vector2_[k].normalize() == norm_2) {
            tmp[k] = vector2_[j];
            continue;
          }
          tmp[k] = vector2_[k];
        }
        delete[] vector2_;
        vector2_ = tmp;
      }
    }
  }
}