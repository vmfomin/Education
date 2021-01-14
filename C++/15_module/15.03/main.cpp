/* Задача 3. Уровень самоизоляции
В одной отдельно взятой пятиэтажке проживает N зарегистрированных жильцов -
данное число требуется ввести с самого начала программы. На каждом из этажей
сейчас находится Ni людей. Это число также требуется ввести вначале. Используя
все эти данные требуется вычислить общий уровень самоизоляции в доме, как
процентное отношение общего числа людей, которые сейчас находятся на этажах к
общему количеству жильцов, зарегистрированных в нём. Для этого можно
использовать формулу: (сумма Ni * 100) / N */

#include <iostream>

int main() {
  std::cout << "How many residents live in a five-story building? ";
  int residents;
  std::cin >> residents;

  int peopleOnTheFloors[5]{};

  for (size_t i{}; i < 5; ++i) {
    std::cout << "How many people are on the " << i + 1 << " floor right now? ";
    std::cin >> peopleOnTheFloors[i];
  }

  int sumFloorResidents{};
  for (const int &people : peopleOnTheFloors) sumFloorResidents += people;

  float selfIsolationPercent = sumFloorResidents * 100 / residents;

  selfIsolationPercent > 100
      ? std::cout << "The house has more people than residents by "
                  << selfIsolationPercent - 100 << " percent!!!\n"
      : std::cout << "Percentage of self-isolation in the house "
                  << selfIsolationPercent << "\n";

  return 0;
}
