/* Задача 4. Радио-приёмник
В радио-приёмнике настроено 10 частот-каналов, представленные в виде массива.
Каждая из настроек частоты это число с плавающей точкой. Настройка производится
при старте приёмника. Приёмник проигрывает текущий настроенный канал,
устанавливая текущую активную чистоту, которая и показывается пользователю.
Требуется организовать безопасный доступ к каналам приёмника. Если канал
набираемый пользователем находится за пределами массива каналов, приёмник не
переключается и выводит сообщение об ошибке. Если пользователь вводит 0,
приёмник отключается. */

#include <windows.h>

#include <iostream>

/**
 * @brief  Проверка радиостанции на соответствие.
 * @param  &index: выбранная радиостанция.
 */
bool isCorrect(const int &index) {
  if (index < 0 || index > 10) {
    std::cerr << "\e[31;1m"  // ! Красный цвет для ошибки
              << "Error: selected the wrong radio station!!!\n";
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
  float frequencyChannel[]{87.5f,  90.3f,  90.8f,  95.2f,  100.1f,
                           102.1f, 102.5f, 104.2f, 106.2f, 106.6f};

  // Очистка консоли перед следующим выбором радиостанции.
  std::cout << "\e[2J";
  float seconds;
  bool isSeconds{};
  do {
    std::cout << "How often do I refresh the screen (seconds)? ";
    std::cin >> seconds;
    seconds *= 1000;

    if (seconds <= 0)
      std::cerr << "\e[31;1m"  // ! Красный цвет для ошибки
                << "Error: the time cannot be less than 0!!!\e[0m\n";
    else
      isSeconds = true;
  } while (!isSeconds);

  while (true) {
    std::cout << "\e[2JList of available radio stations:\n";
    for (size_t i{}; i < 10; ++i)
      std::cout << radioNames[i] << " (" << frequencyChannel[i] << ")\n";

    int select;  // Выбранная радиостанция.
    do {
      std::cout << "\e[0m\nSelect a radio station (1 - 10): ";
      std::cin >> select;
      if (0 == select) {
        std::cout << "\e[32;1mShutdown...\e[0m";
        return 0;
      }

      --select;
    } while (!isCorrect(select));

    std::cout << "\e[36;1mYou have chosen this radio station \""
              << radioNames[select] << "\" on the wave "
              << frequencyChannel[select] << "\e[0m\n";

    Sleep(seconds);  // Чтобы не стирались данные.
  };
}
