/** Средняя температура по больнице
В больнице проходят лечение 15 пациентов. Ежедневно утром главврач совершает
обход и фиксирует температуру каждого из них. В медицине важна точность, поэтому
температура записывается в виде числа с плавающей точкой. По итогу обхода
требуется вычислить наиболее важную характеристику для любого, уважающего себя,
лечебного заведения - среднюю температуру среди всех пациентов.
 */

#include <iostream>

int main() {
  float temperatures[5]{};

  for (int i{}; i < sizeof(temperatures) / sizeof(temperatures[0]); ++i) {
    std::cout << "Enter the temperature of the " << i + 1 << " patient: ";
    std::cin >> temperatures[i];
  }

  std::cout << "\n";
  float averageTemperature{};

  for (const auto &temperature : temperatures)
    averageTemperature += temperature;

  averageTemperature /= sizeof(temperatures) / sizeof(temperatures[0]);

  std::cout << "The average temperatue of patients is " << averageTemperature
            << "\n";

  return 0;
}
