/**
 * @file      Billing_database.h
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Биллинговая база оператора связи.
 * Система управления информацией о клиентах, оказываемых им услугах и об оплате
 * услуг.
 * @version   0.1
 * @date      13-04-2021
 * @copyright Copyright (c) 2021
 */

#ifndef INC_BILLING_DATABASE_H_
#define INC_BILLING_DATABASE_H_

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct Date_t Date;
typedef struct Hour_t Hour;
typedef struct ContactDetails_t Contacts;
typedef struct Services_t Services;
typedef struct Balance_t Balance;

struct Hour_t {
  unsigned int hour;
  unsigned int minute;
};

struct Date_t {
  unsigned int day;
  unsigned int month;
  unsigned int year;
  Hour time;
};

struct ContactDetails_t {
  char name[256];     // контактное лицо
  char address[256];  // адрес
  char phone[256];    // телефон
  char email[64];     // e-mail
};

struct Services_t {
  char service[150];  // Название услуги
  Date date;          // время оказания
};

struct Balance_t {
  double balance;       // Баланс
  double receiveFunds;  // Поступления на счет
  double payment;  // Списания за оказание услуг связи
  // Ограничения:
  double maxCredit;  // размер максимального кредита
  Date date;         // сроки его погашения
};

typedef struct {
  // Наименование или ФИО
  char name[256];
  // Количество контактных лиц.
  int nContacts;
  // контактные лица, адрес(а), телефон(ы), e-mail(ы)
  Contacts contacts[50];
  // Количество оказанных услуг.
  int nServices;
  // История услуг: услуги, в какое время оказывались
  Services services[50];
  Balance balance;
} Client;

struct node {
  Client* data;
  struct node* next;
};

extern struct node* start;

/**
 * @brief     Добавление нового клиента.
 */
void addClient();

/**
 * @brief     Удаление данных клиента.
 */
void removeClient(const char*);

/**
 * @brief     Чтение данных о клиенте.
 */
void readDataClient(const char*);

/**
 * @brief     Редактирование данных о клиенте
 */
void editClient(const char*);

// TODO Получение списка клиентов в заданном интервале времени

// TODO Получение списка клиентов по характеристикам их счетов

/**
 * @brief     Получение списка всех клиентов
 */
void listOfClients();

/**
 * @brief     Выход из программы.
 */
void exitProgram();

/**
 * @brief     Проверка даты
 * @return    int          0 -- неверная дата, 1 -- верная.
 */
int checkDate(const Date*);

/**
 * @brief     Чтение даты из консоли.
 * @return    int          0 -- неверная дата, 1 -- верная.
 */
int readDate(Date*);

#endif /* INC_BILLING_DATABASE_H_ */