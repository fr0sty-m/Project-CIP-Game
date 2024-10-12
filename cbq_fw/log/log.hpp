#ifndef CBQ_FRAMEWORK_LOGGING_HPP
#define CBQ_FRAMEWORK_LOGGING_HPP

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>

namespace fr0sty {

#ifdef ENABLE_LOGGING

template <typename... Args> void log(const Args &...args) {
  auto now =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  std::cout << "[" << std::put_time(std::localtime(&now), "%H:%M:%S") << "] ";
  std::cout << "FR0STY: ";
  ((std::cout << args << " "), ...); // Fold expression to print all arguments
  std::cout << std::endl;
}

template <typename... Args> void error(const Args &...args) {
  auto now =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  std::cerr << "[" << std::put_time(std::localtime(&now), "%H:%M:%S") << "] ";
  std::cerr << "FR0STY ERROR: ";
  ((std::cerr << args << " "), ...); // Fold expression to print all arguments
  std::cerr << std::endl;
}

#else

template <typename... Args> void log(const Args &...) {
  // Logging is disabled
}

template <typename... Args> void error(const Args &...) {
  // Logging is disabled
}

#endif

} // namespace fr0sty

#endif // !CBQ_FRAMEWORK_LOGGING_HPP
