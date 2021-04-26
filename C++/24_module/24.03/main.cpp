/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задание 3. Реализация математического вектора.
 * Реализуйте структуру двумерного математического вектора и основные операции
 * над ним. Обе координаты вектора (x и y) должны быть вещественными числами.
 * Вначале программы пользователь вводит команду, которая соответствует
 * требуемой операции. Далее, в зависимости от операции, пользователь вводит её
 * аргументы. Это могут быть как вектора, так и обычные, скалярные значения. В
 * результате в стандартный вывод помещается результат. Это тоже может быть или
 * вектор, или скаляр.
 * @version   0.1
 * @date      26-04-2021
 * @copyright Copyright (c) 2021
 */

#include <cmath>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

struct Coordinates {
  double x{};
  double y{};
};

std::ostream& operator<<(std::ostream& out, const Coordinates& coord) {
  out << coord.x << " " << coord.y << endl;
  return out;
}

Coordinates operator+(const Coordinates& one, const Coordinates& two) {
  Coordinates coordOut{};
  coordOut.x = one.x + two.x;
  coordOut.y = one.y + two.y;
  return coordOut;
}

Coordinates operator-(const Coordinates& one, const Coordinates& two) {
  Coordinates coordOut{};
  coordOut.x = one.x - two.x;
  coordOut.y = one.y - two.y;
  return coordOut;
}

Coordinates operator*(const Coordinates& coord, const double& scalar) {
  Coordinates coordOut{};
  coordOut.x = coord.x * scalar;
  coordOut.y = coord.y * scalar;
  return coordOut;
}

void add();
void subtract();
void scale();
double length(Coordinates&);
void normalize();

int main() {
  cout << "\x1b[2J";

  int16_t command{-1};
  cout << "Enter 1 to adding two vectors;\n"
       << "Enter 2 to subtracting two vectors;\n"
       << "Enter 3 to multiplying a vector by a scalar;\n"
       << "Enter 4 to finding the length of a vector;\n"
       << "Enter 5 to normalize a vector;\n\n";
  cin >> command;
  Coordinates coord{};
  switch (command) {
    case 1:
      add();
      break;
    case 2:
      subtract();
      break;
    case 3:
      scale();
      break;
    case 4:
      cout << "\nEnter the coordinates of the vector: ";
      cin >> coord.x >> coord.y;
      cout << "The length of vector is " << length(coord) << endl;
      break;
    case 5:
      normalize();
      break;
    default:
      cout << "Command not found!\n";
      break;
  }

  cout << "\x1b[0m";
  return 0;
}

void add() {
  cout << "Enter the coordinates of the first vector:\t";
  Coordinates one;
  cin >> one.x >> one.y;

  cout << "Enter the coordinates of the second vector:\t";
  Coordinates two;
  cin >> two.x >> two.y;

  cout << "The new vector is " << one + two << endl;
}

void subtract() {
  cout << "Enter the coordinates of the first vector:\t";
  Coordinates one;
  cin >> one.x >> one.y;

  cout << "Enter the coordinates of the second vector:\t";
  Coordinates two;
  cin >> two.x >> two.y;

  cout << "The new vector is " << one - two << endl;
}

void scale() {
  cout << "Enter the coordinates of the vector:\t";
  Coordinates coord;
  cin >> coord.x >> coord.y;

  cout << "Enter the scalar:\t";
  int32_t scalar;
  cin >> scalar;

  cout << "The new vector is " << coord * scalar << endl;
}

double length(Coordinates& coord) {
  return std::sqrt(coord.x * coord.x + coord.y * coord.y);
}

void normalize() {
  cout << "Enter the coordinates of the vector:\t";
  Coordinates coord;
  cin >> coord.x >> coord.y;
  double inverseLength{1. / length(coord)};
  cout << "The vector after normalize " << coord * inverseLength << endl;
}