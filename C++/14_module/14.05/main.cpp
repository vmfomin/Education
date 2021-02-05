/**
 * @file main.cpp
 * @author vmf0min (vlifom@yandex.ru)
 * @brief Задача 5. Сравнение длинных вещественных чисел.
 * Вы продолжаете писать калькулятор, работающий с вещественными числами с очень
 * высокой точностью. Вы уже научились проверять корректность записи
 * вещественных чисел в виде строк, и теперь перед вами новая цель - научиться
 * сравнивать такие вещественные числа.
 * Пользователь вводит две строки, задающие
 * вещественные числа, в том же формате, как было описано в задаче “Длинное
 * вещественное число”. Программа должна проверить корректность ввода (для этого
 * можно переиспользовать код, написанный в задаче “Длинное вещественное
 * число”), после чего вывести слово Less, если первое число строго меньше
 * второго; слово More, если первое число строго больше второго; и слово Equal,
 * если введенные числа равны.
 * @version 0.1
 * @date 02-02-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>

/**
 * @brief Check the floating point number
 * @param number number to check
 * @return true Correct number.
 */
bool checkFloatNumber(std::string& number);

/**
 * @brief Input the floating point number
 * @param number number to check
 */
inline void inputFloatNumber(std::string& number);

bool checkFloatNumber(std::string& number) {
  // Количество плавающих точек. Должно быть максимум 1. Иначе ошибка.
  int floatingPointCount{};
  // Есть ли цифры в числе.
  bool isContainNumbers{};
  bool isCorrectNumber{};
  for (int i = 0; i < number.length(); ++i) {
    if (number[i] >= '0' && number[i] <= '9') {
      // Чтобы не переприсваивать переменную.
      if (!isCorrectNumber) isCorrectNumber = true;
      isContainNumbers = true;
    } else if (number[i] == '-' && i == 0) {
      isCorrectNumber = true;
    } else if (number[i] == '.') {
      ++floatingPointCount;
      if (floatingPointCount > 1) {
        isCorrectNumber = false;
        break;
      }
      isCorrectNumber = true;
    } else if (number[i] == '+') {
      isCorrectNumber = false;
      break;
    } else if (number[i] == 'e') {
      isCorrectNumber = false;
      break;
    } else {
      isCorrectNumber = false;
      break;
    }
  }

  if (isCorrectNumber && isContainNumbers) {
    return true;
  } else {
    std::cout << "\x1b[31mError: incorrect number.\x1b[37m\n";
    return false;
  }
}

inline void inputFloatNumber(std::string& number) {
  do {
    std::cout << "Enter the first number:  \x1b[32m";
    std::cin >> number;
    std::cout << "\x1b[37m";
  } while (!checkFloatNumber(number));
}

int main() {
  std::cout << "\x1b[2J";

  float firstNumber{};
  std::string firstNumberStr;
  inputFloatNumber(firstNumberStr);
  firstNumber = std::stof(firstNumberStr);

  float secondNumber{};
  std::string secondNumberStr;
  inputFloatNumber(secondNumberStr);
  secondNumber = std::stof(secondNumberStr);

  if (firstNumber == secondNumber)
    std::cout << "\x1b[36mEqual\x1b[37m\n";
  else if (firstNumber > secondNumber)
    std::cout << "\x1b[36mMore\x1b[37m\n";
  else
    std::cout << "\x1b[36mLess\x1b[37m\n";
}