/**
 * @file main.cpp
 * @author vmf0min (vlifom@yandex.ru)
 * @brief Задача 4. Проверка корректности IP-адреса.
 * На этот раз вам нужно проверить, задает ли введенная пользователем строка
 * корректный IP-адрес. IP-адрес должен представлять из себя 4 числа,
 * разделенных точками без пробелов, причем каждое число должно быть в диапазоне
 * от 0 до 255 включительно. Числа не должны содержать ведущих нулей. Других
 * символов в строке, кроме вышеописанных, присутствовать не должно.
 * Пользователь вводит строку, задающую email-адрес. Программа должна вывести
 * слово Yes, если адрес корректен, а в противном случае - слово No.
 * @version 0.1
 * @date 01-02-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <vector>

/*****************Signatures*****************/
/**
 * @brief Counts of the dots and search dots in a row in IP address.
 * @param str ip-address.
 * @return true 3 dots and not dots in a row in the ip.
 */
bool dotsCheck(std::string& str);

/**
 * @brief check examples ip address in the loop.
 */
void checkIpAddress();

/**
 * @brief check user's ip address.
 * @param str
 */
void checkIpAddress(std::string& str);

/*****************Functions*****************/

bool dotsCheck(std::string& str) {
  int dots{};
  for (auto i{str.begin()}; i != str.end(); ++i) {
    if ('.' == *i) ++dots;
    if (i != str.end() - 1 && '.' == *i && '.' == *(i + 1)) {
      std::cerr << str << "\t"
                << "\e[31mError: dots in a row.\e[37m\n";
      return false;
    }
  }

  if (dots != 3) {
    std::cerr << str << "\t"
              << "\e[31mError: there are more than 3 dots.\e[37m\n";
    return false;
  }

  return true;
}

bool checkIpNumbers(std::string& strIn) {
  std::string str{strIn};
  std::string partOfIpStr{};
  int partOfIp{};
  int pos{};

  while (pos != -1) {
    pos = str.find('.');
    partOfIpStr = str.substr(0, pos);

    if (partOfIpStr.length() >= 2 && '0' == partOfIpStr[0]) {
      std::cerr << strIn << "\t"
                << "\e[31mError: there are leading zeros\e[37m\n";
      return false;
    }

    try {
      partOfIp = std::stoi(partOfIpStr);
    } catch (const std::exception& e) {
      std::cerr << strIn << "\t\t"
                << "\e[31mError: NaN in part of IP\e[37m\n";
      return false;
    }

    if (partOfIp < 0 || partOfIp > 255) {
      std::cerr
          << strIn << "\t"
          << "\e[31mError: part of IP greater than 255 or less than 0\e[37m\n";
      return false;
    }

    str.erase(str.begin(), str.begin() + pos + 1);
  }
  return true;
}

void checkIpAddress() {
  std::vector<std::string> ipAddresses{
      "127.0.0.1",       "255.255.255.255", "1.2.3.4",     "55.77.213.101",
      "255.256.257.258", "0.55.33.22.",     "10.00.000.0", "23.055.255.033",
      "65.123..9",       "a.b.c.d",
  };

  // Check ip addresses in the loop.
  for (auto i_ip{ipAddresses.begin()}; i_ip != ipAddresses.end(); ++i_ip) {
    if (i_ip->length() > 15) {
      std::cerr << *i_ip << "\t"
                << "\e[31mError: ip Length more than 15 digits.\e[37m\n";
      continue;
    }

    if (!dotsCheck(*i_ip)) continue;

    if (!checkIpNumbers(*i_ip)) continue;

    std::cout << *i_ip << "\t\e[32mYes\e[37m\n";
  }
}

void checkIpAddress(std::string& str) {}

int main() {
  std::cout << "\e[2J";
  
  // TODO: сделать вызов 
  checkIpAddress();

  // std::cout << "Enter IP-address: ";

  return 0;
}