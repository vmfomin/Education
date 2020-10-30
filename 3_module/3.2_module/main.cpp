/// Задача 2. Симулятор маршрутки

#include <iostream>

int main() {
    // Массив улиц для удобства.
    std::string streets[]{"Улица Программистов", "Проспект Алгоритмов", "Проспект Насследования",
                           "Улица Объектно-ориентированного программирования"};
    int ticketPrice = 20;
    int inPassengers = 0;
    int outPassengers = 0;
    int totalPassengers = 0;

    int earnAllMoney = 0;
    int salDriver = 0;
    int fuel = 0;
    int taxes = 0;
    int repairCost = 0;

    // Вывод в конце
    int totalRevenue = 0;

    // Маршрут. Сделал цикл, чтобы было проще. Не хотел писать повторяющийся код.
    // Cлышал когда-то про такой принцип "Don't repeat yourself". Про запись "for" сам удивился, его предложила иде.
    // Удобно. Изначально написал стандартный "for" как в Си.
    for (auto & street : streets) {
        std::cout << "Прибываем на остановку " << street << ". В салоне пассажиров: " << totalPassengers << "\n";
        std::cout << "Сколько пассажиров вышло на остановке? ";
        std::cin >> outPassengers;
        std::cout << "Сколько пассажиров зашло на остановке? ";
        std::cin >> inPassengers;

        totalPassengers += inPassengers - outPassengers;

        earnAllMoney += inPassengers * ticketPrice;

        std::cout << "Отправляемся с остановки " << street << ". В салоне пассажиров: " << totalPassengers
                  << "\n\n";
    }

    salDriver = earnAllMoney / 4;
    fuel = earnAllMoney / 5;
    taxes = earnAllMoney / 5;
    repairCost = earnAllMoney / 5;

    totalRevenue = earnAllMoney - salDriver - fuel - taxes - repairCost;

    std::cout << "Всего заработали: " << earnAllMoney << " руб.\n"
              << "Зарплата водителя: " << salDriver << " руб.\n"
              << "Расходы на топливо: " << fuel << " руб.\n"
              << "Налоги: " << taxes << " руб.\n"
              << "Расходы на ремонт машины: " << repairCost << " руб.\n"
              << "Итого доход: " << totalRevenue << " руб.\n";

    return 0;
}