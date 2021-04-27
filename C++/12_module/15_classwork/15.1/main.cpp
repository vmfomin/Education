/** Грузовые контейнеры
На порту производится учёт веса N грузовых контейнеров. N - здесь произвольное
число. Каждый вес контейнера представлен в виде числа с плавающей точкой,
обозначающей тонны. Не используя констант, а используя только имя самого
массива, требуется вывести в консоль общее количество контейнеров в порту.
Помните, в самой программы вы можете объявить любое количество контейнеров, и
именно оно и должно быть показано.
*/

#include <iostream>

int main() {
  std::cout << "Enter wagons count: ";
  int count;
  std::cin >> count;
  int wagons[count];
  float sumWeight{};

  for (int i{}; i < count; i++) {
    wagons[i] = i + 1;
    sumWeight += wagons[i] * 1.2f;
  }

  std::cout << "Wagons count: " << sizeof(wagons) / sizeof(wagons[0]) << "\n";

  std::cout << "Weight of wagons for example: " << sumWeight << "\n";

  getchar();
  getchar();

  return 0;
}
