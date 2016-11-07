#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
	map<string, char> m;
	int lettersNum = 0, strSize = 0;
	
	cin >> lettersNum >> strSize;
	string tmp;
	getline(cin, tmp);
	
	for (int i = 0; i < lettersNum; i++) {
		char c;
		string s = "";
		scanf("%c%*c%*c", &c);
		getline(cin, s);
		m.emplace(s, c);
	}
	
	string str;
	getline(cin, str);
#if 0
	for (auto i = m.begin(); i != m.end(); i++) {
		cout << i->first << i->second << endl;
	}
#endif	
	string s = "";
	for (int i = 0; i < str.length(); i++) {
		s.push_back(str[i]);
		char c = m[s];
		if (c) {
			cout << c;
			s = "";
		}
	}
	return 0;
}
