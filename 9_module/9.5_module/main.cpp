/// Задача 5. Счастливый билетик.
/// В старину, когда даже в столице билеты в общественном транспорте выдавали
/// контролеры, существовало поверье: если на билете сумма первых трех цифр в
/// номере билета равна сумме последних трех, то это к удаче. Напишите программу,
/// которая получала бы на входе шестизначный номер билета и выводила, счастливый
/// ли это билет или нет. К примеру, билеты 666 666 и 252 135 - счастливые,
/// а 123 456 - нет.

#include <iostream>

int main() {
    int ticket;

    std::cout << "Введите номер билета (6 цифр): ";
    std::cin >> ticket;

    bool isHappyTicket;
    int firstThreeDigitsOfTicket = 0, lastThreeDigitsOfTicket = 0;
    int count = 0;

    while (count < 6) {
        if (count < 3)
            lastThreeDigitsOfTicket += ticket % 10;
        else
            firstThreeDigitsOfTicket += ticket % 10;
        
        ticket /= 10;
        isHappyTicket = firstThreeDigitsOfTicket == lastThreeDigitsOfTicket;

        count++;
    }

    if (isHappyTicket)
        std::cout << "Счастливый!\n";
    else
        std::cout << "Не счастливый!\n";


    return 0;
}
