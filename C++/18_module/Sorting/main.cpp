/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     implemented types of sorting
 * @version   0.1
 * @date      02-03-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <iterator>
#include <vector>

using std::vector;

/**
 * @brief     Selection sorting
 * @tparam    T             type of vector
 * @param     array           sorting vector
 */
template <class T>
void selectSort(T& array) {
  for (int i = array.size() - 1; i >= 0; --i) {
    int max_index{};
    for (int j{}; j <= i; ++j)
      if (array[j] > array[max_index]) max_index = j;
    std::swap(array[i], array[max_index]);
  }
}

/**
 * @brief     Bubble sorting
 * @tparam    T             type of vector
 * @param     array           sorting vector
 */
template <class T>
void bubbleSort(T& array) {
  for (int i{}; i < array.size(); ++i)
    for (int j{}; j < array.size() - i - 1; ++j)
      if (array[j] > array[j + 1]) std::swap(array[j], array[j + 1]);
}

/**
 * @brief     Quick sorting
 * @tparam    T             Input class
 * @param     array         sorting vector
 * @param     last          bigger digit
 */
template <class T>
void quickSort(T array, int last) {
  int i{};
  int j{last};
  int pivot = *(array + (last >> 1));

  while (i <= j) {
    while (*(array + i) < pivot) ++i;
    while (*(array + j) > pivot) --j;
    if (i <= j) std::swap(*(array + i++), *(array + j--));
  }
  if (j > 0) quickSort(array, j);
  if (last > i) quickSort(array + i, last - i);
}

int main() {
  using std::cout;
  cout << "\x1b[2J";

  const vector<int> array{7, 1, 5,  4,  6, -20, 100, 5, 3, 10,
                          4, 2, 14, 67, 2, 11,  33,  1, 15};
  cout << "Before sorting:    ";
  std::copy(array.begin(), array.end(),
            std::ostream_iterator<int>(std::cout, " "));

  cout << "\nSelection sorting: ";
  vector<int> s_sortVec(array);
  selectSort(s_sortVec);
  std::copy(s_sortVec.begin(), s_sortVec.end(),
            std::ostream_iterator<int>(std::cout, " "));

  cout << "\nBubble sorting:    ";
  vector<int> b_sortVec(array);
  bubbleSort(b_sortVec);
  std::copy(b_sortVec.begin(), b_sortVec.end(),
            std::ostream_iterator<int>(std::cout, " "));

  cout << "\nQuick sorting:     ";
  vector<int> q_sortVec(array);
  quickSort(q_sortVec.begin(), array.size() - 1);
  std::copy(q_sortVec.begin(), q_sortVec.end(),
            std::ostream_iterator<int>(std::cout, " "));

  cout << "\n";
  cout << "\x1b[37m\n";

  return 0;
}