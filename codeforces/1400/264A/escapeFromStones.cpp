#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

int main() {
	string input;
	cin >> input;

	stack <int> st;
	queue <int> qu;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == 'l'){
			st.push(i+1);
		} else {
			qu.push(i+1);
		}
	}

	while(!qu.empty()) {
		printf("%d\n", qu.front());
		qu.pop();
	}
	while(!st.empty()) {
		printf("%d\n", st.top());
		st.pop();
	}
	printf("\n");
}