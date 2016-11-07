#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

typedef pair<int, int> Segment;

bool segmentComparator(Segment s1, Segment s2) {
	if (s1.first < s2.first)
		return true;
	else if (s1.first == s2.first)
		return s1.second < s2.second;
	return false;
}

int main() {
	int n = 0, m = 0;
	cin >> n >> m;

	vector<Segment> seg;
	vector<int>	dots;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		seg.emplace_back(a, b);
	}

	sort(seg.begin(), seg.end(), segmentComparator);

	for	(int i = 0; i < m; i++) {
		int x = 0;
		cin >> x;
		dots.emplace_back(x);
	}


	for (int i = 0; i < m; i++) {
		int x, cnt = 0;
//		cin >> x;
		x = dots[i];
		if (x < seg[0].first || x > seg[seg.size() - 1].second) {
			cout << "0 ";
			continue;
		}
		for (auto it : seg)  {
			if ((x >= it.first) && (x <= it.second)) {
				cnt++;
			}
			if ((cnt != 0) && (x < it.first)) {
				break;
			}
		}
		cout << cnt << " ";
	}
	return 0;
}
