#include <iostream>
#include <vector>
using namespace std;

long cnt = 0;

vector<int> merge(vector<int> left, vector<int> right) {
	vector<int> sorted;
	int lcnt = 0, rcnt = 0, l = 0, r = 0;

	while (lcnt < left.size() || rcnt < right.size()) {
		if (lcnt == left.size()) {
			sorted.emplace_back(right[rcnt++]);
		} else if (rcnt == right.size()) {
			sorted.emplace_back(left[lcnt++]);
		} else if (left[lcnt] <= right[rcnt]) {
			sorted.emplace_back(left[lcnt++]);
		} else {
			sorted.emplace_back(right[rcnt++]);
			cnt += left.size() - lcnt;
		}
	}
	return sorted;
}

vector<int> mergeSort(vector<int> v) {
	if (v.size() > 1) {
		int m = v.size() / 2;
		vector<int> v1(v.begin(), v.begin() + m);
		vector<int> v2(v.begin() + m, v.end());
		return merge(mergeSort(v1), mergeSort(v2));
	}
	return v;
}

int main() {
	vector<int> a, sorted;
	int size = 0;
	cin >> size;

	for (int i = 0; i < size; ++i) {
		int n = 0;
		cin >> n;
		a.push_back(n);
	}

	sorted = mergeSort(a);

	cout << cnt << endl;

	return 0;
}
