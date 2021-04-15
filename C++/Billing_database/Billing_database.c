/**
 * @file      Billing_database.c
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Биллинговая база оператора связи.
 * @version   0.1
 * @date      13-04-2021
 * @copyright Copyright (c) 2021
 */

#include "Billing_database.h"

void addClient() {
  Client* client = (Client*)malloc(sizeof(Client));
  printf("Введите ФИО или наименование организации: ");
  fgets(client->name, 256, stdin);
  client->name[strlen(client->name)] = '\0';

  printf("Сколько контактных данных: ");
  scanf_s("%d", &client->nContactDetails);
  fflush(stdin);
  for (int i = 0; i < client->nContactDetails; ++i) {
    printf("Введите контактные данные %d лица: ", i + 1);
    fgets(client->contactDetails[i], 512, stdin);
    client->contactDetails[i][strlen(client->contactDetails[i])] = '\0';
  }

  printf("Сколько оказано услуг: ");
  scanf_s("%d", &client->nServices);
  fflush(stdin);
  for (int i = 0; i < client->nServices; ++i) {
    printf("Введите название %d услуги: ", i + 1);
    fgets(client->services[i].service, 150, stdin);
    client->services[i].service[strlen(client->services[i].service)] = '\0';

    printf("Введите дату оказания услуги: ");
    Date date;
    while (!readDate(&date)) {
    }
    client->services[i].date.day = date.day;
    client->services[i].date.month = date.month;
    client->services[i].date.year = date.year;
    client->services[i].date.time.hour = date.time.hour;
    client->services[i].date.time.minute = date.time.minute;
    fflush(stdin);
  }

  printf("Введите текущий баланс: ");
  scanf_s("%lf", &client->balance.balance);
  printf("Введите поступления на счет: ");
  scanf_s("%lf", &client->balance.receiveFunds);
  printf("Введите списание за оказание услуг: ");
  scanf_s("%lf", &client->balance.payment);
  printf("Введите размер максимального кредита: ");
  scanf_s("%lf", &client->balance.maxCredit);
  printf("Введите сроки погашения: ");
  {
    Date date;
    while (!readDate(&date)) {
    }
    client->balance.date.day = date.day;
    client->balance.date.month = date.month;
    client->balance.date.year = date.year;
    client->balance.date.time.hour = date.time.hour;
    client->balance.date.time.minute = date.time.minute;
    fflush(stdin);
  }

  struct node* temp;
  struct node* ptr;
  temp = (struct node*)malloc(sizeof(struct node));
  if (temp == NULL) {
    puts("Не достаточно памяти!!!");
    exit(0);
  }
  temp->data = client;
  temp->next = NULL;
  if (start == NULL) {
    start = temp;
  } else {
    ptr = start;
    while (ptr->next != NULL) ptr = ptr->next;
    ptr->next = temp;
  }
}

void removeClient(const char* clientName) {
  struct node* ptr;

  if (start == NULL) {
    printf("\nНет клиентов\n");
    return;
  } else {
    if (strcmp(clientName, start->data->name) == 0) {
      ptr = start;
      start = start->next;
      free(ptr);
    } else {
      ptr = start;
      while (ptr != NULL && strcmp(clientName, ptr->data->name) != 0) {
        start = ptr;
        ptr = ptr->next;
      }
      if (ptr == NULL) {
        printf("\nТакой клиент не найден\n");
        return;
      }

      start->next = ptr->next;
      free(ptr->data);
    }
  }
}

void readDataClient(const char* clientName) {}

void exitProgram() {
  if (start != NULL) {
    while (start->next != NULL) {
      free(start->data);
      start = start->next;
    }
    free(start);
  }
  start = NULL;
}

int checkDate(const Date* date) {
  if (date->day > 31 || date->month > 12 || date->year < 1900 ||
      date->year > 2120 || date->time.hour > 24 || date->time.minute > 60) {
    puts("Ошибочная дата! Введите снова!");
    return 0;
  }
  return 1;
}

int readDate(Date* date) {
  scanf_s("%d %d %d %d %d", &date->day, &date->month, &date->year,
          &date->time.hour, &date->time.minute);
  return checkDate(date) ? 1 : 0;
}