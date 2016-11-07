#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>
using namespace std;

#define SEGM_N	50000
#define DOTS_N	50000
#define RANGE	RAND_MAX

typedef pair<long, long> Segment;

bool segmentComparator(Segment s1, Segment s2) {
	if (s1.first < s2.first)
		return true;
	else if (s1.first == s2.first)
		return s1.second < s2.second;
	return false;
}

int main() {
	srand(time(NULL));
	vector<Segment> seg;
	vector<long> dots;

	for (int i = 0; i < SEGM_N; i++) {
		long x1 = rand() % RAND_MAX - RAND_MAX / 2;
		long x2 = rand() % RAND_MAX - RAND_MAX / 2;
		long y1, y2;
		do {
			y1 = rand() % RAND_MAX - RAND_MAX / 2;
			y2 = rand() % RAND_MAX - RAND_MAX / 2;
		} while (y1*y2 < x1*x2);
		seg.emplace_back(x1*x2, y1*y2);
	}

	for (int i = 0; i < SEGM_N; i++) {
		long x = rand() % RAND_MAX - RAND_MAX / 2;
		dots.emplace_back(x);
	}

	ofstream fout;

	fout.open("in_random.txt");
	fout << SEGM_N << " " << DOTS_N << endl;
	for (auto it : seg) {
		fout << it.first << " " << it.second << endl;
	}
	for (auto it : dots) {
		fout << it << " ";
	}
	fout.close();

	sort(seg.begin(), seg.end(), segmentComparator);
	fout.open("in_sort.txt");
	fout << SEGM_N << " " << DOTS_N << endl;
	for (auto it : seg) {
		fout << it.first << " " << it.second << endl;
	}
	for (auto it : dots) {
		fout << it << " ";
	}
	fout.close();

	return 0;
}
