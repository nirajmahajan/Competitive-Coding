#include <iostream>
#include <queue>
using namespace std;

#define scf(n) scanf("%d", &n)

int main() {
	int n; scf(n);
	priority_queue<int> input;

	for (int i = 0 ; i < n; i++) {
		int temp; scf(temp);
		input.push(-temp);
	}

	int days = 0;
	while (!input.empty()) {
		if (-input.top() > days) {
			days++;
			input.pop();
		} else {
			input.pop();
		}
	}
	printf("%d\n", days);
}