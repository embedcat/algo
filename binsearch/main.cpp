#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>

int get_pos(const std::vector<int> &numbers, int number) {
	int l = 0;
	int r = numbers.size();
	while (l <= r) {
		int m = (l + r) / 2;
		if (numbers[m] == number) {
			return m + 1;
		} else if (numbers[m] > number) {
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	return -1;
}

int main(void) {
  size_t number_count;
  std::cin >> number_count;
  std::vector<int> numbers(number_count);
  for (auto &number:numbers) {
    std::cin >> number;
  }
  assert(std::is_sorted(numbers.begin(), numbers.end()));

  size_t query_count;
  std::cin >> query_count;
  while (query_count-- > 0) {
    int number;
    std::cin >> number;
    std::cout << get_pos(numbers, number) << " ";
  }
  std::cout << std::endl;
}
