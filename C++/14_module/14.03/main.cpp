/**
 * @file main.cpp
 * @author vmf0min (vlifom@yandex.ru)
 * @brief Задача 3. Проверка корректности email-адреса.
 * Напишите программу, которая проверяет корректность email-адреса, введенного
 * пользователем.
 * Согласно международным требованиям, корректный email-адрес должен состоять из
 * двух частей, разделенных знаком @. Первая часть должна иметь длину не менее 1
 * и не более 64 символов, вторая часть - не менее 1 и не более 63 символов. Из
 * символов допускаются только английские буквы, цифры и знак - (дефис), а также
 * точка. Точка не может быть первым или последним символом, а кроме того, две
 * точки не могут идти подряд. В первой части (которая предшествует символу @),
 * кроме вышеперечисленных, разрешены еще следующие символы: !#$%&'*+-/=?^_`{|}~
 * Пользователь вводит строку, задающую email-адрес. Программа должна вывести
 * слово Yes, если адрес корректен, а в противном случае - слово No.
 * @version 0.1
 * @date 27-01-2021
 * @copyright Copyright (c) 2021
TODO 3: символы в самом email.английские буквы, цифры и знак - (дефис), а также
точка.
TODO 4: В первой части(которая предшествует символу @), кроме
вышеперечисленных, разрешены еще следующие символы: !#$%&'*+-/=?^_`{|}~
 */

#include "Email_Errors.h"

int main() {
  std::vector<std::string> correctExampleEmails{
      "simple@example.com",
      "very.common@example.com",
      "disposable.style.email.with+symbol@example.com",
      "other.email-with-hyphen@example.com",
      "fully-qualified-domain@example.com",
      "user.name+tag+sorting@example.com",
      "x@example.com",
      "example-indeed@strange-example.com",
      "admin@mailserver1",
      "example@s.example",
      "mailhost!username@example.org",
      "user%example.com@example.org",
  };

  std::vector<std::string> incorrectExampleEmails{
      "John..Doe@example.com",
      "Abc.example.com",
      "A@b@c@example.com",
      "a\"b(c)d,e:f;g<h>i[jk]l@example.com",
      "1234567890123456789012345678901234567890123456789012345678901234+x@"
      "example.com",
      "i_like_underscore@but_its_not_allow_in _this_part.example.com",
      "1@8904+67124124214124214214890123456789012345678901234567890example.com",
  };

  // TODO Выбор проверки. из шаблона или от ввода.
  std::cout << "\e[2J";

  // std::cout << "Enter the email address to check: ";
  // std::string email;
  // // std::cin >> email;
  // email = incorrectExampleEmails[6];
  // Email_Errors error(email);
  // std::cout << error.getEmail() << "  ";
  // if (!error.testEmail()) std::cout << "\e[32mYes\e[37m\n";

  std::cout << "Checking for valid emails:\n\n";
  Email_Errors correct(correctExampleEmails);

  std::cout << "\nChecking for invalid emails:\n\n";
  Email_Errors incorrect(incorrectExampleEmails);

  return 0;
}