/// Задача 4. Злостные вредители

#include <iostream>
#include <cmath>

int main() {
  /// 1 часть задчи
  int startHeight;    // Высота саженца
  int growth;         // Скорость роста
  int losses;         // Скорость поедания гусеницами
  int days;           // Полные дни
  int maxHeight;      // Высота для продажи

  std::cout << "Введите скорость роста бамбука: ";
  std::cin >> growth;

  std::cout << "Введите скорость поедания бамбука: ";
  std::cin >> losses;

  std::cout << "Введите высоту саженца: ";
  std::cin >> startHeight;

  std::cout << "Введите количество дней: ";
  std::cin >> days;

  int dayHeight = startHeight + ((growth - losses) * days + (growth / 2));
  // Чтобы вывести правильно к середине 3 дня добавил инкремент.
  std::cout << "Высота бамбука к середине " << ++days << " дня: " << dayHeight << "\n\n";

  /// 2 часть задчи
  std::cout << "Введите максимальную высоту: ";
  std::cin >> maxHeight;

  /// Здесь получаю число дней с дробной частью, т.к. нам важно когда бамбук вырастет. Для это применил функцию ceil
  /// для округления в большую сторону. Сделал приведение типа к float, т.к. он считает правую часть как int.
  auto day = (float) (maxHeight - startHeight) / (float) (growth - losses);
  days = std::ceil(day);
  std::cout << "Сколько полных дней для вырастания бамбука: " << days << "\n";

  return 0;
}