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
  do {
    scanf_s("%d", &client->nContacts);
    fflush(stdin);
  } while (client->nContacts > 50);

  for (int i = 0; i < client->nContacts; ++i) {
    printf("\nВведите контактные данные %d лица:\n", i + 1);
    printf("Введите ФИО: ");
    fgets(client->contacts[i].name, 256, stdin);
    client->contacts[i].name[strlen(client->contacts[i].name) - 1] = '\0';

    printf("Введите адрес: ");
    fgets(client->contacts[i].address, 256, stdin);
    client->contacts[i].address[strlen(client->contacts[i].address) - 1] = '\0';

    printf("Введите номер телефона: ");
    readNumber(client->contacts[i].phone);

    printf("Введите электронную почту: ");
    fgets(client->contacts[i].email, 64, stdin);
    client->contacts[i].email[strlen(client->contacts[i].email) - 1] = '\0';
  }

  printf("\nСколько оказано услуг: ");
  do {
    scanf_s("%d", &client->nServices);
    fflush(stdin);
  } while (client->nServices > 50);

  for (int i = 0; i < client->nServices; ++i) {
    printf("\nВведите название %d услуги: ", i + 1);
    fgets(client->services[i].service, 150, stdin);
    client->services[i].service[strlen(client->services[i].service) - 1] = '\0';

    printf("Введите номер услуги: ");
    readNumber(client->services[i].numService);

    printf("Введите группу номеров: ");
    fgets(client->services[i].groupNumbers, 100, stdin);
    client->services[i]
        .groupNumbers[strlen(client->services[i].groupNumbers) - 1] = '\0';

    printf("Введите интернет тариф: ");
    fgets(client->services[i].internet, 50, stdin);
    client->services[i].internet[strlen(client->services[i].internet) - 1] =
        '\0';

    printf("Введите количество SMS: ");
    scanf_s("%d", &client->services[i].sms);
    fflush(stdin);

    printf("Введите специальные предложения: ");
    fgets(client->services[i].specialOffer, 100, stdin);
    client->services[i]
        .specialOffer[strlen(client->services[i].specialOffer) - 1] = '\0';

    printf("Введите дату оказания услуги: ");
    while (!readDate(&client->services[i].date)) {
    }
  }

  printf("\nВведите данные баланса: ");
  readBalance(&client->balance);
  printf("Введите сроки погашения: ");
  while (!readDate(&client->balance.date)) {
  }

  struct node* temp;
  temp = (struct node*)malloc(sizeof(struct node));
  if (temp == NULL) {
    puts("Не достаточно памяти!!!");
    exit(0);
  }
  temp->data = client;
  temp->next = NULL;
  if (head == NULL) {
    head = temp;
  } else {
    struct node* ptr = head;
    while (ptr->next != NULL) ptr = ptr->next;
    ptr->next = temp;
  }
}

void removeClient(const char* clientName) {
  if (head == NULL) {
    printf("\nНет клиентов\n");
    return;
  }

  struct node* ptr = head;
  struct node* temp = head;
  if (strcmp(clientName, head->data->name) == 0) {
    head = head->next;
    free(ptr);
  } else {
    while (ptr != NULL && strcmp(clientName, ptr->data->name) != 0) {
      temp = ptr;
      ptr = ptr->next;
    }

    if (ptr == NULL) {
      printf("\nТакой клиент не найден\n");
      return;
    }

    temp->next = ptr->next;
    free(ptr->data);
    free(ptr);
  }
}

void readDataClient(const char* clientName) {
  if (head == NULL) {
    printf("\nНет данных");
    return;
  }

  struct node* ptr = head;
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
    printf("Услуга № %d:\n", i + 1);
    printf("  Название услуги: %s\n", ptr->data->services[i].service);
    printf("  Номер услуги: %d\n", ptr->data->services[i].numService);
    printf("  Группа номеров: %s\n", ptr->data->services[i].groupNumbers);
    printf("  Интернет: %s\n", ptr->data->services[i].internet);
    printf("  SMS: %d\n", ptr->data->services[i].sms);
    printf("  Специальные предложения: %s\n",
           ptr->data->services[i].specialOffer);
    printf("  Дата: %02u.%02u.%u %02u:%02u\n\n",
           ptr->data->services[i].date.day, ptr->data->services[i].date.month,
           ptr->data->services[i].date.year,
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
  if (head == NULL) {
    printf("\nНет данных");
    return;
  }

  struct node* ptr = head;
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
          if (!checkNumber(temp, strlen(temp))) readNumber(temp);
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

        printf("Введите номер услуги: ");
        fgets(temp, 150, stdin);
        if (strcmp(temp, "\n") != 0) {
          temp[strlen(temp) - 1] = '\0';
          memmove(ptr->data->services[i].numService, temp, 12);
        }

        printf("Введите группу номеров: ");
        fgets(temp, 150, stdin);
        if (strcmp(temp, "\n") != 0) {
          temp[strlen(temp) - 1] = '\0';
          memmove(ptr->data->services[i].groupNumbers, temp, 100);
        }

        printf("Введите интернет тариф: ");
        fgets(temp, 150, stdin);
        if (strcmp(temp, "\n") != 0) {
          temp[strlen(temp) - 1] = '\0';
          memmove(ptr->data->services[i].internet, temp, 50);
        }

        printf("Введите количество SMS: ");
        fgets(temp, 150, stdin);
        if (strcmp(temp, "\n") != 0) {
          temp[strlen(temp) - 1] = '\0';
          memmove(ptr->data->services[i].sms, temp, 12);
        }

        printf("Введите специальные предложения: ");
        fgets(temp, 150, stdin);
        if (strcmp(temp, "\n") != 0) {
          temp[strlen(temp) - 1] = '\0';
          memmove(ptr->data->services[i].specialOffer, temp, 100);
        }

        printf("Введите новую дату услуги: ");
        while (!readDate(&ptr->data->services[i].date)) {
        }
        found = 1;
        break;
      }
    }
    if (!found) puts("Услуга не найдена!");
  }

  printf("\nВведите новый текущий баланс: ");
  fgets(temp, 150, stdin);
  if (strcmp(temp, "\n") != 0) {
    temp[strlen(temp) - 1] = '\0';
    ptr->data->balance.balance = atoi(temp);
  }

  printf("Введите изменения поступления на счет: ");
  fgets(temp, 150, stdin);
  if (strcmp(temp, "\n") != 0) {
    temp[strlen(temp) - 1] = '\0';
    ptr->data->balance.receiveFunds = atoi(temp);
  }

  printf("Введите изменения списания за оказание услуг: ");
  fgets(temp, 150, stdin);
  if (strcmp(temp, "\n") != 0) {
    temp[strlen(temp) - 1] = '\0';
    ptr->data->balance.payment = atoi(temp);
  }

  printf("Введите изменения размера максимального кредита: ");
  fgets(temp, 150, stdin);
  if (strcmp(temp, "\n") != 0) {
    temp[strlen(temp) - 1] = '\0';
    ptr->data->balance.maxCredit = atoi(temp);
  }

  printf("Введите  изменение срока погашения: ");
  while (!readDate(&ptr->data->balance.date)) {
  }
}

void addContact(const char* clientName) {
  if (head == NULL) {
    printf("\nНет данных");
    return;
  }

  struct node* ptr = head;
  while (ptr != NULL && strcmp(ptr->data->name, clientName) != 0)
    ptr = ptr->next;

  if (ptr == NULL) {
    printf("\nНет данных");
    return;
  }

  if (50 == ptr->data->nContacts) {
    printf("\nСписок контактов полностью заполнен!");
    return;
  }

  ++ptr->data->nContacts;
  int currentContact = ptr->data->nContacts - 1;
  printf("Введите ФИО: ");
  fgets(ptr->data->contacts[currentContact].name, 256, stdin);
  ptr->data->contacts[currentContact]
      .name[strlen(ptr->data->contacts[currentContact].name) - 1] = '\0';

  printf("Введите адрес: ");
  fgets(ptr->data->contacts[currentContact].address, 256, stdin);
  ptr->data->contacts[currentContact]
      .address[strlen(ptr->data->contacts[currentContact].address) - 1] = '\0';

  printf("Введите номер телефона: ");
  fgets(ptr->data->contacts[currentContact].phone, 12, stdin);
  ptr->data->contacts[currentContact]
      .phone[strlen(ptr->data->contacts[currentContact].phone) - 1] = '\0';

  printf("Введите электронную почту: ");
  fgets(ptr->data->contacts[currentContact].email, 64, stdin);
  ptr->data->contacts[currentContact]
      .email[strlen(ptr->data->contacts[currentContact].email) - 1] = '\0';
}

void removeContact(const char* clientName) {
  if (head == NULL) {
    printf("\nНет данных");
    return;
  }

  struct node* ptr = head;
  while (ptr != NULL && strcmp(ptr->data->name, clientName) != 0)
    ptr = ptr->next;

  if (ptr == NULL) {
    printf("\nНет данных");
    return;
  }

  if (ptr->data->nContacts <= 0) {
    printf("\nНет контактов");
    return;
  }

  char temp[256];
  printf("\nВведите контактные данные лица для удаления: ");
  fgets(temp, 256, stdin);
  if (strcmp(temp, "\n") != 0) {
    temp[strlen(temp) - 1] = '\0';
    int found = 0;  // Если не нашли контактное лицо, то false.
    for (int i = 0; i < ptr->data->nContacts; ++i) {
      if (strcmp(ptr->data->contacts[i].name, temp) == 0) {
        for (int j = i; j < ptr->data->nContacts; ++j) {
          ++i;
          if (ptr->data->nContacts == i) break;
          memmove(&ptr->data->contacts[j], &ptr->data->contacts[i],
                  sizeof(Contacts));
        }
        found = 1;
        --ptr->data->nContacts;
        break;
      }
    }
    if (!found) puts("Контактное лицо не найдено!");
  }
}

void addService(const char* clientName) {
  if (head == NULL) {
    printf("\nНет данных");
    return;
  }

  struct node* ptr = head;
  while (ptr != NULL && strcmp(ptr->data->name, clientName) != 0)
    ptr = ptr->next;

  if (ptr == NULL) {
    printf("\nНет данных");
    return;
  }

  if (50 == ptr->data->nServices) {
    printf("\nСписок услуг полностью заполнен!");
    return;
  }

  ++ptr->data->nServices;
  int currentService = ptr->data->nServices - 1;
  printf("\nВведите название услуги: ");
  fgets(ptr->data->services[currentService].service, 150, stdin);
  ptr->data->services[currentService]
      .service[strlen(ptr->data->services[currentService].service) - 1] = '\0';

  printf("Введите номер услуги: ");
  scanf_s("%d", &ptr->data->services[currentService].numService);
  fflush(stdin);

  printf("Введите группу номеров: ");
  fgets(ptr->data->services[currentService].groupNumbers, 100, stdin);
  ptr->data->services[currentService]
      .groupNumbers[strlen(ptr->data->services[currentService].groupNumbers) -
                    1] = '\0';

  printf("Введите интернет тариф: ");
  fgets(ptr->data->services[currentService].internet, 50, stdin);
  ptr->data->services[currentService]
      .internet[strlen(ptr->data->services[currentService].internet) - 1] =
      '\0';

  printf("Введите количество SMS: ");
  scanf_s("%d", &ptr->data->services[currentService].sms);
  fflush(stdin);

  printf("Введите специальные предложения: ");
  fgets(ptr->data->services[currentService].specialOffer, 100, stdin);
  ptr->data->services[currentService]
      .specialOffer[strlen(ptr->data->services[currentService].specialOffer) -
                    1] = '\0';

  printf("Введите дату оказания услуги: ");

  while (!readDate(&ptr->data->services[currentService].date)) {
  }
}

void removeService(const char* clientName) {
  if (head == NULL) {
    printf("\nНет данных");
    return;
  }

  struct node* ptr = head;
  while (ptr != NULL && strcmp(ptr->data->name, clientName) != 0)
    ptr = ptr->next;

  if (ptr == NULL) {
    printf("\nНет данных");
    return;
  }

  if (ptr->data->nServices <= 0) {
    printf("\nНет услуг");
    return;
  }

  char temp[256];
  printf("\nВведите услугу для удаления: ");
  fgets(temp, 256, stdin);
  if (strcmp(temp, "\n") != 0) {
    temp[strlen(temp) - 1] = '\0';
    int found = 0;  // Если не нашли контактное лицо, то false.
    for (int i = 0; i < ptr->data->nServices; ++i) {
      if (strcmp(ptr->data->services[i].service, temp) == 0) {
        for (int j = i; j < ptr->data->nServices; ++j) {
          ++i;
          if (ptr->data->nServices == i) break;
          memmove(&ptr->data->services[j], &ptr->data->services[i],
                  sizeof(Services));
        }
        found = 1;
        --ptr->data->nServices;
        break;
      }
    }
    if (!found) puts("Контактное лицо не найдено!");
  }
}

void listOfClientsDateRange(const Date* dateBegin, const Date* dateEnd) {
  if (head == NULL) {
    printf("\nНет данных");
    return;
  }

  int found = 0;
  int nClients = 1;
  struct node* ptr = head;
  while (ptr != NULL) {
    for (int i = 0; i < ptr->data->nServices; ++i) {
      if (ptr->data->services[i].date.year >= dateBegin->year &&
          ptr->data->services[i].date.year <= dateEnd->year &&

          ptr->data->services[i].date.month >= dateBegin->month &&
          ptr->data->services[i].date.month <= dateEnd->month &&

          ptr->data->services[i].date.day >= dateBegin->day &&
          ptr->data->services[i].date.day <= dateEnd->day &&

          ptr->data->services[i].date.time.hour >= dateBegin->time.hour &&
          ptr->data->services[i].date.time.hour <= dateEnd->time.hour &&

          ptr->data->services[i].date.time.minute >= dateBegin->time.minute &&
          ptr->data->services[i].date.time.minute <= dateEnd->time.minute) {
        printf("\nКлиент № %02d:\n", nClients);
        readDataClient(ptr->data->name);
        found = 1;
        ++nClients;
        break;
      }
    }
    ptr = ptr->next;
  }

  if (!found) {
    printf("\nНет клиентов удовлетворяющих условию.");
    return;
  }
}

void listOfClientsBalanceRange(const Balance* minimum, const Balance* maximum) {
  if (head == NULL) {
    printf("\nНет данных");
    return;
  }
  printf("Список клиентов:\n");
  int found = 0;
  int nClients = 1;
  struct node* ptr = head;
  while (ptr != NULL) {
    if (ptr->data->balance.balance >= minimum->balance &&
        ptr->data->balance.balance <= maximum->balance &&

        ptr->data->balance.receiveFunds >= minimum->receiveFunds &&
        ptr->data->balance.receiveFunds <= maximum->receiveFunds &&

        ptr->data->balance.payment >= minimum->payment &&
        ptr->data->balance.payment <= maximum->payment &&

        ptr->data->balance.maxCredit >= minimum->maxCredit &&
        ptr->data->balance.maxCredit <= maximum->maxCredit) {
      printf("\nКлиент № %02d:\n", nClients);
      readDataClient(ptr->data->name);
      found = 1;
      ++nClients;
    }
    ptr = ptr->next;
  }

  if (!found) {
    printf("\nНет клиентов удовлетворяющих условию.");
    return;
  }
}

void listOfAllClients() {
  if (head == NULL) {
    printf("\nНет данных");
    return;
  }

  struct node* ptr = head;
  int nClients = 1;
  while (ptr != NULL) {
    printf("\nКлиент № %02d:\n", nClients);
    readDataClient(ptr->data->name);
    ptr = ptr->next;
    ++nClients;
  }
}

void exitProgram() {
  if (head != NULL) {
    while (head->next != NULL) {
      free(head->data);
      head = head->next;
    }
    free(head);
  }
  head = NULL;
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
  fflush(stdin);
  return checkDate(date) ? 1 : 0;
}

int checkNumber(char* number, const int length) {
  for (int j = 0; j < length; ++j) {
    if (!isdigit(number[j])) {
      puts("Ошибка! Должны быть только цифры");
      return 0;
    }
  }
  return 1;
}

void readNumber(char* number) {
  do {
    fgets(number, 12, stdin);
    number[strlen(number) - 1] = '\0';
  } while (!checkNumber(number, strlen(number)));
}

void readBalance(Balance* balance) {
  printf("\nВведите баланс: ");
  scanf_s("%lf", &balance->balance);
  fflush(stdin);

  printf("Введите поступления на счет: ");
  scanf_s("%lf", &balance->receiveFunds);
  fflush(stdin);

  printf("Введите списание за оказание услуг: ");
  scanf_s("%lf", &balance->payment);
  fflush(stdin);

  printf("Введите размер максимального кредита: ");
  scanf_s("%lf", &balance->maxCredit);
  fflush(stdin);
}