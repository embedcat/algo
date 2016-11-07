#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
using namespace std;

map<char,vector<bool> > table;	// code table: 'a' = 0101

class Node {
public:
	char c;
	int n;
	Node *left, *right;	
	
	Node() {
		left = right = NULL;
	}	
	Node(Node *l, Node *r) {
		left = l;
		right = r;
		n = l->n + r->n;
	}
};

struct myCompare {
    bool operator()(const Node* l, const Node* r) const {
		return l->n < r->n;
	}
};
 
void buildTable(Node *root) {	
	static vector<bool> code;	// bin code for symbol 
	
	if (root->left != NULL) {
		code.push_back(0);
    	buildTable(root->left);
	}
    if (root->right != NULL) {
		code.push_back(1);
        buildTable(root->right);
	}
    if (root->left == NULL && root->right == NULL) {
    	table[root->c] = code;     	
	}
   code.pop_back();
}

int main(int argc, char** argv) {
	string s;
	getline(cin, s);

	map<char, int> m;
	for (int i = 0; i < s.length(); i++ ) {
		m[s[i]]++;
	}
	
	list<Node*> nodes;
	for (auto i = m.begin(); i != m.end(); i++ ) {
		Node *p = new Node;
		p->c = i->first;
		p->n = i->second;
		nodes.push_back(p);
	}
		
	int symNum =  nodes.size();
	Node *root = NULL;
	
	if (symNum == 1) {
		root = nodes.front();
		vector<bool> tmpv;
		tmpv.push_back(0);
		table[root->c] = tmpv;	
	} else {
		while (nodes.size() != 1) {  
		    nodes.sort(myCompare());
		
		    Node *sonL = nodes.front();
		    nodes.pop_front();
		    
		    Node *sonR = nodes.front(); 
		    nodes.pop_front();
		    
			Node *parent = new Node(sonL, sonR); 
	    	nodes.push_back(parent);
		}
		root = nodes.front();
		buildTable(root);
	}
	
	string output = "";
	for (int i = 0; i < s.length(); i++) {
		vector<bool> x = table[s[i]];
		for (int j = 0; j < x.size(); j++) {
			output.push_back(x[j] ? '1' : '0');
		}
	}
	cout << symNum << " " << output.length() << endl;
	
	for (auto i = table.begin(); i != table.end(); i++) {
		cout << i->first << ": ";
		for (int j = 0; j < (i->second).size(); j++) {
			cout << i->second[j];
		}	
		cout << endl;
	}
	
	cout << output;
	
	return 0;
}
