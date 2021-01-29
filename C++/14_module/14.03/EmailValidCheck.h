/**
 * @file EmailValidCheck.h
 * @author vmf0min (vlifom@yandex.ru)
 * @brief Class check the e-mail address.
 * @version 0.1
 * @date 27-01-2021
 * @copyright Copyright (c) 2021
 */

#ifndef _INC_EMAIL_VALID_CHECK_H_
#define _INC_EMAIL_VALID_CHECK_H_

#include <iostream>
#include <map>
#include <vector>

/****Коды ошибок при тестированнии email.****/

#define ERROR_FIRST_DOT_IN_EMAIL \
  101  // symbol '@' or '.' at the first or last position.
#define ERROR_TWO_DOTS_IN_ROW 102  // two dots in a row.
#define ERROR_AT_IN_EMAIL 103      // the symbol'@' more than one or not found.
#define ERROR_LENGTH_1 104  // the first part of length before '@' more than 64.
#define ERROR_LENGTH_2 105  // the second part of length after '@' more than 63.
#define ERROR_FULL_LENGTH 106  // the total length should be no more than 127
#define ERROR_INCORRECT_SYMBOLS 107  // incorrect symbols in the email.
#define ERROR_INCORRECT_SYMBOLS_PART2 \
  108  // incorrect symbols in second part of the email. !#$%&'*+-/=?^_`{|}~

#define ERROR_UNKNOWN 404  // unknown error code.

/**
 * @brief Class check the e-mail address.
 */
class EmailValidCheck {
 public:
  /**
   * @brief Construct a new email error check.
   * @param email the email address for check errors.
   */
  EmailValidCheck(std::string& email) : email_{email} {}

  /**
   * @brief Construct a new email and additional error map.
   * @param email the email address for check errors.
   * @param errorsMap new error added in the error's map.
   */
  EmailValidCheck(std::string& email, std::map<int, std::string>& errorsMap)
      : email_{email} {
    errorsMap_.insert(errorsMap.begin(), errorsMap.end());
  }

  /**
   * @brief Construct for check the emails in the loop.
   * @param emails A list of email addresses.
   */
  EmailValidCheck(std::vector<std::string>& emails);

  /**
   * @brief Destroy the EmailValidCheck object
   */
  virtual ~EmailValidCheck() = default;

  /**
   * @brief A method for the user to check the email is valid.
   * @return true email is invalid
   * @return false
   */
  bool testEmail();

  /**
   * @brief Compute full length of email
   * @return true full length more than 127
   * @return false
   */
  virtual bool computeLength();

  /**
   * @brief Check for Latin letters and Arabic numerals as default
   * @param symbol the symbol being checked
   * @return true
   * @return false
   */
  virtual bool validLetters(const char& symbol);

  /**
   * @brief Get the email address
   * @return std::string
   */
  std::string getEmail() { return email_; }

  /**
   * @brief Get the error message
   * @param error error number.
   * @return std::string error message.
   */

  std::string getErrorStr(const int& error) {
    auto it{errorsMap_.find(error)};

    if (it != errorsMap_.end()) {
      return it->second;
    } else {
      it = errorsMap_.find(ERROR_UNKNOWN);
      return it->second;
    }
  }

 private:
  const std::string email_;  // const, чтобы нельзя было изменить email и
                             // допустить ошибку при решении.
  std::map<int, std::string> errorsMap_{
      {ERROR_FIRST_DOT_IN_EMAIL,
       "\e[31mError: symbol '@' or '.' at the first or last position\e[37m\n"},
      {ERROR_TWO_DOTS_IN_ROW, "\e[31mError: two dots in a row.\e[37m\n"},
      {ERROR_AT_IN_EMAIL,
       "\e[31mError: the symbol'@' more than one or not found.\e[37m\n"},
      {ERROR_LENGTH_1,
       "\e[31mError: the first part of length before '@' more than "
       "64.\e[37m\n"},
      {ERROR_LENGTH_2,
       "\e[31mError: the second part of length after '@' more than "
       "63.\e[37m\n"},
      {ERROR_FULL_LENGTH, "the total length should be no more than 127.\n"},
      {ERROR_INCORRECT_SYMBOLS,
       "\e[31mError: incorrect symbols in the email.\e[37m\n"},
      {ERROR_INCORRECT_SYMBOLS_PART2,
       "\e[31mError: incorrect symbols in second part of the email.\e[37m\n"},

      {ERROR_UNKNOWN, "\e[31mError: unknown error code.\e[37m\n"},
  };

  /**
   * @brief Search symbols '.' and '\@' in the email address at first
   * position
   * @return true found
   * @return false
   */
  bool findDotAtFirstPosition() {
    if ('@' == email_[0] || '@' == email_[email_.length() - 1] ||
        '.' == email_[0] || '.' == email_[email_.length() - 1])
      return true;

    return false;
  }

  /**
   * @brief Search two symbols '.' in a row.
   * @return true found
   * @return false
   */
  bool findDotsInARow() {
    for (auto i{email_.begin()}; i != email_.end() - 1; ++i)
      if ('.' == *i && '.' == *(i + 1)) return true;

    return false;
  }

  /**
   * @brief Count of symbol '\@' in the email
   * @return true if more than 1 symbol '\@'
   * @return false
   */
  bool countAtInEmail() {
    size_t count{};
    for (auto& c : email_)
      if ('@' == c) ++count;

    if (count > 1 || 0 == count) return true;

    return false;
  }

  /**
   * @brief Check the length of the 2 parts (before and after '\@') of the
   * email.
   * @param pos position to search the email address length.
   * @return true incorrect length
   * @return false
   */
  bool computeLength(size_t& pos, const size_t& lengthPart);

  /**
   * @brief Check for Latin letters and Arabic numerals and allowed symbols for
   * 1 part of email.
   * @param pos determining the position in the email address.
   * @return true incorrect letters found.
   * @return false
   */
  bool validSymbols(const size_t& pos);
};

#endif /* _INC_EMAIL_VALID_CHECK_H_ */