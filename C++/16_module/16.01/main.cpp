/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 1. Спидометр
 * Надо реализовать цифровой спидометр автомобиля. Сама модель автомобиля,
 * которую нужно будет воссоздать весьма проста. Начальная скорость - 0 км/ч.
 * Пользователь вводит в стандартный ввод разницу (дельту) в скорости и
 * результирующая скорость показывается на спидометре в стандартный вывод. Так
 * происходит до той поры, пока машина снова не остановится, т.е. пока скорость
 * не станет меньше или равна нулю (сравнение должно происходить с дельтой в
 * 0.01). Диапазон возможных значений скорости машины от 0 до 150 км/ч. Сам
 * показатель спидометра, вместе с единицами измерения, требуется записывать в
 * отдельную строку-буфер, которая потом и будет показываться на экране.
 * Точность отображения скорость до 0.1 км/ч.
 * @version   0.1
 * @date      04-03-2021
 * @copyright Copyright (c) 2021
 */

#include <iomanip>
#include <iostream>
#include <sstream>

/**
 * @brief     comparison of fractional numbers
 * @param     a             first number
 * @param     b             second number
 * @param     absEpsilon    absolute epsilon
 * @param     relEpsilon    relative epsilon
 * @return    true          equal
 */
bool isEqualFloat(double a, double b, double absEpsilon = 1e-12,
                  double relEpsilon = 1e-8) {
  using std::abs;
  double diff = abs(a - b);
  if (diff <= absEpsilon) return true;

  // Knuth algorithm
  return diff <= ((abs(a) < abs(b) ? abs(b) : abs(a)) * relEpsilon);
}

int main() {
  using std::cin;
  using std::cout;
  cout << "\x1b[2J";

  std::stringstream speedometr;
  double currentSpeed{0.};
  do {
    cout << "Enter speed:\t";
    double speed;
    cin >> speed;
    currentSpeed += speed;

    if (currentSpeed > 150 || isEqualFloat(currentSpeed, 150., 0.01)) {
      cout << "\x1b[31mThis is more than maximum speed! Slowdown!\x1b[0m\n";
      currentSpeed -= speed;
      continue;
    }

    if (currentSpeed < 0 || isEqualFloat(currentSpeed, 0., 0.01)) {
      speedometr << 0. << "\x1b[32m\tKm/h\x1b[0m\n";
      break;
    }

    speedometr << std::fixed << std::setprecision(1) << currentSpeed
               << "\x1b[32m\tKm/h\x1b[0m\n";
    cout << "Current speed\x1b[36m\t" << currentSpeed << "\x1b[0m\n\n";
  } while (true);

  cout << "\x1b[2JSpeedometer:\n";
  cout << speedometr.str();

  cout << "\n";
  return 0;
}