/**
 * @file Email_Errors.cpp
 * @author vmf0min (vlifom@yandex.ru)
 * @brief Ошибки в email адресах.
 * @version 0.1
 * @date 27-01-2021
 * @copyright Copyright (c) 2021
 */

#include "Email_Errors.h"

Email_Errors::Email_Errors(std::vector<std::string>& emails) {
  for (auto i{emails.begin()}; i != emails.end(); ++i) {
    std::string email{*i};
    Email_Errors error(email);

    std::cout << error.getEmail() << "  ";
    if (!error.testEmail()) std::cout << "\e[32mYes\e[37m\n";
  }
}

bool Email_Errors::testEmail() {
  if (findSpace()) {
    std::cout << getErrorStr(ERROR_SPACE);
    return true;
  }

  if (findDotAtFirstPosition()) {
    std::cout << getErrorStr(ERROR_FIRST_DOT_IN_EMAIL);
    return true;
  }

  if (findDotsInARow()) {
    std::cout << getErrorStr(ERROR_TWO_DOTS_IN_ROW);
    return true;
  }

  if (countAtInEmail()) {
    std::cout << getErrorStr(ERROR_AT_IN_EMAIL);
    return true;
  }

  size_t positionPart{};
  if (computeLength(positionPart, 64)) {
    std::cout << getErrorStr(ERROR_LENGTH_1);
    return true;
  }

  if (computeLength(positionPart, 63)) {
    std::cout << getErrorStr(ERROR_LENGTH_2);
    return true;
  }

  return false;
}

bool Email_Errors::computeLength(size_t& pos, const size_t& lengthPart) {
  int count{};
  for (auto i{email_.begin() + pos}; i != email_.end(); ++i) {
    count = static_cast<int>(i - email_.begin() - pos);

    if (('@' == *i || email_.end() - 1 == i) && count < lengthPart) {
      pos = ++count;
      return false;
    }
  }
  return true;
}
