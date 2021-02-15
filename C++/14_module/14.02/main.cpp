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
 * Peter won, если нолики - то Ivan won, а иначе (то есть они не доиграли или
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
 * @param nX_Out Количество X в строке.
 * @param nO_Out Количество O в строке.
 * @return true если 3 числа в строке.
 * @return false
 */
bool isCorrectLine(std::string& str, int16_t& nX_Out, int16_t& nO_Out);

/**
 * @brief Вывод строки на экран
 * @param str строка партии игры в крестики-нолики
 */
inline void printLine(const std::string& str);

/**
 * @brief Проверка победителя X или O
 * @param symbol X или O
 */
inline void whoWon(const char& symbol, bool& winner);

/**
 * @brief Проверка победы по вертикали.
 * @param str1 1 строка
 * @param str2 2 строка
 * @param str3 3 строка
 * @return true победа по вертикали
 * @return false
 */
inline bool checkWhoWon(const std::string& str1, const std::string& str2,
                        const std::string& str3, bool& winner);

/**
 * @brief Проверка победы по горизонтали.
 * @param str проверяемая строка.
 * @return true победа по горизонтали.
 * @return false
 */
inline bool checkWhoWon(const std::string& str, bool& winner);

/**
 * @brief Проверка победы по диагонали.
 * @param symbol1 1 символ в диагонали.
 * @param symbol2 2 символ в диагонали.
 * @param symbol3 3 символ в диагонали.
 * @return true победа по диагонали.
 * @return false
 */
inline bool checkWhoWon(const char& symbol1, const char& symbol2,
                        const char& symbol3, bool& winner);

/**
 * @brief Check winner
 * @param str1 first string
 * @param str2 second string
 * @param str3 third string
 * @param winner Победитель X или O
 * @param countVictory количество побед. только 1.
 * @return true winner found
 */
bool check(const std::string& str1, const std::string& str2,
           const std::string& str3, bool& winner, int16_t& countVictory);

/**
 * @brief Ввод строки.
 * @param str Вводимая строка.
 * @param nX_Out Количество X в строке.
 * @param nO_Out Количество O в строке.
 */
void inputLine(std::string& str, int16_t& nX_Out, int16_t& nO_Out);

/******************Функции******************/

bool isCorrectLine(std::string& str, int16_t& nX_Out, int16_t& nO_Out) {
  if (3 != str.length()) {
    std::cout << "\x1b[31mError: the string must contain 3 values\x1b[37m\n";
    return false;
  }

  for (size_t i{}; i < str.length(); ++i) {
    if (str[i] != 'X' && str[i] != 'O' && str[i] != 'x' && str[i] != 'o' &&
        str[i] != '.') {
      std::cout << "\x1b[31mIncorrect line\x1b[37m\n";

      return false;
    }

    if (std::islower(str[i])) str[i] = std::toupper(str[i]);

    if ('X' == str[i])
      ++nX_Out;
    else if ('O' == str[i])
      ++nO_Out;
  }
  return true;
}

inline void printLine(const std::string& str) {
  for (size_t i{}; i < str.length(); ++i) std::cout << str[i] << "  ";
  std::cout << "\n";
}

inline void whoWon(const char& symbol, bool& winner) {
  if (symbol == 'X')
    winner = true;
  else if (symbol == 'O')
    winner = false;

  std::cout << "\x1b[37m";
}

inline bool checkWhoWon(const std::string& str1, const std::string& str2,
                        const std::string& str3, bool& winner) {
  for (size_t i{}; i < str1.length(); ++i) {
    if (str1[i] != '.' && str1[i] == str2[i] && str1[i] == str3[i]) {
      whoWon(str1[i], winner);
      return true;
    }
  }
  return false;
}

inline bool checkWhoWon(const std::string& str, bool& winner) {
  if (str[0] != '.' && str[0] == str[1] && str[0] == str[2]) {
    whoWon(str[0], winner);
    return true;
  }
  return false;
}

inline bool checkWhoWon(const char& symbol1, const char& symbol2,
                        const char& symbol3, bool& winner) {
  if (symbol1 != '.' && symbol1 == symbol2 && symbol1 == symbol3) {
    whoWon(symbol1, winner);
    return true;
  }
  return false;
}

bool check(const std::string& str1, const std::string& str2,
           const std::string& str3, bool& winner, int16_t& countVictory) {
  // Нахождение победителя по вертикали.
  if (checkWhoWon(str1, str2, str3, winner)) ++countVictory;

  // Нахождение победителя по горизонтали.
  if (checkWhoWon(str1, winner)) ++countVictory;
  if (checkWhoWon(str2, winner)) ++countVictory;
  if (checkWhoWon(str3, winner)) ++countVictory;

  // Нахождение победителя по диагонали.
  if (checkWhoWon(str1[0], str2[1], str3[2], winner)) ++countVictory;
  if (checkWhoWon(str1[2], str2[1], str3[0], winner)) ++countVictory;

  if (countVictory != 1)
    return false;
  else
    return true;
}

void inputLine(std::string& str, int16_t& nX_Out, int16_t& nO_Out) {
  do {
    std::cout << "Enter first line:  ";
    std::cin >> str;
    nX_Out = nO_Out = 0;
  } while (!isCorrectLine(str, nX_Out, nO_Out));
}

int main() {
  std::cout << "\x1b[2J";

  int16_t nX{};  // Общее количество крестиков
  int16_t nO{};  // Общее количество ноликов

  int16_t nX_Out{10}, nO_Out{};  // количество крестиков и ноликов в строке.

  std::string line_1;
  inputLine(line_1, nX_Out, nO_Out);
  nX += nX_Out;
  nO += nO_Out;

  std::string line_2;
  inputLine(line_2, nX_Out, nO_Out);
  nX += nX_Out;
  nO += nO_Out;

  std::string line_3;
  inputLine(line_3, nX_Out, nO_Out);
  nX += nX_Out;
  nO += nO_Out;

  std::cout << "\ntic-tac-toe:\x1b[32m\n";
  printLine(line_1);
  printLine(line_2);
  printLine(line_3);
  std::cout << "\x1b[37m\n";

  bool victory;   // Проверка победителя.
  bool winner{};  // true X won, else O.
  // Количество побед. Только равен 1.
  int16_t countVictory{};
  victory = check(line_1, line_2, line_3, winner, countVictory);

  // Results
  if (victory && countVictory == 1) {
    if (winner && nX - nO == 1)
      std::cout << "\x1b[36mPeter won\x1b[37m\n";
    else if (!winner && nX - nO == 0)
      std::cout << "\x1b[36mIvan won\x1b[37m\n";
    else
      std::cout << "\x1b[31mIncorrect\x1b[37m\n";
  } else if (!victory && countVictory == 0 && (nX - nO == 1 || nX - nO == 0)) {
    std::cout << "\x1b[36mNobody\x1b[37m\n";
  } else {
    std::cout << "\x1b[31mIncorrect\x1b[37m\n";
  }

  return 0;
}