#include <iostream>
// Комментарий для отображения в GitHub

int main() {
#pragma region  Задание 1. Улучшаем гонщика
/*
    int lap = 4;
    int engine = 220;
    int wheels = 93;
    int steerinWheel = 49;
    int headItem = 3;
    int wind = 21;
    int rain = 17;
    int speed = engine + wheels + steerinWheel - rain - wind; //int speed = 358;

    std::cout << "===================\n"
    << "Супер гонки. Круг " << lap << "\n"
    << "===================\n"
    << "Шумахер (" << speed << ")\n"
    << "===================\n"
    << "Водитель: Шумахер\n"
    << "Скорость: " << speed << "\n"
    << "-------------------\n"
    << "Оснащение\n"
    << "Двигатель: +" << engine << "\n"
    << "Колеса: +" << wheels << "\n"
    << "Руль: +" << steerinWheel << "\n"
    << "-------------------\n"
    << "Действия плохой погоды\n"
    << "Ветер: -" << wind << "\n"
    << "Дождь: -" << rain << "\n";
    */
#pragma endregion

#pragma region  Задание 2. Калькулятор стоимости товара
/*
    // Объявление переменных:
    // цены всегда целые
    int productPrice = 0; // Стоимость товара
    int delivery = 0;     // Стоимость доставки
    float discount = 0;     // Скидка в процентах
    float fullPrice = 0;    // Полная цена зависит от процента и решил сделать float, а не дабл
                            // все-таки тут не так важна точность.

    std::cout << "Приветствуем вас в калькуляторе! "
                 "Он поможет рассчитать полную стоимость товаров с учетом скидок и доставки.\n"
                 << "Введите стоитмость товара: ";
    std::cin >> productPrice;

    std::cout << "Введите стоимость доставки: ";
    std::cin >> delivery;

    std::cout << "Введите размер скидки в процентах: ";
    std::cin >> discount;

    fullPrice = productPrice + delivery - discount * productPrice / 100;    // Полная цена
    std::cout << "-----Считаем-----\n"
    << "Итого: " << fullPrice;
*/
#pragma endregion

#pragma region  Задание 3. Время, время!
/*
    int workShift = 0;            // Рабочая смена в минутах
    int orderTime = 0;            // Время заказа клиента в минутах
    int cashierMasterUp = 0;      // Время сборки заказа
    int countClientsPerShift = 0; // Количество клиентов за смену

    std::cout << "Эта программа рассчитает, сколько клиентов успеет обслужить кассир за смену.\n";
    std::cout << "Введите длительность смены в минутах: ";
    std::cin >> workShift;

    std::cout << "Сколько минут клиент делает заказ? ";
    std::cin >> orderTime;

    std::cout << "Сколько минут кассир собирает заказ? ";
    std::cin >> cashierMasterUp;

    std::cout << "-----Считаем-----\n";
    countClientsPerShift = workShift / (orderTime + cashierMasterUp);
    std::cout << "За смену длиной " << workShift << " минут кассир успеет обслужить "
    << countClientsPerShift << " клиентов";
*/
#pragma endregion

#pragma region Задание 4. Непонятная квитанция

    int fullResult = 0; // Сумма в квитанции
    int entrance = 0;   // Количество подъездов
    int flats = 0;      // Количество квартир
    int eachFlat = 0;   // Сколько должна заплатить каждая квартира

    std::cout << "Приветствуем вас в калькуляторе квартплаты!\n"
              << "Введите сумму, указанную в квитанции: ";
    std::cin >> fullResult;

    entrance:
    std::cout << "Сколько подъездов в вашем доме? ";
    std::cin >> entrance;

    if (entrance == 0) {
        entrance = 1;
        std::cout << "Количество подъездов не может быть 0.\n";
        goto entrance;
    }

    flats:
    std::cout << "Сколько квартир в каждом подъезде? ";
    std::cin >> flats;

    if (flats == 0) {
        flats = 1;
        std::cout << "Количество кваритр не может быть 0.\n";
        goto flats;
    }

    std::cout << "----Считаем-----\n";

    eachFlat = fullResult / (entrance * flats);

    std::cout << "Каждая квартира должна заплатить по " << eachFlat << " руб.";

#pragma endregion

    return 0;
}