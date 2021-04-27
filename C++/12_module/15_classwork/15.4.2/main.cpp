/** Баскетбольный разброс
В баскетбольной команде, вместе с запасными игроками всего находится девять
человек. О каждом из игроков тренер собирает одну из важнейших физических
характеристик в этой игре, а именно рост. Рост игрока записывается в
сантиметрах, и для точности требуется использовать число с плавающей точкой.
После записи, осуществляется анализ полученных данных. Требуется, за один проход
цикла, вычислить минимальный и максимальный рост игрока, а также разницу между
ними.
 */

#include <iostream>

int main() {
  float growths[]{182.3f, 201.5f, 173.4f, 199.f, 203.2f, 185.5f};

  // Рост баскетболистов
  float lowest{growths[0]}, highest{};

  for (const auto &growth : growths) {
    if (growth < lowest) lowest = growth;

    if (growth > highest) highest = growth;
  }

  std::cout << "The lowest basketball player is " << lowest
            << "\nThe highest basketball player is " << highest
            << "\nThe difference between the highest and lowest players is "
            << highest - lowest << "\n";

  return 0;
}
