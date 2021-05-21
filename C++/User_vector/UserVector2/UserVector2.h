/**
 * @file      UserVector2.h
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     User class of vector of vectors
 * @version   0.1
 * @date      20-05-2021
 * @copyright Copyright (c) 2021
 */

#ifndef _INC_USER_VECTOR_2_H_
#define _INC_USER_VECTOR_2_H_

#include "UserVector.h"

class UserVector2 {
 public:
  UserVector2() : size_{}, vector2_{} {}
  explicit UserVector2(size_t size)
      : size_{size}, vector2_{new UserVector[size_]} {}
  UserVector2(char size) = delete;
  UserVector2(const std::initializer_list<UserVector>& list)
      : UserVector2(list.size()) {
    size_t i{};
    for (auto& element : list) {
      vector2_[i] = element;
      ++i;
    }
  }

  size_t size() const { return size_; }

  auto& operator[](const size_t index) { return vector2_[index]; }
  const auto& operator[](const size_t index) const { return vector2_[index]; }

  /**
   * @brief     Destroy the User Vector 2 object
   *
   */
  ~UserVector2() {
    delete[] vector2_;
    vector2_ = nullptr;
  }

  void sort();

  void push_back(UserVector& vec) {
    UserVector* tmp{new UserVector[++size_]};
    if (tmp == nullptr) return;

    for (size_t i{}; i < size_ - 1; ++i) tmp[i] = vector2_[i];
    tmp[size_ - 1] = vec;
    delete[] vector2_;
    vector2_ = tmp;
  }

  void pop_back() {
    UserVector* tmp{new UserVector[--size_]};
    if (tmp == nullptr) return;

    for (size_t i{}; i < size_; ++i) tmp[i] = vector2_[i];
    delete[] vector2_;
    vector2_ = tmp;
  }

 private:
  size_t size_;
  UserVector* vector2_;
};

#endif  // _INC_USER_VECTOR_2_H_