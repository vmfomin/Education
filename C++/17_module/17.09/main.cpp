/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Морской бой.
 * Требуется реализовать упрощённую игру в Морской бой. Игровое поле размером 10
 * на 10 клеток. Участвует двое игроков. В арсенале каждого из них: 4 маленьких
 * кораблика размером в одну клетку, 3 небольших корабля размером в две клетки,
 * 2 средних корабля размером в три клетки и один большой корабль размером в
 * четыре клетки. Для простоты, клетки поля пронумерованы по вертикали от 0 до
 * 9, и по горизонтали также от 0 до 9. Мы не будем использовать классические
 * наименования клеток, такие как B4, C6, а просто два индекса. Вначале игроки
 * по очереди расставляют корабли, начиная с самых маленьких и заканчивая
 * большими. Маленькие корабли в одну клетку расставляются с помощью указания
 * лишь одной клетки-точки на поле, к примеру 2,1. Корабли размерностью от двух
 * клеток и выше, расставляются с помощью координат их начала и конца, к
 * примеру: 0,1 - 0,3. Корабли могут быть установлены только строго вертикально,
 * или горизонтально. Установка корабля по диагонали — недопустимо, в случае
 * которого об этом тоже надо сообщить пользователю. Если корабль не может быть
 * размещён на заданных клетках из-за того, что он столкнётся с другим кораблём
 * (окажется на его клетках) или выйдет за пределы поля вообще, то игроку должно
 * быть сделано предупреждение, после которого он должен переставить корабль на
 * новые валидные координаты. Замечу, в нашем упрощённом варианте игры, мы не
 * будем обсчитывать соприкосновения кораблей друг с другом, а потому корабли
 * вполне можно будет размещать друг к другу вплотную — борт к борту. После того
 * как все корабли были расставлены начинается игра. Игроки по очереди атакуют
 * друг друга, называя координаты выстрела. После выстрела, в консоль выводится
 * информация о его результате: попал или мимо. Если выстрел успешен, клетка, на
 * которой был корабль (или его фрагмент) затирается и становится пустой. Игра
 * заканчивается тогда, когда все корабли одной из сторон будут полностью
 * уничтожены. Как только это произойдёт в консоль выводится информация с
 * номером игрока, который победил.
 * @version   0.1
 * @date      20-02-2021
 * @copyright Copyright (c) 2021
 */

#include "src/Battleships.h"

void printScreen(char PlayerOne[10][10], char PlayerTwo[10][10],
                 const uint16_t& odd) {
  std::cout
      << (odd % 2 != 0
              ? "\x1b[31m\t    Player one\x1b[37m\t\t\t\t    Player two\n"
              : "\t    Player one\t\t\t\t    \x1b[31mPlayer two\n\x1b[37m");
  std::cout << "\n";
  for (size_t i{}; i < 10; ++i) {
    if (0 == i) {
      std::cout << "   ";
      for (size_t j{}; j < 10; ++j) std::cout << j << "  ";
      std::cout << "  ||\t    ";
      for (size_t j{}; j < 10; ++j) std::cout << j << "  ";
      std::cout << "\n";
    }
    std::cout << i << "  ";
    for (size_t j{}; j < 10; ++j) std::cout << PlayerOne[i][j] << "  ";
    std::cout << "  ||    " << i << "  ";

    for (size_t j{}; j < 10; ++j) std::cout << PlayerTwo[i][j] << "  ";
    std::cout << "\n";
  }
  std::cout << "\n";
}

/**
 * @brief     Initialize screen players
 * @param     screen        what the player will see
 */
inline void initPlayerScreen(char screen[10][10]) {
  for (size_t i{}; i < 10; ++i)
    for (size_t j{}; j < 10; ++j) screen[i][j] = '.';
}

void shoot(Battleships& player, char PlayerScreen[10][10], uint16_t& nShoots) {
  do {
    std::cout << "Enter the coordinates to shoot: ";
    uint16_t x, y;
    std::cin >> x >> y;
    if (x > 9 || y > 9) {
      std::cout << "\x1b[31mError: incorrect coordinates!\x1b[37m\n";
      continue;
    }

    if ('o' == player.getLocation(x, y) && PlayerScreen[x][y] != 'x') {
      PlayerScreen[x][y] = 'x';
      std::cout << "\x1b[32mYou hit him!\x1b[37m\n";
      Sleep(600);
      ++nShoots;
      break;
    } else if ('*' == PlayerScreen[x][y] || 'x' == PlayerScreen[x][y]) {
      std::cout << "\x1b[31mYou've already shot at this place!\x1b[37m\n";
      continue;
    } else {
      PlayerScreen[x][y] = '*';
      std::cout << "You missed it!\n";
      Sleep(600);
      break;
    }
  } while (true);
}

int main() {
  Battleships playerOne;
  std::cout << "\x1b[2JThe first player will fill their battlefield:\n";
  playerOne.fillField();
  std::cout << "\x1b[2JThe first player's battlefield:\n";
  playerOne.printField();

  Battleships playerTwo;
  std::cout << "\x1b[2JThe second player will fill their battlefield:\n";
  playerTwo.fillField();
  std::cout << "The second player's battlefield:\n";
  playerTwo.printField();

  char PlayerScreenOne[10][10];
  initPlayerScreen(PlayerScreenOne);

  char PlayerScreenTwo[10][10];
  initPlayerScreen(PlayerScreenTwo);

  uint16_t countOne{}, countTwo{}, odd{};
  while (true) {
    if (odd % 2 == 0) {
      std::cout << "\x1b[2J\t\t\t   First player's move\n";
      printScreen(PlayerScreenOne, PlayerScreenTwo, odd);
      shoot(playerTwo, PlayerScreenTwo, countOne);
    } else {
      std::cout << "\x1b[2J\t\t\t  Second player's move\n";
      printScreen(PlayerScreenOne, PlayerScreenTwo, odd);
      shoot(playerOne, PlayerScreenOne, countTwo);
    }

    if (20 == countOne) {
      std::cout << "\x1b[2J";
      printScreen(PlayerScreenOne, PlayerScreenTwo, odd);
      std::cout << "\n\x1b[36mThe first player won!\x1b[37m\n";
      break;
    } else if (20 == countTwo) {
      std::cout << "\x1b[2J";
      printScreen(PlayerScreenOne, PlayerScreenTwo, odd);
      std::cout << "\n\x1b[36mThe second player won!\x1b[37m\n";
      break;
    }
    ++odd;
  }

  std::cout << "\x1b[37m\n";
  return 0;
}