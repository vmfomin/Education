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

  size_t size() const { return size_; }

  auto& operator[](const size_t index) { return vector2_[index]; }
  const auto& operator[](const size_t index) const { return vector2_[index]; }

  /**
   * @brief     Destroy the User Vector object
   */
  ~UserVector2();

  void push_back();  // TODO push_back()

  void pop_back();  // TODO pop_back()

 private:
  size_t size_;
  int32_t* vector2_;
};

std::ostream& operator<<(std::ostream& out, const UserVector2& userVector);

#endif  // _INC_USER_VECTOR_2_H_