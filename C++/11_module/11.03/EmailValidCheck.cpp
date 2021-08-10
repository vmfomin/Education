/**
 * @file EmailValidCheck.cpp
 * @author vmf0min (vlifom@yandex.ru)
 * @brief Class check the e-mail address.
 * @version 0.1
 * @date 27-01-2021
 * @copyright Copyright (c) 2021
 */

#include "EmailValidCheck.h"

EmailValidCheck::EmailValidCheck(std::vector<std::string>& emails) {
  for (auto i{emails.begin()}; i != emails.end(); ++i) {
    std::string email{*i};
    EmailValidCheck error(email);

    std::cout << error.getEmail() << "  ";
    if (!error.testEmail()) std::cout << "\e[32mYes\e[37m\n";
  }
}

bool EmailValidCheck::testEmail() {
  if (findDotAtFirstPosition()) return true;

  if (computeLength()) {
    std::cout << "Error length";
    return true;
  }

  if (countAtInEmail()) {
    std::cout << getErrorStr(ERROR_AT_IN_EMAIL);
    return true;
  }

  {
    // Check invalid symbols of 1 part. Check length.
    size_t positionPart{};
    if (validSymbols(positionPart)) {
      std::cout << getErrorStr(ERROR_INCORRECT_SYMBOLS);
      return true;
    }

    if (computeLength(positionPart, 64)) {
      std::cout << getErrorStr(ERROR_LENGTH_1);
      return true;
    }

    // Check invalid symbols of 2 part. Check length.
    if (validSymbols(positionPart)) {
      std::cout << getErrorStr(ERROR_INCORRECT_SYMBOLS);
      return true;
    }

    if (computeLength(positionPart, 63)) {
      std::cout << getErrorStr(ERROR_LENGTH_2);
      return true;
    }
  }

  if (findDotsInARow()) {
    std::cout << getErrorStr(ERROR_TWO_DOTS_IN_ROW);
    return true;
  }

  return false;
}

bool EmailValidCheck::findDotAtFirstPosition() {
  if ('@' == email_[0] || '@' == email_[email_.length() - 1] ||
      '.' == email_[0] || '.' == email_[email_.length() - 1]) {
    std::cout << getErrorStr(ERROR_FIRST_DOT_IN_EMAIL);
    return true;
  }
  return false;
}

bool EmailValidCheck::computeLength(size_t& pos, const size_t lengthPart) {
  size_t count{};
  for (auto i{email_.begin() + pos}; i != email_.end(); ++i) {
    count = i - email_.begin() - pos;

    if (('@' == *i || email_.end() - 1 == i) && count < lengthPart) {
      pos = ++count;
      return false;
    }
  }
  return true;
}

bool EmailValidCheck::validLetters(const char symbol) {
  if (symbol >= 'a' && symbol <= 'z')
    return true;
  else if (symbol >= 'A' && symbol <= 'Z')
    return true;
  else if ('-' == symbol || '.' == symbol)
    return true;
  else if (symbol >= '0' && symbol <= '9')
    return true;
  else if ('@' == symbol)
    return true;

  return false;
}

bool EmailValidCheck::validSymbols(const size_t pos) {
  std::string symbols{"!#$%&'*+-/=?^_`{|}~"};
  std::unordered_set<char> hash_symbols;
  for (auto&& i : symbols) hash_symbols.insert(i);

  for (auto i{email_.begin() + pos}; i != email_.end(); ++i) {
    if (validLetters(*i)) continue;
    if (pos == 0 && hash_symbols.find(*i) != hash_symbols.end()) continue;
    return true;
  }
  return false;
}