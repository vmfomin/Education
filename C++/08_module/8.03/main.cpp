/// Задача 3. Immolate Improved!
// Мы придумываем фэнтезийную онлайн-игру в жанре RPG. В орка стреляют огненными
// шарами разной степени мощности, но у него есть очки здоровья и показатель
// сопротивляемости магии. Очки здоровья, сопротивляемость магии и мощность
// огненного шара — это вещественные числа от нуля до единицы включительно. Чем
// больше мощность, тем больше урон здоровью, но чем больше сопротивляемость магии,
// тем урон меньше. Например, если сопротивляемость равна нулю (0%), то будет
// нанесен урон равный мощности огненного шара. Если сопротивляемость равна единице
// (100%), урон будет равен нулю, даже если мощность заклинания максимальна.
// Напишите программу, в которой пользователь сначала задаёт количество здоровья
// и сопротивляемость магии орка, а после стреляет в него огненными шарами разной
// мощности, пока орк не погибнет. Мощность удара вводится с клавиатуры с каждым
// выстрелом. После каждого заклинания программа выводит на экран итоговый урон
// от удара, и оставшиеся очки здоровья орка.
// Обеспечьте контроль ввода.

#include <iostream>

/// Статы орка и расчет влияния урона по персонажу.
class Ork {
public:
    /// Констркутор по умолчанию.
    Ork() : name_{"Thrall"}, healthPoint_{1}, magicResistance_{0} {}

    /// Конструктор.
    /// \param name -- имя орка
    /// \param healthPoint -- количество hp.
    /// \param magicResistance -- сопротивление магии.
    // Освежил знания передачи в метод (функцию) по ссылкам и указателям, по
    // значению.
    Ork(std::string &name, float healthPoint, float magicResistance)
        : name_{name},
          healthPoint_{healthPoint},
          magicResistance_{magicResistance} {}


    /// Метод расчета урона от огненого шара.
    /// \param fireball -- входящий урон
    // чтобы не плодить переменные исправляю (добавляю резист) значению полученному
    // по ссылке.
    inline void computeDamage(float &fireball) {
      healthPoint_ -= fireball *= (1 - magicResistance_);
      std::cout << "По орку " << name_ << " нанесено урона " << fireball * 100
                << "\n";
    }


    /// Метод вывода на экран текущих характеристик орка
    inline void printStats() const {
      std::cout << "Орк по имени " << name_ << " имеет "
                << healthPoint_ * 100 << " % очков здоровья и "
                << magicResistance_ * 100 << " % сопротивления магии\n";
    }


    /// Метод вывода на экран титров после смерти орка.
    void printTitre() {
      std::cout << "\nСын Орды по имени " << name_ << " пал в бою! Он бился"
                                                      " с честью!\n";

      // Почитание предков и все такое... Но это уже мои доразмышлизмы)))
      std::cout << "Вождем было принято решение дать ему посмертное звание! Какое "
                   "звание дадим храброму орку? ";
      std::string rank;
      // Составное звание, например, " - Герой Орды".
      std::cin.ignore(80, '\n');
      std::getline(std::cin, rank);

      name_ += " - " + rank;

      std::cout << "Отныне его будут звать " << name_ << "\nЛок’тар огар!\n";
    }


    /// Возврат текущего здоровья орка.
    /// \return Здоровье орка.
    float getHealthPoint() const { return healthPoint_; }


    /// Деструктор
    virtual ~Ork() = default;

private:
    std::string name_; // Имя орка.
    float healthPoint_; // Количество hp.
    float magicResistance_; // Сопротивление магии.
};

int main() {
  std::cout << "Введите имя, количество здоровья и сопротивление магии орка: ";
  std::string name;
  float healthPoint, magicResistance;
  std::cin >> name >> healthPoint >> magicResistance;
  std::cout << "\n";

  if (healthPoint > 1 || magicResistance > 1) {
    std::cout << "Значения здоровья и сопротивления магии должны быть "
                 "от 0 до 1!\n";
    return -1;
  }

  // Создаю орка.
  Ork ork{name, healthPoint, magicResistance};
  ork.printStats();

  // Цикл нанесения урона.
  float fireball{};
  do {
    std::cout << "Введите урон от огненного шара: ";
    std::cin >> fireball;

    if (fireball <= 1) {
      ork.computeDamage(fireball);
      // Выводим пока не убили. Как только убили перестаем выводить.
      // И так понятно что будет или - или 0 в hp.
      if (ork.getHealthPoint() > 0)
        ork.printStats();
    } else
      std::cout << "Урон от огненного шара должен быть меньше 1!\n";
  } while (ork.getHealthPoint() > 0);

  ork.printTitre();

  return 0;
}
