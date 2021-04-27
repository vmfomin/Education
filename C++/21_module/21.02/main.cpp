/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задание 2. Модель данных для посёлка.
 * С помощью структур данных создайте подробную модель посёлка.
 * В посёлке есть множество участков. Каждый из них имеет свой уникальный номер.
 * На каждом из участков должен быть расположен как минимум один жилой дом, но
 * возможны и другие сооружения, такие как гараж, сарай (бытовка) и баня. Для
 * каждого здания предусмотрена информация о площади, которую он занимает на
 * участке.
 * В жилом доме может быть 1–3 этажа. На каждом из этажей может быть 2–4
 * комнаты. Каждая комната при этом может быть разных типов: спальня, кухня,
 * ванная, детская, гостиная. Для каждой комнаты предусмотрены данные о её
 * площади. Для каждого этажа также есть данные о высоте потолка. В жилом доме и
 * бане может быть печь с трубой, информация об этом также должна быть
 * предусмотрена в данных.
 * Для всех упомянутых сущностей надо объявить соответствующие структуры данных.
 * Вначале работы программы пользователь заполняет данные о посёлке: вводит
 * общее количество участков и далее начинает детализировать каждый из участков.
 * Для каждого участка сначала заполняется общее количество построек, а затем
 * детализируется каждая постройка, этажи, комнаты на этажах.
 * По итогам введённых данных вы можете рассчитать некий суммарный параметр,
 * например, процент земли, занимаемой постройками, к общей площади всего
 * посёлка. Главное в этой задаче не сама операция подсчёта, а структуры данных.
 * @version   0.1
 * @date      23-04-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using Village = struct Village_t;
using LandPlot = struct LandPlot_t;
using Buildings = struct Buildings_t;
using Floors = struct Floors_t;
using Rooms = struct Rooms_t;

struct Village_t {
  int32_t nLandPlots{};
  std::vector<LandPlot> landPlot;
};

struct LandPlot_t {
  int32_t serialNumber{};
  double area{};
  int32_t nBuildings{1};
  std::vector<Buildings> builds;
};

struct Buildings_t {
  std::string type{"House"};
  std::string pipe{""};
  double area{};
  int32_t nFloors{1};
  std::vector<Floors> floors;
};

struct Floors_t {
  int32_t nRooms{2};
  double height{};
  std::vector<Rooms> rooms;
};

struct Rooms_t {
  std::string type{"Living"};
  double area{};
};

int main() {
  cout << "\x1b[2J";
  Village village;
  cout << "Enter the number of land plots: ";
  cin >> village.nLandPlots;

  for (size_t i{}; i < village.nLandPlots; ++i) {
    LandPlot land;
    cout << "Enter the serial number of " << i + 1 << " land: ";
    cin >> land.serialNumber;
    cout << "Enter the area of " << i + 1 << " land plot: ";
    cin >> land.area;
    cout << "Enter the number of buildings of " << i + 1 << " land plot: ";
    do cin >> land.nBuildings;
    while (land.nBuildings < 1);

    for (size_t j = 0; j < land.nBuildings; ++j) {
      Buildings build;
      cout << "  Enter the type of " << j + 1 << " building: ";
      do cin >> build.type;
      while (build.type != "house" && build.type != "garage" &&
             build.type != "barn" && build.type != "shed" &&
             build.type != "bathhouse");

      if ("house" == build.type || "bathhouse" == build.type) {
        cout << "  Is there a furnace with a pipe (yes/no)? ";
        std::string answer;
        cin >> answer;
        "yes" == answer ? build.pipe = "pipe" : build.pipe = "";
      }

      cout << "  Enter the area of " << j + 1 << " building: ";
      do cin >> build.area;
      while (build.area > land.area);

      if ("house" == build.type) {
        cout << "  Enter the number of floors of " << j + 1 << " building: ";
        do cin >> build.nFloors;
        while (build.nFloors < 1 || build.nFloors > 3);
        for (size_t k{}; k < build.nFloors; ++k) {
          Floors floor;
          cout << "    Enter the height of rooms on the " << k + 1
               << " floor: ";
          cin >> floor.height;

          cout << "    Enter the number of rooms: on the " << k + 1
               << " floor: ";
          do cin >> floor.nRooms;
          while (floor.nRooms < 2 || floor.nRooms > 4);
          for (size_t h = 0; h < floor.nRooms; ++h) {
            Rooms room;
            cout << "      Enter the type of the " << h + 1 << " room: ";
            do cin >> room.type;
            while (room.type != "bedroom" && room.type != "kitchen" &&
                   room.type != "bathroom" && room.type != "children's" &&
                   room.type != "living");
            cout << "      Enter the area of the " << h + 1 << " room: ";
            do cin >> room.area;
            while (room.area > build.area);
            floor.rooms.push_back(room);
          }
          build.floors.push_back(floor);
        }
      }
      land.builds.push_back(build);
    }
    village.landPlot.push_back(land);
  }

  double sumLandArea{}, sumBuildsArea{};
  for (size_t i{}; i < village.nLandPlots; ++i) {
    sumLandArea += village.landPlot[i].area;
    for (size_t j{}; j < village.landPlot[i].nBuildings; ++j)
      sumBuildsArea += village.landPlot[i].builds[j].area;
  }

  cout << "\nOccupied area of houses is " << sumBuildsArea / sumLandArea * 100
       << "%" << endl;

  cout << "\x1b[0m";
  return 0;
}