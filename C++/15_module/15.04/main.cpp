/* Задача 4. Радио-приёмник
В радио-приёмнике настроено 10 частот-каналов, представленные в виде массива.
Каждая из настроек частоты это число с плавающей точкой. Настройка производится
при старте приёмника. Приёмник проигрывает текущий настроенный канал,
устанавливая текущую активную чистоту, которая и показывается пользователю.
Требуется организовать безопасный доступ к каналам приёмника. Если канал
набираемый пользователем находится за пределами массива каналов, приёмник не
переключается и выводит сообщение об ошибке. Если пользователь вводит 0,
приёмник отключается. */

#include <iostream>

bool isCorrect(const int &index) {
  if (index < 0 || index > 10) {
    std::cerr << "Selected the wrong radio station!!!\n";
    return false;
  }
  return true;
}

int main() {
  // Каналы радио Москвы. Нашел то, что может себе бы настроил.
  std::string radioNames[]{"Business FM",  "Авторадио",        "Relax FM",
                           "Rock FM",      "Серебряный дождь", "Монте-Карло",
                           "Comedy Radio", "Energy",           "Европа Плюс",
                           "Love Радио"};
  float frequencyChannel[10]{87.5f,  90.3f,  90.8f,  95.2f,  100.1f,
                             102.1f, 102.5f, 104.2f, 106.2f, 106.6f};

  std::cout << "List of available radio stations:\n";
  for (size_t i{}; i < 10; ++i)
    std::cout << radioNames[i] << " (" << frequencyChannel[i] << ")\n";

  int select;  // Выбранная радиостанция.
  do {
    std::cout << "\nSelect a radio station (1 - 10): ";
    std::cin >> select;
    --select;
  } while (!isCorrect(select));

  std::cout << "You have chosen this radio station " << radioNames[select]
            << " on the wave " << frequencyChannel[select] << "\n";

  return 0;
}
