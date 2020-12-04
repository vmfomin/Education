/// Задача 1. Космический симулятор
// Вы пишете симулятор космических полётов. Ваш звездолёт массой m килограмм
// включает двигатель с силой тяги F ньютонов на t секунд. Напишите программу,
// которая по заданным F, m и t покажет, на каком расстоянии от первоначального
// положения окажется космический корабль через t секунд.
// Обеспечьте контроль ввода.
// Примечание: космический корабль находится в открытом космосе.
// Напоминаем, что расстояние можно рассчитать по формуле:
// a * t^2 / 2
// a = F / m

#include <iostream>

// Модель звездолета.
class Starship {
public:
    /// Конструктор по умолчанию.
    Starship() : force_{-1000}, mass_{1000}, time_{5} {}

    /// Конструктор класса через список с юниформ присваиванием.
    /// \param force -- Сила тяги в нютонах;
    /// \param mass -- Масса звездолета в кг;
    /// \param time -- Время запуска в сек;
    Starship(float force, float mass, float time)
            : force_{force}, mass_{mass}, time_{time} {}

    /// Метод расчета расстояния.
    // Вычитал, что методы, которые не изменяют объект должны быть const.
    // CLion тоже предложил так сделать.
    float distance() const {
        return (time_ * time_ * force_) / (2 * mass_);
    }

    /// Метод вывода расстояния на экран.
    inline void printDistance() const {
        std::cout << "Звездолет с силой тяги " << force_ << " Н, массой " << mass_
                  << " кг, преодолеет расстояние в " << distance() << " метров за "
                  << time_ << " секунд\n";
    }

    /// Общая проверка массы на 0 или отрицание.
    /// \param mass -- масса звездолета
    inline static void isCheckMass(float mass) {
        if (mass <= 0) {
            std::cout << "Масса не может быть отрицательной или равна 0!\n";
            return;
        }
    }

    /// Общая проверка времени на 0 или отрицание.
    /// \param time -- время
    inline static void isCheckTime(float time) {
        if (time <= 0) {
            std::cout << "Время не может быть отрицательным или равным 0!\n";
            return;
        }
    }

    /// Геттеры и сеттеры.
    float getForce() const { return force_; }

    void setForce(float force) { force_ = force; }

    float getMass() const { return mass_; }

    void setMass(float mass) {
        isCheckMass(mass);
        mass_ = mass;
    }

    float getTime() const { return time_; }

    void setTime(float time) {
        isCheckTime(time);
        time_ = time;
    }

    /// Деструктор объекта Starship.
    ~Starship() = default;

private:
    /// Объекты класса.
    float force_; // Сила тяги в нютонах
    float mass_;  // масса звездолета в кг
    float time_;  // время запуска в сек
};

int main() {
    std::cout << "Введите параметры звездолета:\n";
    std::cout << "Сила тяги (Н): ";
    float force;
    std::cin >> force;

    float mass;
    do {
        std::cout << "Масса (кг): ";
        std::cin >> mass;
        // Чтобы не писать и исправлять постоянно проверку сделал обобщенный метод static
        Starship::isCheckMass(mass);
    } while (mass <= 0);

    float time;
    do {
        std::cout << "Время: ";
        std::cin >> time;
        // Чтобы не писать и исправлять постоянно проверку сделал обобщенный метод static
        Starship::isCheckTime(time);
    } while (time <= 0);

    // Инициализация объекта через конструктор.
    Starship starship{force, mass, time};
    starship.printDistance();

    std::cout << "\nБазовый звездолет (по умолчанию, который дает задний ход).\n";
    Starship starshipBasic;
    starshipBasic.printDistance();

    std::cout << "\nПроизведите апгрейд базового звездолета!\n"
                 "Сделайте так, чтобы он двигался вперед с большей мощностью.\n"
                 "Для этого добавьте положительную тягу и учтите новую массу.\n";

    std::cout << "Введите новую тягу двигателя: ";
    std::cin >> force;
    starshipBasic.setForce(force);

    do {
        std::cout << "Введите изменившуюся массу после обновления: ";
        std::cin >> mass;
        Starship::isCheckMass(mass);
    } while (mass <= 0);
    starshipBasic.setMass(mass);

    do {
        std::cout << "Введите время: ";
        std::cin >> time;
        Starship::isCheckTime(time);
    } while (time <= 0);
    starshipBasic.setTime(time);

    std::cout << "\nВывод данных после обновления (с использованием \"геттеров\".)\n"
              << "\nПараметры звездолета после обновлений:\n"
                 "Сила тяги: " << starshipBasic.getForce() << " Н.\n"
              << "Масса: " << starshipBasic.getMass() << " кг.\n"
              << "Пройдено расстояние: " << starshipBasic.distance() << " метров за "
              << starshipBasic.getTime() << " секунд\n";

    return 0;
}
