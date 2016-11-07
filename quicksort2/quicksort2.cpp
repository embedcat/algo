#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getDotsLessThanNumber(const std::vector<int> &numbers, int number) {
	int l = 0;
	int r = numbers.size();
	while (l <= r) {
		int m = (l + r) / 2;
		/*
		if (numbers[m] == number) {
			return m + 1;
		} else
		*/
		if (numbers[m] > number) {
			r = m - 1;
		} else {
			l = m + 1;
		}
		if (l == r) {
			return l + 1;
		}
	}
	return 0;
}


int main() {
	int n = 0, m = 0;
	cin >> n >> m;

	vector<int> leftD, rightD;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		leftD.emplace_back(a);
		rightD.emplace_back(b);
	}

	sort(leftD.begin(), leftD.end());
	sort(rightD.begin(), rightD.end());

	for (auto it : leftD) {
		cout << it << " ";
	}
	cout << endl;

	for (int i = 0; i < m; i++) {
		int start = getDotsLessThanNumber(leftD, i);
		cout << "i = " << i << ". Less than: " << start << endl;

	}

/*
	for (int i = 0; i < m; i++) {
		int x, cnt = 0;
		cin >> x;

		int segStarts = get_pos(leftD, x);
		int segEnds = get_pos(rightD, x);
		cout << "X: " << x << ". Segm starts: " << segStarts << ". Segm ends: " << segEnds << ". Cnt: ";
		if (segStarts >= 0) cnt = segStarts - segEnds;

		cout << cnt << endl;
	}
	*/
	return 0;
}
