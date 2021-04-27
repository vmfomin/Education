/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 3. Калькулятор.
 * Требуется создать небольшую программу для вычисления простых действий с
 * числами. При запуске программа ожидает пользовательского ввода во
 * временную переменную строку. После ввода строки, она распарсивается на
 * отдельные члены. Строка записывается в форме “<число-1><действие><число-2>”
 * (без пробелов). Оба числа - это значения с плавающей точкой, повышенной
 * точности (double). Действие может быть одним из: +, -, /, *. Результат
 * действия выводится в стандартный вывод cout.
 * @version   0.1
 * @date      09-03-2021
 * @copyright Copyright (c) 2021
 */

#include <iomanip>
#include <iostream>
#include <sstream>

int main() {
  using std::cin;
  using std::cout;
  cout << "\x1b[2J";

  cout << "Enter expression: ";
  std::string expression;
  cin >> expression;

  std::stringstream expressionStream{expression};

  char operation{};
  double a{};
  double b{};

  expressionStream >> a;
  expressionStream >> operation;
  expressionStream >> b;

  cout << std::setprecision(15);
  switch (operation) {
    case '+':
      cout << "Sum = " << a + b;
      break;
    case '-':
      cout << "Subtraction = " << a - b;
      break;
    case '*':
      cout << "Multiplication = " << a * b;
      break;
    case '/':
      cout << "Division = " << a / b;
      break;
    default:
      break;
  }

  cout << "\n";
  return 0;
}