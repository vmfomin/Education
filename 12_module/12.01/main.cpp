/// 1. Время в пути
/* Поезд отправляется в AA часов BB минут и прибывает в пункт назначения в CC
 * часов DD минут. Сколько часов и минут он находится в пути?
 * Напишите программу, которая принимает от пользователя две строки — время
 * отправления и время прибытия поезда. Время задается строкой из 5 символов в
 * формате HH:MM. Обеспечьте контроль ввода, проверьте также, что время корректно.
 * Программа должна ответить, сколько часов и минут поезд находится в пути. Если
 * время отправления больше времени прибытия, считайте, что поезд прибывает в
 * пункт назначения на следующий день.
 * Примеры:
 * Введите время отправления: 07:15
 * Введите время прибытия: 16:55
 * Поезд находится в пути 9 часов 40 минут
 * Введите время отправления: 21:10
 * Введите время прибытия: 08:05
 * Поезд находится в пути 10 часов 55 минут*/

#include <iostream>

int main() {
  do {
    // время отправки.
    int departureHours{}, departureMinutes{};
    bool isTimeDeparture{};
    do {
      std::cout << "Enter the departure time: ";
      std::string departureTime;
      std::cin >> departureTime;

      for (int i = 0; i < departureTime.length(); ++i) {
        if (departureTime[i] >= '0' && departureTime[i] <= '9') {
          // Отделяю часы от минут и учитываю значения на своем месте.
          if (i <= 1)
            if (i == 0)
              departureHours += (departureTime[i] - '0') * 10;
            else
              departureHours += departureTime[i] - '0';
          else if (i == 3)
            departureMinutes += (departureTime[i] - '0') * 10;
          else
            departureMinutes += (departureTime[i] - '0');

          isTimeDeparture = true;
        } else if (departureTime[i] == ':' || departureTime[i] == '.')
          continue;
        else {
          isTimeDeparture = false;
          break;
        }

        if (departureHours > 24 || departureMinutes > 60) {
          std::cout << "Error! Time format is \"HH:MM\" in 24 hours.\n";
          departureHours = 0;
          departureMinutes = 0;
          isTimeDeparture = false;
          break;
        }
      }
    } while (!isTimeDeparture);

    // время прибытия
    int arrivalHours{}, arrivalMinutes{};
    bool isTimeArrival{};
    do {
      std::cout << "Enter your arrival time: ";
      std::string arrivalTime;
      std::cin >> arrivalTime;

      for (int i = 0; i < arrivalTime.length(); ++i) {
        if (arrivalTime[i] >= '0' && arrivalTime[i] <= '9') {
          if (i <= 1)
            if (i == 0)
              arrivalHours += (arrivalTime[i] - '0') * 10;
            else
              arrivalHours += arrivalTime[i] - '0';
          else if (i == 3)
            arrivalMinutes += (arrivalTime[i] - '0') * 10;
          else
            arrivalMinutes += (arrivalTime[i] - '0');

          isTimeArrival = true;
        } else if (arrivalTime[i] == ':' || arrivalTime[i] == '.')
          continue;
        else {
          isTimeArrival = false;
          break;
        }

        if (arrivalHours > 24 || arrivalMinutes > 60) {
          std::cout << "Error! Time format is \"HH:MM\" in 24 hours.\n";
          arrivalHours = 0;
          arrivalMinutes = 0;
          isTimeArrival = false;
          break;
        }
      }
    } while (!isTimeArrival);

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