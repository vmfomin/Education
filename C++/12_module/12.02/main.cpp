/* Задача 2. Средняя этажность
С помощью массивов объявите 5 зданий, каждый элемент которых будет обозначать
отдельный этаж. Это могут быть совершенно разные здания: фитнес-клуб (2 этажа),
магазин (1 этаж), коттедж (3 этажа), квартирный дом (15) и небоскрёб (50
этажей). Используя среднее арифметическое число, узнайте итоговую этажность
вашего “квартала”. */

#include <cmath>
#include <iostream>

int main() {
  int fitnessClub[2]{};
  size_t fitnessClubSize{sizeof(fitnessClub) / sizeof(fitnessClub[0])};

  int shop[1]{};
  size_t shopSize{sizeof(shop) / sizeof(shop[0])};

  int cottage[3]{};
  size_t cottageSize{sizeof(cottage) / sizeof(cottage[0])};

  int apartmentBuilding[15]{};
  size_t ApartmentBuildingSize{sizeof(apartmentBuilding) /
                               sizeof(apartmentBuilding[0])};

  int skyscraper[50]{};
  size_t skyscrapperSize{sizeof(skyscraper) / sizeof(skyscraper[0])};

  float averageNumberOfFloors{(fitnessClubSize + shopSize + cottageSize +
                               ApartmentBuildingSize + skyscrapperSize) /
                              5.f};
  std::cout << "Average number of floors is " << averageNumberOfFloors
            << std::endl;

  return 0;
}
