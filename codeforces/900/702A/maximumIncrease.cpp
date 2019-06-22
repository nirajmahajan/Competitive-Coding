/*A. Maximum Increase
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given array consisting of n integers. Your task is to find the maximum length of an increasing subarray of the given array.

A subarray is the sequence of consecutive elements of the array. Subarray is called increasing if each element of this subarray strictly greater than previous.

Input
The first line contains single positive integer n (1 ≤ n ≤ 10^5) — the number of integers.

The second line contains n positive integers a1, a2, ..., an (1 ≤ ai ≤ 10^9).

Output
Print the maximum length of an increasing subarray of the given array.
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

		if (temp > prev) {
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