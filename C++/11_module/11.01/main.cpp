/**
 * @file main.cpp
 * @author vmf0min (vlifom@yandex.ru)
 * @brief Задача 1.
 * Шифр Цезаря
 * В древности для зашифровывания сообщений использовался такой способ. Все
 * буквы в сообщении сдвигались на одно и то же число позиций в алфавите. Число
 * позиций могло быть как положительным, так и отрицательным, и являлось
 * параметром шифра. Если для сдвига на данное число позиций алфавита не
 * хватает, то он зацикливается (то есть буква с номером 27 - это снова a, буква
 * с номером 28 - это b, и так далее). Например, слово abracadabra при сдвиге на
 * 10 позиций превратится в klbkmknklbk. Этот простейший шифр называется шифром
 * Цезаря. Регистр букв (заглавные и строчные) менять не нужно. Напишите функцию
 * encryptCaesar от строки и числа, которая возвращает исходную строку,
 * зашифрованную шифром Цезаря с параметром, равным данному числу. Также
 * напишите функцию decryptCaesar, выполняющую обратное преобразование. Считаем,
 * что входные строки состоят лишь из английских букв; если там содержатся и
 * другие символы, то их надо игнорировать.
 * @version 0.1
 * @date 25-01-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>

/**
 * @brief Функция кодирования Шифра Цезаря.
 * @param strOut строка, которую надо зашивровать
 * @param pos на сколько смещаем.
 */
void encryptCaesar(std::string& strOut, const int& pos) {
  for (size_t i{}; i < strOut.length(); ++i) {
    bool isUpperChar{strOut[i] >= 'A' && strOut[i] <= 'Z'};
    bool isLowerChar{strOut[i] >= 'a' && strOut[i] <= 'z'};

    if (isUpperChar) {
      if ((strOut[i] + pos) > 'Z') {
        strOut[i] += pos - 'Z' + 'A' - 1;
      } else if ((strOut[i] + pos) < 'A') {
        strOut[i] += pos + 'Z' - 'A' + 1;
      } else {
        strOut[i] += pos;
      }
    } else if (isLowerChar) {
      if ((strOut[i] + pos) > 'z') {
        strOut[i] += pos - 'z' + 'a' - 1;
      } else if ((strOut[i] + pos) < 'a') {
        strOut[i] += pos + 'z' - 'a' + 1;
      } else {
        strOut[i] += pos;
      }
    }
  }
}

/**
 * @brief Функция декодирования Шифра Цезаря.
 * @param strOut строка, которую надо зашивровать
 * @param pos на сколько смещаем.
 */
void decryptCaesar(std::string& strOut, const int& pos) {
  encryptCaesar(strOut, -pos);
}

/**
 * @brief Вывод примеров в консоль
 * @param example текст для вывода в консоль.
 * @param pos смещение в тексте.
 */
void print(std::string& example, const int& pos) {
  std::cout << "Example:\e[32m\n" << example << "\e[37m\n";

  encryptCaesar(example, pos);
  std::cout << "Encrypted:\e[32m\n" << example << "\e[37m\n";

  decryptCaesar(example, pos);
  std::cout << "Decrypted:\e[32m\n" << example << "\e[37m\n\n";
}

int main() {
  std::cout << "\e[2J";
  // 10 позиций
  std::string example_1{"abracadabra"};
  // 5 позиций
  std::string example_2{"The quick brown fox jumps over the lazy dog"};
  // 25 позиций
  std::string example_3{
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do "
      "eiusmod tempor incididunt ut labore et dolore magna aliqua.\n"
      "Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi "
      "ut aliquip ex ea commodo consequat.\nDuis aute irure dolor in "
      "reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla "
      "pariatur.\nExcepteur sint occaecat cupidatat non proident, sunt in "
      "culpa qui officia deserunt mollit anim id est laborum."};

  print(example_1, 10);
  print(example_2, 5);
  print(example_3, 25);

  return 0;
}