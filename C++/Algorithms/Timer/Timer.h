/**
 * @file      Timer.h
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Measuring the execution time (timing) of the code
 * @version   0.1
 * @date      17-03-2021
 * @copyright Copyright (c) 2021
 */

#include <chrono>

class Timer {
 private:
  using clock_t = std::chrono::high_resolution_clock;
  using second_t = std::chrono::duration<double, std::ratio<1> >;

  std::chrono::time_point<clock_t> m_beg;

 public:
  Timer() : m_beg{clock_t::now()} {}
  ~Timer() = default;

  void reset() { m_beg = clock_t::now(); }

  double elapsed() const {
    return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
  }
};