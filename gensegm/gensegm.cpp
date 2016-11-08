#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;

#define SEGM_N	100000
#define DOTS_N	100000
#define RANGE	RAND_MAX

typedef pair<long, long> Segment;

bool segmentComparator(Segment s1, Segment s2) {
	if (s1.first < s2.first)
		return true;
	else if (s1.first == s2.first)
		return s1.second < s2.second;
	return false;
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	vector<Segment> seg;
	vector<long> dots;
	int segm_n = SEGM_N, dots_n = DOTS_N;

	if (argc > 1) {
		istringstream iss(argv[1]);
		int value;

		if (iss >> value) {
			// Conversion successful
			segm_n = value;
			dots_n = value;
		}
	}


	for (int i = 0; i < segm_n; i++) {
		long x1 = rand() % RAND_MAX - RAND_MAX / 2;
		long x2 = rand() % RAND_MAX - RAND_MAX / 2;
		long y1, y2;
		do {
			y1 = rand() % RAND_MAX - RAND_MAX / 2;
			y2 = rand() % RAND_MAX - RAND_MAX / 2;
		} while (y1 * y2 < x1 * x2);
		seg.emplace_back(x1 * x2, y1 * y2);
	}

	for (int i = 0; i < dots_n; i++) {
		long x = rand() % RAND_MAX - RAND_MAX / 2;
		dots.emplace_back(x);
	}

	ofstream fout;

	fout.open("in_random.txt");
	fout << segm_n << " " << dots_n << endl;
	for (auto it : seg) {
		fout << it.first << " " << it.second << endl;
	}
	for (auto it : dots) {
		fout << it << " ";
	}
	fout.close();

	sort(seg.begin(), seg.end(), segmentComparator);
	fout.open("in_sort.txt");
	fout << segm_n << " " << dots_n << endl;
	for (auto it : seg) {
		fout << it.first << " " << it.second << endl;
	}
	for (auto it : dots) {
		fout << it << " ";
	}
	fout.close();

	vector<Segment> seg2;
	vector<long> dots2;

	long x1 = rand() % RAND_MAX - RAND_MAX / 2;
	long x2 = rand() % RAND_MAX - RAND_MAX / 2;
	long y1, y2;
	do {
		y1 = rand() % RAND_MAX - RAND_MAX / 2;
		y2 = rand() % RAND_MAX - RAND_MAX / 2;
	} while (y1 * y2 < x1 * x2);
	for (int i = 0; i < segm_n; i++) {
		seg2.emplace_back(x1 * x2, y1 * y2);
	}

	long x = rand() % RAND_MAX - RAND_MAX / 2;
	for (int i = 0; i < dots_n; i++) {
		dots2.emplace_back(x);
	}

	fout.open("in_same.txt");
	fout << segm_n << " " << dots_n << endl;
	for (auto it : seg2) {
		fout << it.first << " " << it.second << endl;
	}
	for (auto it : dots2) {
		fout << it << " ";
	}
	fout.close();

	return 0;
}
