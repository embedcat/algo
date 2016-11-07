#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char** argv) {
	priority_queue<int> heap;
	int opNum = 0;
	cin >> opNum;
	string tmp;
	getline(cin, tmp);
	
	for (int i = 0; i < opNum; i++) {
		int n = 0;
		char c = getchar();
		if (c == 'I') {
			while (getchar() != ' ');
			cin >> n;
			getline(cin, tmp);
			heap.push(n);
		} else if (c == 'E') {
			getline(cin, tmp);
			if (!heap.empty()) {
				cout << heap.top() << endl;
				heap.pop();
			}
		} else {
			return -1;
		}
	}
	return 0;
}
