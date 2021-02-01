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
bool dotsCheck(const std::string& str);

/**
 * @brief Check ip address numbers
 * @param strIn string to console
 * @return true numbers correct.
 * @return false
 */
bool checkIpNumbers(const std::string& strIn);

/**
 * @brief check examples ip address in the loop.
 */
void checkIpAddress();

/**
 * @brief check user's ip address.
 * @param str
 */
void checkIpAddress(const std::string& str);

/**
 * @brief Search char in ip
 * @param str ip
 * @return true found
 */
bool isChar(const std::string& str);

/*****************Functions*****************/

bool dotsCheck(const std::string& str) {
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
              << "\e[31mError: Not 3 dots in the IP.\e[37m\n";
    return false;
  }

  return true;
}

bool isChar(const std::string& str) {
  for (auto& i : str) {
    if (i >= '0' && i <= '9' || '.' == i) {
    } else {
      std::cerr << str << "\t"
                << "\e[31mError: NaN in part of IP\e[37m\n";
      return false;
    }
  }

  return true;
}

bool checkIpNumbers(const std::string& strIn) {
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

    partOfIp = std::stoi(partOfIpStr);

    if (partOfIp < 0) {
      std::cerr << strIn << "\t"
                << "\e[31mError: part of IP less than 0\e[37m\n";
      return false;
    } else if (partOfIp > 255) {
      std::cerr << strIn << "\t"
                << "\e[31mError: part of IP greater than 255 \e[37m\n";
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
    checkIpAddress(*i_ip);
  }
}

void checkIpAddress(const std::string& str) {
  if (str.length() > 15) {
    std::cerr << str << "\t"
              << "\e[31mError: ip Length more than 15 digits.\e[37m\n";
    return;
  }

  if (!isChar(str)) return;

  if (!dotsCheck(str)) return;

  if (!checkIpNumbers(str)) return;

  std::cout << str << "\t\e[32mYes\e[37m\n";
}

int main() {
  std::cout << "\e[2J";

  std::cout << "\e[2JDo you want to check IP-address or see examples?\n"
            << "1 - check your IP-address.\n"
            << "2 - see the examples.\n";

  int choice;
  do {
    std::cout << "Enter your choice: ";
    std::string choiceStr;
    std::cin >> choiceStr;

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

  std::cout << "\n";
  std::string ip;
  switch (choice) {
    case 1:
      std::cout << "Enter the IP:\e[32m ";
      std::cin >> ip;
      checkIpAddress(ip);
      std::cout << "\e[37m";
      break;

    case 2:
      checkIpAddress();
      break;

    default:
      break;
  }

  return 0;
}