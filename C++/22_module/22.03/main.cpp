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
 * @version   0.1
 * @date      25-03-2021
 * @copyright Copyright (c) 2021
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using std::cin;
using std::cout;

/**
 * @brief     information about payments per person
 */
struct Payments {
  std::string name{};
  std::string surname{};
  double payment{};
  std::string paymentDate{};
};

int main() {
  std::ifstream paymentStatementFile("../payment_statement.txt");
  if (!paymentStatementFile) {
    cout << "Error: could not be opened for reading!";
    return 1;
  }

  std::vector<Payments> payments;
  while (paymentStatementFile) {
    std::string inputLine;
    std::getline(paymentStatementFile, inputLine);
    std::stringstream paymentInfo{inputLine};
    Payments personPayment{};
    paymentInfo >> personPayment.name;
    paymentInfo >> personPayment.surname;
    paymentInfo >> personPayment.payment;
    paymentInfo >> personPayment.paymentDate;

    payments.push_back(personPayment);
  }
  payments.pop_back();
  payments.shrink_to_fit();

  for (const auto &person : payments) {
    cout << person.name << " " << person.surname << " " << person.payment << " "
         << person.paymentDate << std::endl;
  }

  {
    double sum{};
    for (const auto &person : payments) sum += person.payment;
    cout << "\nTotal of all payments: " << sum << "\n";

    double maxPayment{payments[0].payment};
    for (auto i{payments.cbegin() + 1}; i != payments.cend(); ++i)
      if (i->payment > maxPayment) maxPayment = i->payment;

    cout << "\nMaximum payment: " << maxPayment << "\n";
  }

  paymentStatementFile.close();
  cout << std::endl;
  return 0;
}