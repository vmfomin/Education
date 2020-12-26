/// 1. Время в пути
/* Поезд отправляется в AA часов BB минут и прибывает в пункт назначения в CC
 * часов DD минут. Сколько часов и минут он находится в пути?
 * Напишите программу, которая принимает от пользователя две строки — время
 * отправления и время прибытия поезда. Время задается строкой из 5 символов в
 * формате HH:MM. Обеспечьте контроль ввода, проверьте также, что время
 * корректно. Программа должна ответить, сколько часов и минут поезд находится в
 * пути. Если время отправления больше времени прибытия, считайте, что поезд
 * прибывает в пункт назначения на следующий день.
 * Примеры: Введите время отправления: 07:15
 * Введите время прибытия: 16:55
 * Поезд находится в пути 9 часов 40 минут
 * Введите время отправления: 21:10
 * Введите время прибытия: 08:05
 * Поезд находится в пути 10 часов 55 минут*/

#include <iostream>

// Функция чтения времени.
bool parseTime(std::string &timeStr, int &hours, int &minutes) {
  for (int i = 0; i < timeStr.length(); ++i) {
    if (timeStr[i] >= '0' && timeStr[i] <= '9') {
      // Отделяю часы от минут и учитываю значения на своем месте.
      if (i <= 1)
        if (i == 0)
          hours += (timeStr[i] - '0') * 10;
        else
          hours += timeStr[i] - '0';
      else if (i == 3)
        minutes += (timeStr[i] - '0') * 10;
      else
        minutes += (timeStr[i] - '0');
    } else if (timeStr[i] == ':' || timeStr[i] == '.') {
      continue;
    } else {
      return false;
    }

    if (hours > 24 || minutes > 60) {
      std::cout << "Error! Time format is \"HH:MM\" in 24 hours.\n";
      hours = 0;
      minutes = 0;
      return false;
    }
  }

  return true;
}

int main() {
  do {
    // время отправки.
    int departureHours{}, departureMinutes{};
    std::string timeStr;
    do {
      std::cout << "Enter the departure time: ";
      std::cin >> timeStr;
    } while (!parseTime(timeStr, departureHours, departureMinutes));

    // время прибытия
    int arrivalHours{}, arrivalMinutes{};
    do {
      std::cout << "Enter your arrival time: ";
      std::cin >> timeStr;
    } while (!parseTime(timeStr, arrivalHours, arrivalMinutes));

    // Время в пути
    int wayHours;
    int wayMinutes;
    if (arrivalHours > departureHours) {
      // Если время прибытия меньше по значению, чем отправки.
      if (arrivalMinutes < departureMinutes) {
        wayMinutes = (arrivalMinutes + 60) - departureMinutes;
        // Отнимаем 1, т.к. взяли 1 час, чтобы сделать больше значение минут.
        wayHours = arrivalHours - 1 - departureHours;
      } else {
        wayMinutes = arrivalMinutes - departureMinutes;
        wayHours = arrivalHours - departureHours;
      }
    } else {
      if (arrivalMinutes < departureMinutes) {
        wayMinutes = (arrivalMinutes + 60) - departureMinutes;
        // Отнимаем 1, т.к. взяли 1 час, чтобы сделать больше значение минут.
        wayHours = (arrivalHours + 24) - 1 - departureHours;
      } else {
        wayMinutes = arrivalMinutes - departureMinutes;
        wayHours = (arrivalHours + 24) - departureHours;
      }
    }

    // условие для выхода из бесконечного цикла.
    if ((0 == wayHours || 24 == wayHours) && 0 == wayMinutes) {
      std::cout << "Exit.\n";
      break;
    }

    std::cout << "The train is on its way for " << wayHours << " hours and "
              << wayMinutes << " minutes\n";
  } while (true);

  return 0;
}