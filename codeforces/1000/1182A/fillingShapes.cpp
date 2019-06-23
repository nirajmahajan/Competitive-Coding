/*A. Filling Shapes
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You have a given integer n. Find the number of ways to fill all 3×n tiles with the shape described in the picture below. Upon filling, no empty spaces are allowed. Shapes cannot overlap.

This picture describes when n=4. The left one is the shape and the right one is 3×n tiles.
Input
The only line contains one integer n (1≤n≤60) — the length.

Output
Print the number of ways to fill.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	if ((n%2) != 0){
		printf("0\n");
		return 0;
	}

	printf("%d\n", (int)pow(2, n/2));
}