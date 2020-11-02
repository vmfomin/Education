/// Задача 6. Улучшим барберов.
#include <iostream>

int main() {
    int men;
    int barbers;

    std::cout << "Количество мужчин в городе: ";
    std::cin >> men;

    std::cout << "Сколько удалось нанять барберов? ";
    std::cin >> barbers;

    int menPerBarber = 8; // 1 в час 8 часов рабочий день.

    int menPerBarberPerMonth = menPerBarber * 30;
    std::cout << "Один барбер пострижет " << menPerBarberPerMonth << " мужчин в месяц" << "\n";

    // Сколько нужно барберов
    int reqBarber = men / menPerBarberPerMonth;

    // Проверка на целое. Если есть дробная часть, значит добавляем.
    if (men / menPerBarberPerMonth != 0) reqBarber++;

    std::cout << "Необходимое число барберов: " << reqBarber << "\n";

    std::cout << reqBarber << " барбера могут постричь "
              << reqBarber * menPerBarberPerMonth << " мужчин за месяц\n";
    
    std::cout << (reqBarber > barbers ? "Нужно больше барберов!!!\n" : "Барберов хватает!!!\n");

    return 0;
}
