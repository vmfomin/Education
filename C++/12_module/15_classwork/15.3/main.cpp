/** Не самый безопасный банк
В банке находится 8 ячеек для не-очень-безопасного хранения денег. Все ячейки
представлены в виде массива чисел с плавающей точкой, который обозначают
хранимые в них суммы.  Вначале программы, с помощью стандартного ввода (cin), в
каждой из ячеек располагаются деньги, по очереди. После этого в банк приходит
клиент, который хочет посмотреть сумму, которая лежит в его конкретной ячейке.
Для этого клиент вводит в стандартный ввод (cin) свой пин-код от ячейки. В нашем
не самом безопасном банке пин-код - это просто индекс ячейки. После этого, сумма
в ячейке выводится в cout. Если пользователь указывает неправильный пин-код -
выводится сообщение об ошибке.
*/

#include <iostream>

bool isIndex(float cells[], const int &index, const int &count) {
  if (index < 0) {
    std::cerr << "Cell can't be less than 0!";
    return false;
  }

  if (index > count) {
    std::cerr << "Cell can't be greater than count!";
    return false;
  }

  return true;
}

int main() {
  float cells[8]{};
  std::cout << "Put money in the cells\n";

  for (auto &cell : cells) std::cin >> cell;

  std::cout << "\n";

  std::cout << "Check money in the cell\n";
  int index;
  std::cin >> index;
  --index;  // т.к. вводим пользователь вводит номер ячейки не с 0

  if (isIndex(cells, index, 8))
    std::cout << cells[index] << " money in the cell is " << index + 1 << "\n";
  else
    return -1;

  getchar();
  getchar();

  return 0;
}
