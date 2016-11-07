#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

int	get_max_sum(int n, std::vector<int> *s) {
	long sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i;
		if (sum + i + 1 > n) {
			s->push_back(i + n - sum);
			return i;
		} else {
			s->push_back(i);
		}
	}	
	return 0;
}

int main(void) {
  int num;
  std::cin >> num;
	
	std::vector<int> sum;
	int k = get_max_sum(num, &sum);
	
  std::cout << k << std::endl;
  for (std::size_t i = 0; i < sum.size(); i++) {
    std::cout << sum[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
