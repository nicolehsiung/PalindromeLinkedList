//palindrome by vector and node
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Node {
public:
	int data;
	Node *ptr;
};

bool palin(Node* head, vector<int> rlist, int s) {

	for (int i = 0; i < (s / 2); i++) {
		if (rlist.front() != head->data) {
			return false;
		}
		else if (i != (s / 2 - 1)) {
			rlist.erase(rlist.begin());
			head = head->ptr;
		}
		else if (i == (s / 2 - 1)) {
			return true;
		}
	}
}

int main() {

	vector<int>rlist = {};
	Node *head = NULL;
	string input = {};
	int count = 0;
	cin >> input;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] != '-'&&input[i] != '>') {
			rlist.push_back((int)input[i]-48);
			Node *add = new Node();;
			add->data = ((int)input[i]-48);
			add->ptr = head;
			head = add;
			count++;
		}
	}

	if (!palin(head, rlist,count)) 
		cout << "false";
	else
		cout << "true";
	system("pause");
	return 0;
}
