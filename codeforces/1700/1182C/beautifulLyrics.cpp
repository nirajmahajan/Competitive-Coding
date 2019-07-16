#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

vector <pair<char, string> > words[10000000];
stack <pair<string, string> > same_ends; 
stack <pair<string, string> > diff_ends; 


bool isVow(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return true;
	}
	return false;
}

pair<int, char> read(string s) {
	int vov = 0;
	char curr;
	for (int i = 0; i < s.size(); i++) {
		if (isVow(s[i])) {
			curr = s[i];
			vov++;
		}
	}
	return make_pair(vov, curr);
}

void process(vector <pair<char, string> > lst) {
	stack <string> stacks[5];


	for (auto mem : lst) {
		string str = mem.second;
		char ends = mem.first;
		if (ends == 'a') {
			stacks[0].push(str);
		} else if (ends == 'e') {
			stacks[1].push(str);
		} else if (ends == 'i') {
			stacks[2].push(str);
		} else if (ends == 'o') {
			stacks[3].push(str);
		} else {
			stacks[4].push(str);
		}
	}

	stack <string> diff_ends_temp; 

	for(auto lst : stacks) {
		int size =lst.size();
		if (size == 0) {
			continue;
		} else if (size % 2 == 1) {
			diff_ends_temp.push(lst.top());
			lst.pop();
		}

		while (!lst.empty()) {
			string a, b;
			a = lst.top();
			lst.pop();
			b = lst.top();
			lst.pop();
			same_ends.push(make_pair(a, b));
		}
	}

	int diff_size = diff_ends_temp.size();

	if (diff_size % 2 == 1) {
		diff_ends_temp.pop();
		diff_size--;
	}

	while (!diff_ends_temp.empty()) {
		string a = diff_ends_temp.top();
		diff_ends_temp.pop();
		string b = diff_ends_temp.top();
		diff_ends_temp.pop();

		diff_ends.push(make_pair(a, b));
	}
}

void printAll() {
	int diff_size = diff_ends.size();
	int same_size = same_ends.size();

	if (same_ends.size() == 0) {
		printf("0\n");
		return;
	}

	if (diff_size > same_size) {
		cout << same_size << endl;
	} else {
		if ((same_size - diff_size) % 2 == 1) {
			same_ends.pop();
			same_size--;
		}
		int ans = diff_size + (same_size - diff_size)/2;
		cout << ans << endl;
	} 

	while (!diff_ends.empty() && !same_ends.empty()) {
		pair<string, string> second = same_ends.top();
		same_ends.pop();
		auto first = diff_ends.top();
		diff_ends.pop();

		cout << first.first << " " << second.first << endl << first.second << " " << second.second << endl;
	}

	while (!same_ends.empty()) {
		pair<string, string> second = same_ends.top();
		same_ends.pop();
		pair<string, string> first = same_ends.top();
		same_ends.pop();

		cout << first.first << " " << second.first << endl << first.second << " " << second.second << endl;
	}	
}


int main() {
	int n; cin >> n;
	set <int> lengths;

	for (int i = 0; i < n; i++) {
		string temp; cin >> temp;
		pair<int, char> temp_pair = read(temp);
		words[temp_pair.first].push_back(make_pair(temp_pair.second, temp));
		lengths.insert(temp_pair.first);
	}

	for (int i : lengths) {
		process(words[i]);
	}
	printAll();
}