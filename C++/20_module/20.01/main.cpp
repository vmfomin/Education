/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задание 1. Реализация записи в ведомость учёта.
 * В одном из прошлых заданий мы уже создавали программу чтения и анализа
 * ведомости выплат. Теперь требуется создать простую программу записи в эту
 * ведомость.
 * Формат ведомости прежний. Сначала идёт имя и фамилия получателя денежных
 * средств, далее располагается дата выдачи в формате ДД.ММ.ГГГГ. Завершает
 * запись сумма выплаты в рублях. Данные разделяются между собой пробелами. В
 * конце каждой записи должен быть расположен перевод строки.
 * При старте программы пользователь последовательно вводит данные для новой
 * записи, которые записываются затем в файл в текстовом режиме. Программа
 * должна добавлять новые записи в конец файла, не удаляя его текущее
 * содержимое.
 * @version   0.1
 * @date      29-03-2021
 * @copyright Copyright (c) 2021
 */

#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>

using std::cin;
using std::cout;

/**
 * @brief     information about payments per person
 */
struct Payments {
  std::string name;
  std::string surname;
  double payment;
  std::string paymentDate;
};

/**
 * @brief     write info of personPaymentStruct to file
 * @param     out           output stream
 * @param     pay           Payment info of person
 * @return    std::ostream& output stream
 */
std::ostream& operator<<(std::ostream& out, const Payments& pay) {
  out << pay.name << " " << pay.surname << " " << pay.payment << " "
      << pay.paymentDate << std::endl;
  return out;
}

/**
 * @brief     input info of personPaymentStruct
 * @param     in            input stream
 * @param     pay           Payment info of person
 * @return    std::istream& input stream
 */
std::istream& operator>>(std::istream& in, Payments& pay) {
  in >> pay.name >> pay.surname >> pay.payment >> pay.paymentDate;
  return in;
}

/**
 * @brief     Read payments
 * @param     filename     payment filepath
 */
void readPaymentConsole(const std::string& filename) {
  std::ifstream paymentStatementFile(filename, std::ios::binary);
  if (!paymentStatementFile) {
    cout << "Error: could not be opened for reading!";
    return;
  }
  cout.setf(std::ios::fixed);
  cout.precision(0);
  std::copy(std::istream_iterator<Payments>(paymentStatementFile),
            std::istream_iterator<Payments>(),
            std::ostream_iterator<Payments>(cout, ""));
}

/**
 * @brief     Puts payment to each person
 * @param     filename     payment filepath
 */
void putPayment(const std::string& filename) {
  std::ofstream paymentStatementFile(filename, std::ios::app);
  if (!paymentStatementFile) {
    cout << "Error: could not be opened for writing!";
    return;
  }

  while (paymentStatementFile) {
    Payments personPaymentStruct{};
    cout << "Enter information about the payment to the person:\x1b[32m\n";
    std::string inputLine;
    std::getline(cin, inputLine);
    if (inputLine.empty()) break;

    std::stringstream personPaymentStream{inputLine};
    {
      std::string name{};
      personPaymentStream >> name;
      if (std::isdigit(name[0])) {
        cout << "\x1b[31mInvalid name!\x1b[0m" << std::endl;
        continue;
      }
      personPaymentStruct.name = name;
    }

    {
      std::string surname{};
      personPaymentStream >> surname;
      if (std::isdigit(surname[0])) {
        cout << "\x1b[31mInvalid surname!\x1b[0m" << std::endl;
        continue;
      }
      personPaymentStruct.surname = surname;
    }

    {
      try {
        std::string payment{};
        personPaymentStream >> payment;
        personPaymentStruct.payment = std::stod(payment);
      } catch (const std::exception& e) {
        cout << "\x1b[31mInvalid payment!\x1b[0m" << std::endl;
        continue;
      }
    }

    {
      try {
        std::string date{};
        personPaymentStream >> date;
        int32_t day{std::stoi(date.substr(0, 2))};
        if (day < 1 || day > 31) throw -1;

        int32_t month{std::stoi(date.substr(3, 2))};
        if (month < 1 || month > 12) throw -2;

        int32_t year{std::stoi(date.substr(6, 4))};
        if (year < 1900 || year > 2021) throw -3;

        personPaymentStruct.paymentDate = date;
      } catch (int a) {
        cout << "\x1b[31mInvalid date!\x1b[0m" << std::endl;
        continue;
      } catch (const std::exception& e) {
        cout << "\x1b[31mInvalid date!\x1b[0m" << std::endl;
        continue;
      }
    }
    cout << "\x1b[0m";
    paymentStatementFile.setf(std::ios::fixed);
    paymentStatementFile.precision(0);
    paymentStatementFile << personPaymentStruct;
  }

  cout << "\x1b[0m";
  paymentStatementFile.close();
}

int main() {
  cout << "\x1b[2J";
  cout << "\x1b[33mI open the file to enter the payment information.\x1b[0m\n";
  putPayment("../payment_statement.txt");
  cout << "\x1b[33mI close the file after I put the payment "
          "information.\x1b[0m"
       << std::endl;

  cout << "\x1b[33m\nI open the file to read the payment information.\x1b[0m\n";
  readPaymentConsole("../payment_statement.txt");
  cout << "\x1b[33mI close the file after i read the payment "
          "information.\x1b[0m"
       << std::endl;

  cout << "\x1b[0m";
  return 0;
}