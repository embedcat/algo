#include <iostream>
#include <vector>
#include <algorithm>
#include <ios>
using namespace std;

typedef enum {
	START, END, DOT,
} dot_e;

typedef struct {
	int n;
	dot_e t;
} Dot;

bool dotComparator(Dot d1, Dot d2) {
	return d1.n < d2.n;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<Dot> dots;
	for (int i = 0; i < n; i++) {
		int a, b;
		Dot d;
		cin >> a >> b;
		d.n = a;
		d.t = START;
		dots.emplace_back(d);
		d.n = b;
		d.t = END;
		dots.emplace_back(d);
	}

	sort(dots.begin(), dots.end(), dotComparator);
	/*
	 for (auto it : dots) {
	 char c = it.t ? 'E' : 'S';
	 cout << it.n << '(' << c << ") ";
	 }
	 cout << endl;
	 */
	vector<int> counter;
	for (int i = 0; i < m; i++) {
		int x, cnt = 0;
		cin >> x;
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

//		cout << "x: " << x << ". cnt: "<< cnt << endl;
//		cout << cnt << " ";
		counter.emplace_back(cnt);

	}

	for (auto it : counter) {
		cout << it << " ";
	}

	return 0;
}
