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
 */

#include "EmailValidCheck.h"

/**
 * @brief user email address check
 */
void userEmailCheck() {
  std::cout << "Enter the email address to check: \e[32m";
  std::string email;
  std::cin >> email;

  std::cout << "\e[37m";
  EmailValidCheck error(email);
  std::cout << error.getEmail() << "  ";
  if (!error.testEmail()) std::cout << "\e[32mYes\e[37m\n";
}

/**
 * @brief example emails to check
 */
void examplesEmailCheck() {
  std::vector<std::string> exampleEmails{
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
      "example-indeed@strange-example.com",
      "John..Doe@example.com",
      "Abc.example.com",
      "A@b@c@example.com",
      "a\"b(c)d,e:f;g<h>i[jk]l@example.com",
      "1234567890123456789012345678901234567890123456789012345678901234+x@"
      "example.com",
      "i_like_underscore@but_its_not_allow_in _this_part.example.com",
      "18904+6@"
      "12512557124124214124214214890123456789012345678901234567890example.com",
  };

  std::cout << "\nChecking for valid example emails:\n\n";
  EmailValidCheck example(exampleEmails);
}

int main() {
  std::cout << "\e[2JDo you want to check email address or see examples?\n"
            << "1 - check your email address.\n"
            << "2 - see the examples.\n";

  int choice;
  do {
    std::cout << "Enter your choice: ";
    std::string choiceStr;
    std::cin >> choiceStr;
    // Т.к. могут ввести случайно строку вместо цифр, и тогда программа уходит в
    // бесконечный цикл.
    try {
      choice = std::stoi(choiceStr);
    } catch (const std::exception& e) {
      std::cerr << "\e[31mError in the entered number.\e[37m\n";
    }

    if (1 == choice || 2 == choice)
      break;
    else
      std::cout << "\e[31mEnter the number 1 or 2\e[37m\n";
  } while (true);

  switch (choice) {
    case 1:
      userEmailCheck();
      break;

    case 2:
      examplesEmailCheck();
      break;

    default:
      break;
  }

  return 0;
}