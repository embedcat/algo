#include <iostream>
#include <vector>
#include <algorithm>
#include <ios>
using namespace std;

long getNumLessThanOrEquals(const vector<long> v, long x) {
	long l = 0, r = v.size() - 1;
	long m = 0;

	while (1) {
		m = (l + r) / 2;
		if (r <= l) {
			if (x >= v[m]) {
				return m + 1;
			} else {
				return m;
			}
		}
		if (x >= v[m]) {
			l = m + 1;
		} else {
			r = m - 1;
		}

	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n = 0, m = 0;
	cin >> n >> m;

	vector<long> left, right;
	for (int i = 0; i < n; i++) {
		long a, b;
		cin >> a >> b;
		left.emplace_back(a);
		right.emplace_back(b);
	}

	sort(left.begin(), left.end());
	sort(right.begin(), right.end());

	vector<long> dots;
	for (int i = 0; i < m; i++) {
		long x;
		cin >> x;
		dots.emplace_back(x);
	}

	vector<long> cnt;
	for (auto it : dots) {
		long starts, ends;
		starts = getNumLessThanOrEquals(left, it);
		ends = getNumLessThanOrEquals(right, it);
		cnt.emplace_back(starts - ends);
	}

	for (auto it : cnt) {
		cout << it << " ";
	}

	return 0;
}
