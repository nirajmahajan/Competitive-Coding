/*A. Kefa and First Steps
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Kefa decided to make some money doing business on the Internet for exactly n days. He knows that on the i-th day (1 ≤ i ≤ n) he makes ai money. Kefa loves progress, that's why he wants to know the length of the maximum non-decreasing subsegment in sequence ai. Let us remind you that the subsegment of the sequence is its continuous fragment. A subsegment of numbers is called non-decreasing if all numbers in it follow in the non-decreasing order.

Help Kefa cope with this task!
*/

#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n; cin >> n;
	int arr[n];
	
	int ans = 0;
	int streak = 0;
	int prev = INT_MIN;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;

		if (temp >= prev) {
			streak++;
			prev = temp;
		}
		else {
			ans = max(streak, ans);
			streak = 1;
			prev = temp;
		}
	}
	ans = max(streak, ans);
	printf("%d\n", ans);
}