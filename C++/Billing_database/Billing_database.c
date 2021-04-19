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
  client->name[strlen(client->name) - 1] = '\0';

  printf("Сколько контактных данных: ");
  scanf_s("%d", &client->nContacts);
  fflush(stdin);
  for (int i = 0; i < client->nContacts; ++i) {
    printf("\nВведите контактные данные %d лица:\n", i + 1);
    printf("Введите ФИО: ");
    fgets(client->contacts[i].name, 256, stdin);
    client->contacts[i].name[strlen(client->contacts[i].name) - 1] = '\0';

    printf("Введите адрес: ");
    fgets(client->contacts[i].address, 256, stdin);
    client->contacts[i].address[strlen(client->contacts[i].address) - 1] = '\0';

    printf("Введите номер телефона: ");
    readPhone(client->contacts[i].phone);

    printf("Введите электронную почту: ");
    fgets(client->contacts[i].email, 64, stdin);
    client->contacts[i].email[strlen(client->contacts[i].email) - 1] = '\0';
  }

  printf("Сколько оказано услуг: ");
  scanf_s("%d", &client->nServices);
  fflush(stdin);
  for (int i = 0; i < client->nServices; ++i) {
    printf("Введите название %d услуги: ", i + 1);
    fgets(client->services[i].service, 150, stdin);
    client->services[i].service[strlen(client->services[i].service) - 1] = '\0';

    // TODO Добавить другие поля

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

  printf("\nВведите текущий баланс: ");
  scanf_s("%lf", &client->balance.balance);
  // printf("Введите поступления на счет: ");
  // scanf_s("%lf", &client->balance.receiveFunds);
  // printf("Введите списание за оказание услуг: ");
  // scanf_s("%lf", &client->balance.payment);
  // printf("Введите размер максимального кредита: ");
  // scanf_s("%lf", &client->balance.maxCredit);
  // printf("Введите сроки погашения: ");
  // {
  //   Date date;
  //   while (!readDate(&date)) {
  //   }
  //   client->balance.date.day = date.day;
  //   client->balance.date.month = date.month;
  //   client->balance.date.year = date.year;
  //   client->balance.date.time.hour = date.time.hour;
  //   client->balance.date.time.minute = date.time.minute;
  //   fflush(stdin);
  // }

  struct node* temp;
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
    struct node* ptr = start;
    while (ptr->next != NULL) ptr = ptr->next;
    ptr->next = temp;
  }
}

void removeClient(const char* clientName) {
  if (start == NULL) {
    printf("\nНет клиентов\n");
    return;
  }

  struct node* ptr = start;
  if (strcmp(clientName, start->data->name) == 0) {
    start = start->next;
    free(ptr);
  } else {
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

void readDataClient(const char* clientName) {
  if (start == NULL) {
    printf("\nНет данных");
    return;
  }

  struct node* ptr = start;
  while (ptr != NULL && strcmp(ptr->data->name, clientName) != 0)
    ptr = ptr->next;

  if (ptr == NULL) {
    printf("\nНет данных");
    return;
  }
  printf("ФИО или название организации: %s\n", ptr->data->name);

  puts("\nКонтактные лица:");
  for (int i = 0; i < ptr->data->nContacts; ++i) {
    printf("%d контактное лицо:\n", i + 1);
    printf("  ФИО: %s\n", ptr->data->contacts[i].name);
    printf("  Адрес: %s\n", ptr->data->contacts[i].address);
    printf("  Телефон: %s\n", ptr->data->contacts[i].phone);
    printf("  email: %s\n", ptr->data->contacts[i].email);
  }

  puts("\nСписок оказываемых услуг:");
  for (int i = 0; i < ptr->data->nServices; ++i) {
    printf("Услуга %d: %s  Дата: %02u.%02u.%u %02u:%02u\n", i + 1,
           ptr->data->services[i].service, ptr->data->services[i].date.day,
           ptr->data->services[i].date.month, ptr->data->services[i].date.year,
           ptr->data->services[i].date.time.hour,
           ptr->data->services[i].date.time.minute);
  }
  puts("\nСостояние счета клиента:");
  printf(
      "Баланс: %0.2lf\nПоступления на счет: %0.2lf\nСписания за оказание "
      "услуг: %0.2lf\nРазмер максимального кредита: %0.2lf\nСрок погашения "
      "кредита: %02u.%02u.%u %02u:%02u\n",
      ptr->data->balance.balance, ptr->data->balance.receiveFunds,
      ptr->data->balance.payment, ptr->data->balance.maxCredit,
      ptr->data->balance.date.day, ptr->data->balance.date.month,
      ptr->data->balance.date.year, ptr->data->balance.date.time.hour,
      ptr->data->balance.date.time.minute);
}

void editClient(const char* clientName) {
  if (start == NULL) {
    printf("\nНет данных");
    return;
  }

  struct node* ptr = start;
  while (ptr != NULL && strcmp(ptr->data->name, clientName) != 0)
    ptr = ptr->next;

  if (ptr == NULL) {
    printf("\nНет данных");
    return;
  }

  char temp[256];
  puts("Если не хотите изменять данные -- нажмите \"ВВОД\"");
  printf("Введите новые ФИО: ");
  fgets(temp, 256, stdin);
  if (strcmp(temp, "\n") != 0) {
    temp[strlen(temp) - 1] = '\0';
    memmove(ptr->data->name, temp, sizeof(temp));
  }

  printf("\nВведите контактные данные лица для изменения: ");
  fgets(temp, 256, stdin);
  if (strcmp(temp, "\n") != 0) {
    temp[strlen(temp) - 1] = '\0';
    int found = 0;  // Если не нашли контактное лицо, то false.
    for (int i = 0; i < ptr->data->nContacts; ++i) {
      if (strcmp(ptr->data->contacts[i].name, temp) == 0) {
        printf("Введите новые ФИО контактного лица: ");
        fgets(temp, 256, stdin);
        if (strcmp(temp, "\n") != 0) {
          temp[strlen(temp) - 1] = '\0';
          memmove(ptr->data->contacts[i].name, temp, 256);
        }

        printf("Введите новый адрес контактного лица: ");
        fgets(temp, 256, stdin);
        if (strcmp(temp, "\n") != 0) {
          temp[strlen(temp) - 1] = '\0';
          memmove(ptr->data->contacts[i].address, temp, 256);
        }

        printf("Введите новый телефон контактного лица: ");
        fgets(temp, 12, stdin);
        if (strcmp(temp, "\n") != 0) {
          temp[strlen(temp) - 1] = '\0';
          if (!checkPhone(temp, strlen(temp))) readPhone(temp);
          memmove(ptr->data->contacts[i].phone, temp, 12);
        }

        printf("Введите новый электронный адрес контактного лица: ");
        fgets(temp, 64, stdin);
        if (strcmp(temp, "\n") != 0) {
          temp[strlen(temp) - 1] = '\0';
          memmove(ptr->data->contacts[i].email, temp, 64);
        }

        found = 1;
        break;
      }
    }
    if (!found) puts("Контактное лицо не найдено!");
  }

  printf("\nВведите услугу для изменения: ");
  fgets(temp, 256, stdin);
  if (strcmp(temp, "\n") != 0) {
    temp[strlen(temp) - 1] = '\0';
    int found = 0;  // Если не нашли услугу, то false.
    for (int i = 0; i < ptr->data->nServices; ++i) {
      if (strcmp(ptr->data->services[i].service, temp) == 0) {
        printf("Введите новое название услуги: ");
        fgets(temp, 150, stdin);
        if (strcmp(temp, "\n") != 0) {
          temp[strlen(temp) - 1] = '\0';
          memmove(ptr->data->services[i].service, temp, 150);
        }

        // TODO Добавить изменения других полей

        printf("Введите новую дату услуги: ");
        while (!readDate(&ptr->data->services[i].date)) {
        }
        found = 1;
        break;
      }
    }
    if (!found) puts("Услуга не найдена!");
  }

  // TODO изменения баланса
}

// TODO Добавление и удаление данных о клиенте (контакты)
void removeContact(const char* clientName) {}

// TODO Добавление и удаление услуги
void removeService(const char* clientName) {}

void listOfClients() {
  if (start == NULL) {
    printf("\nНет данных");
    return;
  }

  struct node* ptr = start;
  int num = 1;
  while (ptr != NULL) {
    printf("\nКлиент № %02d:\n", num);
    readDataClient(ptr->data->name);
    ptr = ptr->next;
    ++num;
  }
}

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

int checkPhone(char* phone, const int length) {
  for (int j = 0; j < length; ++j) {
    if (!isdigit(phone[j])) {
      puts("Ошибка в номере телефона! Должны быть только цифры");
      return 0;
    }
  }
  return 1;
}

void readPhone(char* phone) {
  do {
    fgets(phone, 12, stdin);
    phone[strlen(phone) - 1] = '\0';
  } while (!checkPhone(phone, strlen(phone)));
}