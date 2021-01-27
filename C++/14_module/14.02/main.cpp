/**
 * @file main.cpp
 * @author vmf0min (vlifom@yandex.ru)
 * @brief Задача 2. Крестики-нолики.
 * Петя и Вася играли в крестики-нолики и не стерли после себя результаты своей
 * игры. Теперь перед вами табличка 3х3, которая осталась после их поединка. Вы
 * хотите понять, выиграл ли кто-то из них, или они не доиграли.
 * На вход программе дается три строки, кодирующие верхнюю, среднюю и нижнюю
 * строчки игрового поля. Крестик обозначается символом X (английская заглавная
 * буква X), нолик - символом O (заглавная английская буква O), пустая клетка -
 * точкой.
 * Если ввод некорректен (то есть такая таблица не могла получиться в ходе
 * настоящей игры), то надо написать в ответ слово Incorrect.
 * Если таблица корректна и выиграли крестики, то нужно вывести в ответ слова
 * Petya won, если нолики - то Vanya won, а иначе (то есть они не доиграли или
 * сыграли вничью) надо написать Nobody.
 * @version 0.1
 * @date 26-01-2021
 * @copyright Copyright (c) 2021
 */

#include <cctype>
#include <iostream>

/******************Сигнатуры******************/

/**
 * @brief Проверка на 3 числа в строке.
 * @param str Проверяемая строка.
 * @return true если 3 числа в строке.
 * @return false
 */
bool isCorrectLine(std::string& str);

/**
 * @brief Вывод строки на экран
 * @param str строка партии игры в крестики-нолики
 */
inline void printLine(const std::string& str);

/**
 * @brief Проверка победителя X или O
 * @param symbol X или O
 */
inline void printWhoWon(const char& symbol, const int& index);

/**
 * @brief Проверка победы по вертикали.
 * @param str1 1 строка
 * @param str2 2 строка
 * @param str3 3 строка
 * @return true победа по вертикали
 * @return false
 */
inline bool checkWhoWon(const std::string& str1, const std::string& str2,
                        const std::string& str3);

/**
 * @brief Проверка победы по горизонтали.
 * @param str проверяемая строка.
 * @return true победа по горизонтали.
 * @return false
 */
inline bool checkWhoWon(const std::string& str);

/**
 * @brief Проверка победы по диагонали.
 * @param symbol1 1 символ в диагонали.
 * @param symbol2 2 символ в диагонали.
 * @param symbol3 3 символ в диагонали.
 * @return true победа по диагонали.
 * @return false
 */
inline bool checkWhoWon(const char& symbol1, const char& symbol2,
                        const char& symbol3);

/******************Функции******************/

bool isCorrectLine(std::string& str) {
  if (3 != str.length()) {
    std::cout << "\e[31mError: the string must contain 3 values\e[37m\n";
    return false;
  }

  for (size_t i{}; i < str.length(); ++i) {
    if (str[i] != 'X' && str[i] != 'O' && str[i] != 'x' && str[i] != 'o' &&
        str[i] != '.') {
      std::cout << "\e[31mIncorrect line\e[37m\n";
      return false;
    }

    if (std::islower(str[i])) str[i] = std::toupper(str[i]);
  }

  return true;
}

inline void printLine(const std::string& str) {
  for (size_t i{}; i < str.length(); ++i) std::cout << str[i] << "  ";
  std::cout << "\n";
}

inline void printWhoWon(const char& symbol, const int& index) {
  std::string typeWonStr[]{"vertically\n", "horizontally\n", "diaganally\n"};
  std::cout << "\e[36m";

  if (symbol == 'X')
    std::cout << "Petya won ";
  else if (symbol == 'O')
    std::cout << "Vanya won ";

  std::cout << typeWonStr[index];
  std::cout << "\e[37m";
}

inline bool checkWhoWon(const std::string& str1, const std::string& str2,
                        const std::string& str3) {
  for (size_t i{}; i < str1.length(); ++i) {
    if (str1[i] == str2[i] && str2[i] == str3[i] && str1[i] == str3[i] &&
        str1[i] != '.') {
      printWhoWon(str1[i], 0);
      return true;
    }
  }

  return false;
}

inline bool checkWhoWon(const std::string& str) {
  if (str[0] != '.' && str[0] == str[1] && str[0] == str[2]) {
    printWhoWon(str[0], 1);
    return true;
  }

  return false;
}

inline bool checkWhoWon(const char& symbol1, const char& symbol2,
                        const char& symbol3) {
  if (symbol1 == symbol2 && symbol1 == symbol3 && symbol1 != '.') {
    printWhoWon(symbol1, 2);
    return true;
  }

  return false;
}

int main() {
  std::cout << "\e[2J";

  std::string line_1;
  do {
    std::cout << "Enter first line:  ";
    std::cin >> line_1;
  } while (!isCorrectLine(line_1));

  std::string line_2;
  do {
    std::cout << "Enter second line: ";
    std::cin >> line_2;
  } while (!isCorrectLine(line_2));

  std::string line_3;
  do {
    std::cout << "Enter third line:  ";
    std::cin >> line_3;
  } while (!isCorrectLine(line_3));

  std::cout << "\ntic-tac-toe:\e[32m\n";
  printLine(line_1);
  printLine(line_2);
  printLine(line_3);
  std::cout << "\e[37m\n";

  // Нахождение победителя по вертикали.
  if (checkWhoWon(line_1, line_2, line_3)) return 0;

  // Нахождение победителя по горизонтали.
  if (checkWhoWon(line_1)) return 0;
  if (checkWhoWon(line_2)) return 0;
  if (checkWhoWon(line_3)) return 0;

  // Нахождение победителя по диагонали.
  if (checkWhoWon(line_1[0], line_2[1], line_3[2])) return 0;
  if (checkWhoWon(line_1[2], line_2[1], line_3[0])) return 0;

  std::cout << "\e[36mNobody\e[37m\n";

  return 0;
}