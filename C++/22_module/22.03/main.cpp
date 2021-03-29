/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 3.
 * Реализуйте программу чтения информации из ведомости по учёту выплат. Сама
 * ведомость представляет собой следующую таблицу:
    имя и фамилия человека;
    количество денег, которые были выплачены лицу;
    дата выплаты в формате ДД.ММ.ГГГГ.
 * На основе данных из ведомости следует подсчитать общее количество выплаченных
 * средств и определить человека с максимальной суммой выплат.
 * @version   0.2
 * @date      25-03-2021
 * @copyright Copyright (c) 2021
 */

#include <fstream>
#include <iostream>
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

int main() {
  std::ifstream paymentStatementFile("../payment_statement.txt");
  if (!paymentStatementFile) {
    cout << "Error: could not be opened for reading!";
    return 1;
  }

  double sum{};
  double maxPayment{};
  while (paymentStatementFile) {
    std::string inputLine;
    std::getline(paymentStatementFile, inputLine);
    std::stringstream paymentInfo{inputLine};
    Payments personPayment{};
    paymentInfo >> personPayment.name;
    paymentInfo >> personPayment.surname;
    paymentInfo >> personPayment.payment;
    paymentInfo >> personPayment.paymentDate;
    if (!inputLine.empty())
      cout << personPayment.name << "\t" << personPayment.surname << " "
           << personPayment.payment << "\t" << personPayment.paymentDate
           << std::endl;

    sum += personPayment.payment;
    if (personPayment.payment > maxPayment) maxPayment = personPayment.payment;
  }
  cout << "\nTotal of all payments: " << sum;
  cout << "\nMaximum payment: " << maxPayment << std::endl;

  paymentStatementFile.close();
  return 0;
}