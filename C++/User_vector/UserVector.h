/**
 * @file      UserVector.h
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     User class of vector
 * @version   0.1
 * @date      20-05-2021
 * @copyright Copyright (c) 2021
 */

#ifndef _INC_USER_VECTOR_H_
#define _INC_USER_VECTOR_H_

#include <cassert>
#include <cmath>
#include <iostream>

class UserVector {
 public:
  UserVector() : size_{}, vector_{nullptr} {}
  UserVector(size_t size);
  UserVector(char size) = delete;
  UserVector(const UserVector& other);
  UserVector(UserVector&& other);
  UserVector(const std::initializer_list<int32_t>& list)
      : UserVector(list.size()) {
    size_t i{};
    for (auto& element : list) {
      vector_[i] = element;
      ++i;
    }
  }

  size_t size() const { return size_; }

  double normalize() {
    int32_t sum{};
    for (int32_t i{}; i < size_; ++i) sum += vector_[i] * vector_[i];
    return std::sqrt(sum);
  }

  auto& operator[](const size_t index) {
    assert(index >= 0 && index < size_);
    return vector_[index];
  }
  const auto& operator[](const size_t index) const {
    assert(index >= 0 && index < size_);
    return vector_[index];
  }

  /**
   * @brief     Destroy the User Vector object
   */
  ~UserVector() {
    delete[] vector_;
    vector_ = nullptr;
  }

  void push_back(int32_t value) {
    int32_t* newVector{new int32_t[++size_]};
    for (size_t i{}; i < size_ - 1; ++i) newVector[i] = vector_[i];
    newVector[size_ - 1] = value;
    delete[] vector_;
    vector_ = newVector;
  }

  void pop_back() {
    int32_t* newVector{new int32_t[--size_]};
    for (size_t i{}; i < size_; ++i) newVector[i] = vector_[i];
    delete[] vector_;
    vector_ = newVector;
  }

 private:
  size_t size_;
  int32_t* vector_;
};

std::istream& operator>>(std::istream& in, const UserVector& userVector);
std::ostream& operator<<(std::ostream& out, const UserVector& userVector);

#endif  // _INC_USER_VECTOR_H_