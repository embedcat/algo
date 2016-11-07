#include <cassert>
#include <iostream>
#define MAX_N	1000000

class Fibonacci {
 public:
  static int get(int n) {
    assert(n >= 0);
    int i = 0;
    static int a[MAX_N] = {0};
    a[0] = 0;
    a[1] = 1;
    for (i = 2; i <= n; i++) {
    	a[i] = (a[i-1] + a[i-2]) % 10;
	}
    
    return a[n];
  }
};

int main(void) {
  int n;
  std::cin >> n;
  std::cout << Fibonacci::get(n) << std::endl;
  return 0;
}
