#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <stdio.h>
#include <ios>
using namespace std;

typedef pair<long, long> Segment;

typedef enum {
	START, END, DOT,
} dot_e;

typedef struct {
	long n;
	dot_e t;
} Dot;

bool dotComparator(Dot d1, Dot d2) {
	return d1.n < d2.n;
}

bool segmentComparator(Segment s1, Segment s2) {
	if (s1.first < s2.first)
		return true;
	else if (s1.first == s2.first)
		return s1.second < s2.second;
	return false;
}

template<typename T>
T getNumLessThanOrEquals(const vector<T> v, T x) {
	T l = 0, r = v.size() - 1;
	T m = 0;

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

template<typename T>
T getDotsCount(vector<Dot> dots, T x) {
	T cnt = 0;
	for (int j = 0; j < dots.size(); j++) {
		if (dots[j].n > x) {
			break;
		}
		if (dots[j].t == START) {
			cnt++;
		}
		if (dots[j].t == END && dots[j].n < x) {
			cnt--;
		}
	}
	return cnt;
}

template<typename T>
T getDotsCountNaive(vector<Segment> seg, T x) {
	T cnt = 0;
	if (x < seg[0].first || x > seg[seg.size() - 1].second) {
		return 0;
	}
	for (auto it : seg) {
		if ((x >= it.first) && (x <= it.second)) {
			cnt++;
		}
		if ((cnt != 0) && (x < it.first)) {
			break;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	clock_t time_start = clock();

	int n = 0, m = 0;
	cin >> n >> m;

	vector<Dot> allDots;
	vector<Segment> seg;

	vector<long> left, right;
	for (int i = 0; i < n; i++) {
		long a, b;
		cin >> a >> b;
		left.emplace_back(a);
		right.emplace_back(b);

		Dot d;
		d.n = a;
		d.t = START;
		allDots.emplace_back(d);
		d.n = b;
		d.t = END;
		allDots.emplace_back(d);

		seg.emplace_back(a, b);
	}

	vector<long> dots;
	for (int i = 0; i < m; i++) {
		long x;
		cin >> x;
		dots.emplace_back(x);
	}

	clock_t time_after_input = clock() - time_start;
	clock_t time_s = clock();
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());
	sort(allDots.begin(), allDots.end(), dotComparator);
	sort(seg.begin(), seg.end(), segmentComparator);

	clock_t time_after_sort = clock() - time_s;
	time_s = clock();
	vector<int> cnt;
	for (auto it : dots) {
		int starts, ends;
		starts = getNumLessThanOrEquals(left, it);
		ends = getNumLessThanOrEquals(right, it);
		cnt.emplace_back(starts - ends);
	}

	clock_t time_after_algo1 = clock() - time_s;
	time_s = clock();
/*
	vector<long> cnt2;
	for (auto it : dots) {
		long count;
		count = getDotsCount(allDots, it);

		cnt2.emplace_back(count);
	}
*/
	clock_t time_after_algo2 = clock() - time_s;
	time_s = clock();
/*
	vector<long> cnt3;
	for (auto it : dots) {
		long count;
		count = getDotsCountNaive(seg, it);

		cnt3.emplace_back(count);
	}
*/
	clock_t time_after_algo3 = clock() - time_s;
	time_s = clock();
/*
	for (auto i = 0; i < cnt.size(); i++) {
		if (cnt[i] != cnt2[i] ||
				cnt[i] != cnt3[i] ||
				cnt2[i] != cnt3[i]) {
			cout << "Err: " << cnt[i] << " or " << cnt2[i] << " or " << cnt3[i] << endl;
		}
	}
*/

	 for (auto it : cnt) {
		 cout << it << " ";
	//	 printf("%d ", it);
	 }

	clock_t time_after_output = clock() - time_s;
	clock_t time_all = clock() - time_start;

	cout << endl;
	printf("Num: %d\n", n);
	printf("Input: %f\n", (float) time_after_input / CLOCKS_PER_SEC);
	printf("Sort: %f\n", (float) time_after_sort / CLOCKS_PER_SEC);
	printf("Algo1: %f\n", (float) time_after_algo1 / CLOCKS_PER_SEC);
	printf("Algo2: %f\n", (float) time_after_algo2 / CLOCKS_PER_SEC);
	printf("Algo3: %f\n", (float) time_after_algo3 / CLOCKS_PER_SEC);
	printf("Output: %f\n", (float) time_after_output / CLOCKS_PER_SEC);
	printf("All: %f\n", (float) time_all / CLOCKS_PER_SEC);

	return 0;
}
