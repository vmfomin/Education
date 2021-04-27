/** Задача 2. Быки и коровы
 * В логической игре “быки и коровы” первый игрок загадывает четырехзначное
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

/*********** Прототипы функций ***********/

/** Проверка на количество чисел.
 * @param  &number: значение числа.
 */
bool isFourDigits(std::string& number);

/** Парсер числа. Реализовал через указатель.
 * @param  *number: указатель на массив для записи числа.
 */
bool parserDigitsOfNumber(int* number);

/** Функция для выхода из цикла.
 @param  &exitNumber: Если на входе введены 0, тогда выходим.
 */
inline bool exitLoop(int& exitNumber);

/*********** Функции ***********/

bool isFourDigits(std::string& number) {
  if (4 != number.length()) {
    std::cout << "Error: input number greater than or less than 4 digits\n";
    return false;
  } else {
    return true;
  }
}

bool parserDigitsOfNumber(int* number) {
  std::string numberStr;
  std::cin >> numberStr;

  // Проверка на 4-хзначное число
  if (!isFourDigits(numberStr)) return false;

  for (char iNumber : numberStr) {
    if (iNumber >= '0' && iNumber <= '9') {
      // присваиваю значение в массиве чисел через разыменовывание
      *number = iNumber - '0';
      // смещаю адрес указателя на следующее значение в массиве (тоже самое,
      // что использовать индекс в массиве). Можно убрать к ++i.
      ++number;
    } else {
      std::cout << "Error: nan found!\n";
      return false;
    }
  }

  return true;
}

inline bool exitLoop(int& exitNumber) {
  if (0 == exitNumber) {
    std::cout << "Exiting...\n" << std::endl;
    return true;
  }
  return false;
}

int main() {
  std::cout << "\e[2JFor quit from the loop enter \"0000\"\n";
  while (true) {
    // Объявляю массив чисел для 1 числа. Вводим и парсим 1 число
    int firstNumber[4]{};
    do {
      std::cout << "Enter the intended number: ";
    } while (!parserDigitsOfNumber(firstNumber));

    // Объявляю массив чисел для 2 числа. Вводим и парсим 2 число
    int secondNumber[4]{};
    do {
      std::cout << "Enter the second number:   ";
    } while (!parserDigitsOfNumber(secondNumber));

    // Длина чисел.
    int sizeNumber = sizeof(firstNumber) / sizeof(firstNumber[0]);

    int nBulls{}, nCows{};
    for (int i = 0; i < sizeNumber; i++) {
      if (firstNumber[i] == secondNumber[i]) {
        nBulls++;
      } else {
        for (int j = 0; j < sizeNumber; j++) {
          if (firstNumber[i] == secondNumber[j] &&
              firstNumber[i] != firstNumber[j]) {
            if (secondNumber[j] != secondNumber[j - 1] ||
                firstNumber[i] != firstNumber[i - 1]) {
              nCows++;
            }
          }
        }
      }
    }

    std::cout << "Bulls: " << nBulls << ", cows: " << nCows << "\n\n";

    // Обрабатываю выход из бесконечного цикла при вводе 0000.
    int exitNumber{};
    for (int i = 0; i < sizeNumber; i++) exitNumber += firstNumber[i];
    if (exitLoop(exitNumber)) return 0;

    exitNumber = 0;
    for (int i = 0; i < sizeNumber; i++) exitNumber += secondNumber[i];
    if (exitLoop(exitNumber)) return 0;
  }
}