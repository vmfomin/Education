/**
 * @file      main.c
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Процедура умножения 2-х чисел типа uint_32t друг на друга. Для
 * представления чисел и для выполнения всех операций используются массивы
 * uint16_t (т.е. разрешено использовать только uint_16t).
 * Результат операции также uint16_t.
 * @version   0.1
 * @date      27-04-2021
 * @copyright Copyright (c) 2021
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Number_t {
  uint16_t number[4];
} Number;

void splitNumber(Number*, int64_t);
uint64_t mergeNumber(const Number*);

int main() {
  puts("\x1b[2J");
  Number one;  // init first number.
  for (int i = 0; i < 4; ++i) one.number[i] = 0u;

  {
    uint32_t num = 1123033334u;
    splitNumber(&one, num);
  }
  uint32_t first = (uint32_t)mergeNumber(&one);
  printf("1st number = %d\n", first);

  Number two;  // init second number.
  for (int i = 0; i < 4; ++i) two.number[i] = 0u;

  {
    uint32_t num = 1123033334u;
    splitNumber(&two, num);
  }

  uint32_t second = (uint32_t)mergeNumber(&two);
  printf("2nd number = %d\n", second);

  Number mult;  // 12612038827515556
  for (int i = 0; i < 4; ++i) mult.number[i] = 0u;
  uint16_t isMultiply = 0;
  while (!isMultiply) {
    if (1 == (two.number[0] & 1))
      for (int i = 0; i < 4; ++i) mult.number[i] += one.number[i];

    for (int i = 0; i < 4; ++i) {
      if (i < 3) {
        two.number[i] = two.number[i] >> 1 | two.number[i + 1] & 1;
        one.number[i + 1] |= one.number[i] >> 15;
      } else {
        two.number[i] >>= 1;
      }
      one.number[i] <<= 1;
    }
    uint32_t sum = 0;
    for (int j = 0; j < 4; ++j) sum += two.number[j];
    if (0 == sum) isMultiply = 1;
  }

  uint64_t result = mergeNumber(&mult);
  printf("result     = %llu\n", result);

  return 0;
}

void splitNumber(Number* number, int64_t num64) {
  for (int i = 0; i < 4; ++i) {
    number->number[i] |= (uint16_t)num64;
    num64 >>= 16;
    if (0 == num64) break;
  }
}

uint64_t mergeNumber(const Number* number) {
  int64_t result = 0;
  for (int i = 0; i < 4; ++i) result |= (uint64_t)(number->number[i]) << i * 16;
  return result;
}