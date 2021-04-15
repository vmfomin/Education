#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct Theatre_t Theatre;
typedef struct Date_t Date;
typedef struct Hour_t Hour;

struct Hour_t {
  int hour;
  int minute;
};

struct Date_t {
  int day;
  int month;
  int year;
  Hour hour;
};

typedef struct {
  Theatre *theatre;
  char title[120];
  char producer[120];
  char actors[100][120];
  int totalActors;
  int duration;
  int countFreeSeatParter;
  int countFreeSeatBalcony;
  int countFreeSeatMezzanine;
  float costSeatParter;
  float costSeatBalcony;
  float costSeatMezzanine;
  Date date[31];
  int totalDate;
} Representation;

typedef struct Theatre_t {
  char title[120];
  char producer[20][120];
  int totalProducer;
  char actors[300][120];
  int totalActors;
  char address[240];
  int totalSeatParter;
  int totalSeatBalcony;
  int totalSeatMezzanine;
  Representation representation[50];
  int totalRepresentation;
} Theatre;

void addTheatre(void);
void removeTheatre(const char *title);
void editTheatre(const char *title);
void displayTheatreInfo(const char *title);
void infoFreeSeatAndCostRepresent(const char *title);
void getRepresentByTheatre(const char *title);
void getRepresentByProducer(const char *title);
void getRepresentByDate(int day, int month, int year);
void getRepresentByActor(const char *actor);

struct node {
  Theatre *data;
  struct node *next;
};

struct node *start = NULL;

//Меню
int main() {
  int command = -1;
  char title[120];
  int d, m, y;
  while (command != 0) {
    puts("\n============= Театральна касса =============");
    puts("Введите 1 чтобы добавить данные по театру;");
    puts("Введите 2 чтобы удалить данные по театру;");
    puts("Введите 3 чтобы редактировать данные по театру;");
    puts("Введите 4 чтобы отобразить данные по театру;");
    puts("Введите 5 чтобы отобразить свободные места и цены по представлению;");
    puts("Введите 6 чтобы найти представление по дате;");
    puts("Введите 7 чтобы найти представление по актеру;");
    puts("Введите 8 чтобы найти представление по театру;");
    puts("Введите 9 чтобы найти представление по режиссёру;");
    puts("Введите 0 чтобы выйти из программы.");
    printf("\nВыберите команду: ");
    scanf_s("%d", &command);
    getchar();
    switch (command) {
      case 1:
        addTheatre();
        break;
      case 2:
        printf("Введите название театра для удаления: ");
        fgets(title, 120, stdin);
        title[strlen(title) - 1] = '\0';
        removeTheatre(title);
        break;
      case 3:
        printf("Введите название театра для редактирования: ");
        fgets(title, 120, stdin);
        title[strlen(title) - 1] = '\0';
        editTheatre(title);
        break;
      case 4:
        printf("Введите название театра: ");
        fgets(title, 120, stdin);
        title[strlen(title) - 1] = '\0';
        displayTheatreInfo(title);
        break;
      case 5:
        printf("Введите название представления: ");
        fgets(title, 120, stdin);
        title[strlen(title) - 1] = '\0';
        infoFreeSeatAndCostRepresent(title);
        break;
      case 6:
        printf("Введите число: ");
        scanf_s("%d", &d);
        printf("Введите месяц: ");
        scanf_s("%d", &m);
        printf("Введите год: ");
        scanf_s("%d", &y);
        getRepresentByDate(d, m, y);
        break;
      case 7:
        printf("Введите данные об актере: ");
        fgets(title, 120, stdin);
        title[strlen(title) - 1] = '\0';
        getRepresentByActor(title);
        break;
      case 8:
        printf("Введите название театра: ");
        fgets(title, 120, stdin);
        title[strlen(title) - 1] = '\0';
        getRepresentByTheatre(title);
        break;
      case 9:
        printf("Введите данные о режиссёре: ");
        fgets(title, 120, stdin);
        title[strlen(title) - 1] = '\0';
        getRepresentByProducer(title);
        break;
    }
  }
  return 0;
}

//Добавление театра
void addTheatre() {
  int i, j, k;
  Theatre *theatre = (Theatre *)malloc(sizeof(Theatre));
  printf("Введите название театра: ");
  fgets(theatre->title, 120, stdin);
  theatre->title[strlen(theatre->title) - 1] = '\0';
  printf("Введите общее кол-во режиссеров в театре: ");
  scanf_s("%d", &theatre->totalProducer);
  getchar();
  for (i = 0; i < theatre->totalProducer; ++i) {
    printf("Введите данные о режиссёре: ");
    fgets(theatre->producer[i], 120, stdin);
    theatre->producer[i][strlen(theatre->producer[i]) - 1] = '\0';
  }
  printf("Введите общее кол-во актеров в театре: ");
  scanf_s("%d", &theatre->totalActors);
  getchar();
  for (i = 0; i < theatre->totalActors; ++i) {
    printf("Введите данные о актере: ");
    fgets(theatre->actors[i], 120, stdin);
    theatre->actors[i][strlen(theatre->actors[i]) - 1] = '\0';
  }
  printf("Введите адрес: ");
  fgets(theatre->address, 240, stdin);
  theatre->address[strlen(theatre->address) - 1] = '\0';
  printf("Введите общее кол-во мест в партере: ");
  scanf_s("%d", &theatre->totalSeatParter);
  getchar();
  printf("Введите общее кол-во мест на балконе: ");
  scanf_s("%d", &theatre->totalSeatBalcony);
  getchar();
  printf("Введите общее кол-во мест в бельэтаже: ");
  scanf_s("%d", &theatre->totalSeatMezzanine);
  getchar();
  // Ввод представления
  printf("Введите общее кол-во представлений в театре: ");
  scanf_s("%d", &theatre->totalRepresentation);
  getchar();
  for (i = 0; i < theatre->totalRepresentation; ++i) {
    theatre->representation[i].theatre = theatre;
    printf("Введите название представления: ");
    fgets(theatre->representation[i].title, 120, stdin);
    theatre->representation[i]
        .title[strlen(theatre->representation[i].title) - 1] = '\0';
    printf("Введите данные о режиссёре представления: ");
    fgets(theatre->representation[i].producer, 120, stdin);
    theatre->representation[i]
        .producer[strlen(theatre->representation[i].producer) - 1] = '\0';
    printf("Введите общее кол-во актеров участвующих в представлении: ");
    scanf_s("%d", &theatre->representation[i].totalActors);
    getchar();
    for (j = 0; j < theatre->representation[i].totalActors; ++j) {
      printf("Введите данные об актере: ");
      fgets(theatre->representation[i].actors[j], 120, stdin);
      theatre->representation[i]
          .actors[j][strlen(theatre->representation[i].actors[j]) - 1] = '\0';
    }
    printf("Введите длительность представления в минутах: ");
    scanf_s("%d", &theatre->representation[i].duration);
    getchar();
    printf("Введите кол-во свободных мест в партере: ");
    scanf_s("%d", &theatre->representation[i].countFreeSeatParter);
    getchar();
    printf("Введите кол-во свободных мест на балконе: ");
    scanf_s("%d", &theatre->representation[i].countFreeSeatBalcony);
    getchar();
    printf("Введите кол-во свободных мест в бельэтаже: ");
    scanf_s("%d", &theatre->representation[i].countFreeSeatMezzanine);
    getchar();
    printf("Введите цену за место в партере: ");
    scanf_s("%f", &theatre->representation[i].costSeatParter);
    getchar();
    printf("Введите цену за место на балконе: ");
    scanf_s("%f", &theatre->representation[i].costSeatBalcony);
    getchar();
    printf("Введите цену за место в бельэтаже: ");
    scanf_s("%f", &theatre->representation[i].costSeatMezzanine);
    getchar();
    printf("Введите кол-во дат проведения представления: ");
    scanf_s("%d", &theatre->representation[i].totalDate);
    getchar();
    for (k = 0; k < theatre->representation[i].totalDate; ++k) {
      printf("Введите число представления: ");
      scanf_s("%d", &theatre->representation[i].date->day);
      getchar();
      printf("Введите месяц представления: ");
      scanf_s("%d", &theatre->representation[i].date->month);
      getchar();
      printf("Введите год представления: ");
      scanf_s("%d", &theatre->representation[i].date->year);
      getchar();
      printf("Введите часы представления: ");
      scanf_s("%d", &theatre->representation[i].date->hour.hour);
      getchar();
      printf("Введите минуты представления: ");
      scanf_s("%d", &theatre->representation[i].date->hour.minute);
      getchar();
      puts("\n");
    }
  }
  struct node *temp, *ptr;
  temp = (struct node *)malloc(sizeof(struct node));
  if (temp == NULL) {
    printf("nНе достаточно памяти:n");
    exit(0);
  }
  temp->data = theatre;
  temp->next = NULL;
  if (start == NULL) {
    start = temp;
  } else {
    ptr = start;
    while (ptr->next != NULL) {
      ptr = ptr->next;
    }
    ptr->next = temp;
  }
}

//Удаление театра
void removeTheatre(const char *title) {
  struct node *temp, *ptr;
  if (start == NULL) {
    printf("\nНет театров\n");
    return;
  } else {
    if (!strcmp(title, start->data->title)) {
      ptr = start;
      start = start->next;
      free(ptr->data);
      free(ptr);
    } else {
      ptr = start;
      temp = start;
      while (ptr != NULL && !strcmp(title, start->data->title)) {
        temp = ptr;
        ptr = ptr->next;
      }
      if (ptr == NULL) {
        printf("\nТакой театр не найден\n");
        return;
      }
      temp->next = ptr->next;
      free(ptr->data);
      free(ptr);
    }
  }
}

//Редактирование театра
void editTheatre(const char *title) {
  int i, j, k;
  if (start == NULL) {
    printf("\nНет данных");
    return;
  } else {
    struct node *ptr = start;
    while (ptr != NULL && strcmp(ptr->data->title, title)) {
      ptr = ptr->next;
    }
    if (ptr == NULL) {
      printf("\nНет данных");
      return;
    }
    Theatre *theatre = ptr->data;
    printf("Введите общее кол-во режиссёров в театре: ");
    scanf_s("%d", &theatre->totalProducer);
    getchar();
    for (i = 0; i < theatre->totalProducer; ++i) {
      printf("Введите данные режиссёра: ");
      fgets(theatre->producer[i], 120, stdin);
      theatre->producer[i][strlen(theatre->producer[i]) - 1] = '\0';
    }
    printf("Введите общее кол-во актеров в театре: ");
    scanf_s("%d", &theatre->totalActors);
    getchar();
    for (i = 0; i < theatre->totalActors; ++i) {
      printf("Введите данные актера: ");
      fgets(theatre->actors[i], 120, stdin);
      theatre->actors[i][strlen(theatre->actors[i]) - 1] = '\0';
    }
    printf("Введите адрес театра: ");
    fgets(theatre->address, 240, stdin);
    theatre->address[strlen(theatre->address) - 1] = '\0';
    printf("Введите общее кол-во мест в партере: ");
    scanf_s("%d", &theatre->totalSeatParter);
    getchar();
    printf("Введите общее кол-во мест на балконе: ");
    scanf_s("%d", &theatre->totalSeatBalcony);
    getchar();
    printf("Введите общее кол-во мест на бельэтаже: ");
    scanf_s("%d", &theatre->totalSeatMezzanine);
    getchar();
    // Ввод представления при редактировании
    printf("Введите общее кол-во представлений в театре: ");
    scanf_s("%d", &theatre->totalRepresentation);
    getchar();
    for (i = 0; i < theatre->totalRepresentation; ++i) {
      theatre->representation[i].theatre = theatre;
      printf("Введите название представления: ");
      fgets(theatre->representation[i].title, 120, stdin);
      theatre->representation[i]
          .title[strlen(theatre->representation[i].title) - 1] = '\0';
      printf("Введите данные об режиссёре представления: ");
      fgets(theatre->representation[i].producer, 120, stdin);
      theatre->representation[i]
          .producer[strlen(theatre->representation[i].producer) - 1] = '\0';
      printf("Введите общее кол-во актеров представления: ");
      scanf_s("%d", &theatre->representation[i].totalActors);
      getchar();
      for (j = 0; j < theatre->representation[i].totalActors; ++j) {
        printf("Введите данные актера: ");
        fgets(theatre->representation[i].actors[j], 120, stdin);
        theatre->representation[i]
            .actors[j][strlen(theatre->representation[i].actors[j]) - 1] = '\0';
      }
      printf("Введите длительность в минутах: ");
      scanf_s("%d", &theatre->representation[i].duration);
      getchar();
      printf("Введите кол-во свободных мест в партере: ");
      scanf_s("%d", &theatre->representation[i].countFreeSeatParter);
      getchar();
      printf("Введите кол-во свободных мест на балконе: ");
      scanf_s("%d", &theatre->representation[i].countFreeSeatBalcony);
      getchar();
      printf("Введите кол-во свободных мест в бельэтажe: ");
      scanf_s("%d", &theatre->representation[i].countFreeSeatMezzanine);
      getchar();
      printf("Введите цену за место в партере: ");
      scanf_s("%f", &theatre->representation[i].costSeatParter);
      getchar();
      printf("Введите цену за место на балконе: ");
      scanf_s("%f", &theatre->representation[i].costSeatBalcony);
      getchar();
      printf("Введите цену за место в бельэтаже: ");
      scanf_s("%f", &theatre->representation[i].costSeatMezzanine);
      getchar();
      printf("Введите кол-во дат проведения представления: ");
      scanf_s("%d", &theatre->representation[i].totalDate);
      getchar();
      for (k = 0; k < theatre->representation[i].totalDate; ++k) {
        printf("Введите число представления: ");
        scanf_s("%d", &theatre->representation[i].date->day);
        getchar();
        printf("Введите месяц представления: ");
        scanf_s("%d", &theatre->representation[i].date->month);
        getchar();
        printf("Введите год представления: ");
        scanf_s("%d", &theatre->representation[i].date->year);
        getchar();
        printf("Введите часы представления: ");
        scanf_s("%d", &theatre->representation[i].date->hour.hour);
        getchar();
        printf("Введите минуты представления: ");
        scanf_s("%d", &theatre->representation[i].date->hour.minute);
        getchar();
        puts("\n");
      }
    }
  }
}

//Отображение данных об театре
void displayTheatreInfo(const char *title) {
  int i, j;
  struct node *ptr;
  if (start == NULL) {
    printf("\nНет данных");
    return;
  } else {
    ptr = start;
    while (ptr != NULL && strcmp(ptr->data->title, title)) {
      ptr = ptr->next;
    }
    if (ptr == NULL) {
      printf("\nНет данных");
      return;
    }
    printf("====================== Театр %s ======================\n", title);
    puts("Режиссеры:");
    for (i = 0; i < ptr->data->totalProducer; ++i) {
      printf("%s\n", ptr->data->producer[i]);
    }
    puts("Актеры:");
    for (i = 0; i < ptr->data->totalActors; ++i) {
      printf("%s\n", ptr->data->actors[i]);
    }

    printf("Адрес: %s\n", ptr->data->address);

    printf("Мест в партере: %d\n", ptr->data->totalSeatParter);

    printf("Мест на балконе: %d\n", ptr->data->totalSeatBalcony);

    printf("Мест в бельэтаже: %d\n", ptr->data->totalSeatMezzanine);

    for (i = 0; i < ptr->data->totalRepresentation; ++i) {
      printf("====================== Представление %d ======================\n",
             i + 1);
      printf("Режиссёр: %s\n", ptr->data->representation[i].producer);
      puts("Актеры:");

      for (j = 0; j < ptr->data->representation[i].totalActors; ++j) {
        printf("%s\n", ptr->data->representation[i].actors[j]);
      }
      puts("Даты:");
      for (j = 0; j < ptr->data->representation[i].totalDate; ++j) {
        printf("%d.%d.%d %d:%d\n", ptr->data->representation[i].date[j].day,
               ptr->data->representation[i].date[j].month,
               ptr->data->representation[i].date[j].year,
               ptr->data->representation[i].date[j].hour.hour,
               ptr->data->representation[i].date[j].hour.minute);
      }

      printf("Длительность в минутах: %d\n",
             ptr->data->representation[i].duration);
      printf("Свободных мест в партере: %d\n",
             ptr->data->representation[i].countFreeSeatParter);
      printf("Свободных мест на балконе: %d\n",
             ptr->data->representation[i].countFreeSeatBalcony);
      printf("Свободных мест в бельэтаже: %d\n",
             ptr->data->representation[i].countFreeSeatMezzanine);
      printf("Цена места в партере: %f\n",
             ptr->data->representation[i].costSeatParter);
      printf("Цена места на балконе: %f\n",
             ptr->data->representation[i].costSeatBalcony);
      printf("Цена места в бельэтаже: %f\n",
             ptr->data->representation[i].costSeatMezzanine);
    }
  }
}

//Поиск по свободным местам и ценам на представление
void infoFreeSeatAndCostRepresent(const char *title) {
  int i;
  struct node *ptr;

  if (start == NULL) {
    printf("\nНет данных");
    return;
  } else {
    ptr = start;
    while (ptr != NULL) {
      for (i = 0; i < ptr->data->totalRepresentation; ++i) {
        if (!strcmp(ptr->data->representation[i].title, title)) {
          printf("Свободных мест в партере: %d\n",
                 ptr->data->representation[i].countFreeSeatParter);

          printf("Свободных мест на балконе: %d\n",
                 ptr->data->representation[i].countFreeSeatBalcony);

          printf("Свободных мест в бельэтаже: %d\n",
                 ptr->data->representation[i].countFreeSeatMezzanine);

          printf("Цена места в партере: %f\n",
                 ptr->data->representation[i].costSeatParter);

          printf("Цена места на балконе: %f\n",
                 ptr->data->representation[i].costSeatBalcony);

          printf("Цена места в бельэтаже: %f\n",
                 ptr->data->representation[i].costSeatMezzanine);

          return;
        }
      }
      ptr = ptr->next;
    }
  }
}

//Поиск представления по театру
void getRepresentByTheatre(const char *title) {
  int i;
  struct node *ptr;

  if (start == NULL) {
    printf("\nНет данных");
    return;
  } else {
    ptr = start;
    while (ptr != NULL && strcmp(ptr->data->title, title)) ptr = ptr->next;

    if (ptr == NULL) {
      printf("\nНет данных");
      return;
    }

    for (i = 0; i < ptr->data->totalRepresentation; ++i)
      printf("Представление %d: %s\n", i + 1,
             ptr->data->representation[i].title);
  }
}

//Поиск представления по режиссёру

void getRepresentByProducer(const char *producer) {
  int i;

  struct node *ptr;

  if (start == NULL) {
    printf("\nНет данных");
    return;
  } else {
    ptr = start;
    while (ptr != NULL) {
      for (i = 0; i < ptr->data->totalRepresentation; ++i) {
        char *curProducer = ptr->data->representation[i].producer;
        if (!strcmp(curProducer, producer)) {
          printf("Представление: %s, Режиссёр: %s\n",
                 ptr->data->representation[i].title, curProducer);
        }
      }
      ptr = ptr->next;
    }
  }
}

//Поиск представления по актеру
void getRepresentByActor(const char *actor) {
  int i, j;
  struct node *ptr;

  if (start == NULL) {
    printf("\nНет данных");
    return;
  } else {
    ptr = start;
    while (ptr != NULL) {
      for (i = 0; i < ptr->data->totalRepresentation; ++i) {
        for (j = 0; j < ptr->data->representation[i].totalActors; ++j) {
          char *curActor = ptr->data->representation[i].actors[j];
          if (!strcmp(actor, curActor)) {
            printf("Представление: %s, Актеры: %s\n",
                   ptr->data->representation[i].title, curActor);
          }
        }
      }
      ptr = ptr->next;
    }
  }
}

//Поиск представления по дате
void getRepresentByDate(int day, int month, int year) {
  int i, j;
  struct node *ptr;

  if (start == NULL) {
    printf("\nНет данных");
    return;
  } else {
    ptr = start;
    while (ptr != NULL) {
      for (i = 0; i < ptr->data->totalRepresentation; ++i) {
        for (j = 0; j < ptr->data->representation[i].totalDate; ++j) {
          Date date = ptr->data->representation[i].date[j];
          if (date.day == day && date.month == month && date.year == year) {
            printf("Представление: %s, Дата: %d.%d.%d\n",
                   ptr->data->representation[i].title, date.day, date.month,
                   date.year);
          }
        }
      }
      ptr = ptr->next;
    }
  }
}