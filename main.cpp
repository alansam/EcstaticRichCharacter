
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>

using namespace std::literals;

int main(int argc, char const * argv[]) {
  std::array<int, 10> flub { 42, -10, 77, 4096, 10, -666, 666, 0, 66789, 21, }; //  array
  size_t cc;
  size_t const cc_max(5);
  auto pa = [& cc](auto n_) {
    std::cout << std::setw(8) << n_ << ((++cc % cc_max == 0) ? "\n"s : ""s);
  };

  std::cout << "Array contents:"s << std::endl;
  cc = 0;
  std::for_each(flub.cbegin(), flub.cend(), pa); // looping
  std::cout << std::endl;

  std::cout << "Sorted array:"s << std::endl;
  std::sort(flub.begin(), flub.end(), std::greater<>());
  cc = 0;
  std::for_each(flub.cbegin(), flub.cend(), pa); // looping
  std::cout << std::endl;

  auto max = 25;
  auto ct = std::count_if(flub.cbegin(), flub.cend(), [& max](auto n_) { return n_ > max; });  // decision & counter
  std::cout << "elements greater than "s << max << ": "s << ct << std::endl;

  return 0;
}
