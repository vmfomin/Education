/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задание 4. Реализация симуляции банкомата.
 * Требуется реализовать упрощённую симуляцию работы банкомата. В банкомате
 * могут храниться только бумажные купюры номиналом от 100 до 5000 рублей.
 * Максимально в банкомате может храниться только 1000 купюр. Все они
 * записываются в отдельный файл. У банкомата, как у устройства, две основных
 * операции — снятие денег пользователем и наполнение деньгами инкассаторами
 * банка.
 * Наполнение банкомата происходит, если при старте программы в консоль вводится
 * символ плюс “+”.  Количество купюр рассчитывается так, чтобы банкомат был
 * заполнен полностью. Все купюры при этом выбираются случайным образом.
 * Если на старте программы в консоль вводится минус (“-”), то симулируется
 * снятие пользователем денег. Пользователь указывает сумму с точностью до 100
 * рублей. Мы будем считать, что каждый клиент обладает неограниченным балансом
 * в системе и теоретически может снять любую сумму. На практике, если данная
 * сумма не может быть снята из-за отсутствия подходящих денег в машине,
 * показывается сообщение, что эта операция невозможна.
 * После выполнения любой из операций программа завершает выполнение. Состояние
 * банкомата должно храниться в отдельном бинарном файле, автономно.
 * @version   0.1
 * @date      05-04-2021
 * @copyright Copyright (c) 2021
 */

#include <fstream>
#include <iostream>
#include <iterator>
#include <map>

using std::cin;
using std::cout;
using std::endl;

void atmInitStatus(std::map<int32_t, int32_t>&, uint32_t&);
void addCash(std::map<int32_t, int32_t>&, uint32_t&);
void outputCash(std::map<int32_t, int32_t>&, uint32_t&);
void computeBanknote(std::map<int32_t, int32_t>&, int32_t&, const int32_t&);
void changeStatusAtm(std::map<int32_t, int32_t>&);

void computeBanknote(std::map<int32_t, int32_t>& atm, int32_t& money,
                     const int32_t& denomination) {
  if (0 == denomination) return;

  auto banknoteKey{atm.find(denomination)};
  if (banknoteKey->second != 0) {
    int32_t nDenominationBanknotes{money / denomination};
    if (nDenominationBanknotes < banknoteKey->second) {
      money -= nDenominationBanknotes * banknoteKey->first;
      banknoteKey->second -= nDenominationBanknotes;
    } else {
      money -= banknoteKey->first * banknoteKey->second;
      banknoteKey->second = 0;
    }
  }
}

void changeStatusAtm(std::map<int32_t, int32_t>& atm) {
  std::ofstream bank("../bank.bin", std::ios::binary);
  if (!bank) {
    cout << "Error: could not be opened!";
    return;
  }

  for (const auto& i : atm) bank << i.first << " " << i.second << endl;
  bank.close();
}

void atmInitStatus(std::map<int32_t, int32_t>& atm, uint32_t& nBanknotes) {
  std::ifstream bank("../bank.bin", std::ios::binary);
  if (!bank) {
    cout << "Error: could not be opened!";
    return;
  }

  for (auto iter{atm.begin()}; iter != atm.end(); ++iter) {
    int32_t banknote{};
    bank >> banknote;
    if (banknote == iter->first) bank >> iter->second;
  }

  for (const auto& i : atm) nBanknotes += i.second;
  bank.close();
}

void addCash(std::map<int32_t, int32_t>& atm, uint32_t& nBanknotes) {
  if (1000 == nBanknotes) {
    cout << "Sorry. The ATM is full. Please, select another operation";
    return;
  }

  cout << "Enter your cash to ATM. For exit enter \"0\"\n";
  while (true) {
    int32_t banknote;
    cin >> banknote;
    if (0 == banknote) break;

    auto banknoteKey{atm.find(banknote)};
    if (banknote == banknoteKey->first) {
      ++banknoteKey->second;
      ++nBanknotes;
    } else {
      cout << "Error: invalid banknote!" << endl;
    }

    if (1000 == nBanknotes) {
      cout << "The ATM is full. You can only withdraw cash." << endl;
      break;
    }
  }
  changeStatusAtm(atm);
}

void outputCash(std::map<int32_t, int32_t>& atm, uint32_t& nBanknotes) {
  if (0 == nBanknotes) {
    cout << "Sorry. The ATM is empty. Please, select another operation";
    return;
  }

  std::ifstream bank("../bank.bin", std::ios::binary);
  if (!bank) {
    cout << "Error: could not be opened!";
    return;
  }

  cout << "Enter the withdrawal amount: ";
  int32_t money;

  do {
    cin >> money;
    if (0 == money % 100 && 0 != money)
      break;
    else
      std::cout
          << "Invalid amount, the amount of the requested funds must be a "
             "multiple of 100\n";
  } while (true);

  int32_t maxSumAtm{};
  for (auto& i : atm) maxSumAtm += i.first * i.second;

  if (money <= maxSumAtm) {
    int32_t tempMoney{money};
    if (tempMoney >= 5000) computeBanknote(atm, tempMoney, 5000);
    if (tempMoney >= 2000) computeBanknote(atm, tempMoney, 2000);
    if (tempMoney >= 1000) computeBanknote(atm, tempMoney, 1000);
    if (tempMoney >= 500) computeBanknote(atm, tempMoney, 500);
    if (tempMoney >= 200) computeBanknote(atm, tempMoney, 200);
    if (tempMoney >= 100) computeBanknote(atm, tempMoney, 100);

    bank.close();
    if (0 == tempMoney) {
      changeStatusAtm(atm);
      cout << "Amount of funds withdrawn: " << money;
    } else {
      cout << "The operation cannot be performed: there are not enough "
              "banknotes of the required denomination!\n";
    }
  } else {
    cout << "Insufficient funds at the ATM to withdraw cash";
    bank.close();
  }
}

int main() {
  cout << "\x1b[2J";
  std::map<int32_t, int32_t> atm{
      {100, 0}, {200, 0}, {500, 0}, {1000, 0}, {2000, 0}, {5000, 0},
  };
  uint32_t nBanknotes{};
  atmInitStatus(atm, nBanknotes);

  cout << "Do you want to withdraw or deposit cash?\n"
       << "Enter \"-\" for withdraw or \"+\" for deposit cash:" << endl;
  char choice;

  do {
    cin >> choice;
  } while ('-' != choice && '+' != choice);

  '+' == choice ? addCash(atm, nBanknotes) : outputCash(atm, nBanknotes);

  cout << "\x1b[0m" << endl;
  return 0;
}