#include <iostream>
#include <queue>
using namespace std;

int max_time;
int n;

int orig[1000002];
priority_queue<int> done_times;
priority_queue<int> failed_times;

int main() {
	cin >> n >> max_time;

	for (int i = 1; i <= n; i++) {
		cin >> orig[i];
	}

	int curr_time = 0;
	int ans = 0;

	// LI : when the ith loop start, done_times has the most optimum 
	//		students passed, till the ith student
	for (int i = 1; i <= n; i++) {
		int new_time = curr_time + orig[i];
		while(new_time > max_time) {
			new_time -= done_times.top();
			curr_time -= done_times.top();
			failed_times.push(-done_times.top());
			done_times.pop();
			ans++;
		}
		printf("%d ", ans);

		failed_times.push(-orig[i]);
		ans++;

		while(!failed_times.empty()) {
			int next_min = -failed_times.top();
			if (curr_time + next_min > max_time) {
				break;
			} else {
				curr_time += next_min;
				ans--;
				done_times.push(next_min);
				failed_times.pop();
			}
		}
	}
	printf("\n");
}