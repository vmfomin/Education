///  Задача 2. Быки и коровы
/* В логической игре “быки и коровы” первый игрок загадывает четырехзначное
 * число (оно может начинаться и с нулей), а второй игрок должен его отгадать.
 * Отгадывание происходит так: своим ходом второй игрок называет любое
 * четырехзначное число, а первый ему отвечает, сколько в этом числе “быков” и
 * сколько “коров”. Корова — это цифра, которая совпадает по значению с
 * какой-то из цифр задуманного числа, но стоит не на нужном месте. Бык — это
 * цифра, совпадающая с цифрой в задуманном числе и по значению, и по
 * расположению.
 * Вам нужно написать программу, которая по загаданному числу и по названному
 * вторым игроком числу определяет, сколько во втором числе “быков” и сколько
 * “коров”. Не забудьте, что числа могут начинаться с нулей!
 * Примеры:
 * Введите задуманное число: 5671
 * Введите второе число: 7251
 * Быков: 1, коров: 2
 * Введите задуманное число: 1234
 * Введите второе число: 1234
 * Быков: 4, коров: 0
 * Введите задуманное число: 0023
 * Введите второе число: 2013
 * Быков: 2, коров: 1*/

#include <iostream>

/// Прототипы функций
// Сделал функции, чтобы не повторяться принцип "DRY".

// Проверка на количество чисел.
bool isFourDigits(std::string &number);

// Парсер числа. Реализовал через указатель.
bool parserDigitsOfNumber(int *number);

/// Функции

bool isFourDigits(std::string &number) {
  if (4 != number.length()) {
    std::cout << "Error: input number greater than or less than 4 digits\n";
    return false;
  } else {
    return true;
  }
}

bool parserDigitsOfNumber(int *number) {
  std::string numberStr;
  std::cin >> numberStr;

  // Проверка на 4-хзначное число
  if (!isFourDigits(numberStr)) return false;

  for (int i = 0; i < numberStr.length(); ++i) {
    if (numberStr[i] >= '0' && numberStr[i] <= '9') {
      // присваиваю значение в массиве чисел через разыменовывание
      *number = numberStr[i] - '0';
      // смещаю адрес указателя на следующее значение в массиве (тоже самое,
      // что использовать индекс в массиве).
      ++number;
    } else {
      std::cout << "Error: nan found!\n";
      return false;
    }
  }

  return true;
}

int main() {
  // Объявляю массив чисел для 1 числа.
  int firstNumber[4]{};
  // Вводим и парсим 1 число
  do {
    std::cout << "Enter the intended number: ";
  } while (!parserDigitsOfNumber(firstNumber));

  // Объявляю массив чисел для 2 числа.
  int secondNumber[4]{};
  // Вводим и парсим 2 число
  do {
    std::cout << "Enter the second number: ";
  } while (!parserDigitsOfNumber(secondNumber));

  int bullsCount{}, cowsCount{}, sum{4};
  // Вычисление коров и быков.
  for (int i = 0; i < sizeof(firstNumber) / sizeof(firstNumber[0]); ++i) {
    if (firstNumber[i] == secondNumber[i]) {
      ++bullsCount;
      continue;
    }

    for (int j = 0; j < sizeof(secondNumber) / sizeof(secondNumber[0]); ++j) {
      // Когда повторяются числа
      if (firstNumber[i] == firstNumber[j])
        continue;
      else if (firstNumber[i] == secondNumber[j])
        ++cowsCount;
    }
  }

  std::cout << "Быков: " << bullsCount << ", коров: " << cowsCount << '\n';

  return 0;
}