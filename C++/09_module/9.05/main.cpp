// 5. Из обычных чисел — в римские
/* Напишите программу, которая переводит данное пользователем число в римскую
запись. Например, 19 в римской записи представляется как XIX.
Римская запись числа получается по следующим правилам. Сначала в ней идут буквы,
описывающие количество тысяч в числе. Затем идут буквы, обозначающие количество
сотен, затем буквы, обозначающие количество десятков, и в конце — буквы,
обозначающие количество единиц. Для записи используются следующие буквы: 1 — I,
5 — V, 10 — X, 50 — L, 100 — C, 500 — D и 1000 — M. Число получается как сумма
значений использованных в нем букв, за тем исключением, что если буква с меньшим
значением идет после буквы с большим значением, то ее значение вычитается из
значения числа. Вычитание используется только в случае, когда надо передать
цифру 4 или 9, в остальных случаях используется сложение. (Например, 9
обозначается как IX, 40 обозначается как XL). В числе запрещено писать более
трех одинаковых букв подряд (таким образом, максимальное число, которое можно
записать по этим правилам, равно 3999).
Программе на вход дается целое число из диапазона от 1 до 3999. (Вы можете
считывать его как число или как строку, если так удобнее.)
Программа должна вывести римскую запись данного числа.
Примеры:
Ввод: 351
Вывод: CCCLI
Ввод: 449
Вывод: CDXLIX
Ввод: 1313
Вывод: MCCCXIII
Ввод: 2020
Вывод: MMXX */

#include <iostream>

struct Digits {
  int thousands;
  int hundreds;
  int tens;
  int units;
};

// Функция перевода числа в римские.
// digitInNumber -- тысячи, сотни, десятки или единицы (значение от 0 до 3)
// digit -- число для преобразования.
// romanNumber -- строка для вывода.
void convertNumberToRomans(int digitInNumber, int digit,
                           std::string &romanNumber) {
  std::string romanLetter;

  if (digitInNumber == 0) {
    for (int i = 0; i < digit; i++) romanNumber += 'M';
    return;
  } else if (digitInNumber == 1) {
    romanLetter = "CDM";
  } else if (digitInNumber == 2) {
    romanLetter = "XLC";
  } else if (digitInNumber == 3) {
    romanLetter = "IVX";
  } else {
    return;
  }

  if (digit == 4 || digit == 9) romanNumber += romanLetter[0];
  if (digit >= 4 && digit <= 8) romanNumber += romanLetter[1];
  if (digit == 9) romanNumber += romanLetter[2];
  if (digit % 5 < 4)
    for (int i = 0; i < digit % 5; i++) romanNumber += romanLetter[0];
}

int main() {
  int number;
  do {
    std::cout << "\nEnter a number to convert to romanLetter numerals: ";
    std::cin >> number;

    Digits digits{};

    if (number < 1 || number > 3999) {
      if (0 == number) {
        std::cout << "Exit...\n" << std::endl;
        break;
      }

      std::cout << "Error: not valid number !\n ";
      continue;
    }

    std::string romanNumber{};

    // Конвертация числа
    digits.thousands = number / 1000;
    convertNumberToRomans(0, digits.thousands, romanNumber);

    digits.hundreds = number % 1000 / 100;
    convertNumberToRomans(1, digits.hundreds, romanNumber);

    digits.tens = number % 100 / 10;
    convertNumberToRomans(2, digits.tens, romanNumber);

    digits.units = number % 10;
    convertNumberToRomans(3, digits.units, romanNumber);

    std::cout << "The Roman number after the conversion : " << romanNumber
              << "\n";
  } while (true);

  return 0;
}
