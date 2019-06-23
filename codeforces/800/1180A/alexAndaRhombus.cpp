/*A. Alex and a Rhombus
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
While playing with geometric figures Alex has accidentally invented a concept of a n-th order rhombus in a cell grid.

A 1-st order rhombus is just a square 1×1 (i.e just a cell).

A n-th order rhombus for all n≥2 one obtains from a n−1-th order rhombus adding all cells which have a common side with it to it (look at the picture to understand it better).


Alex asks you to compute the number of cells in a n-th order rhombus.

Input
The first and only input line contains integer n (1≤n≤100) — order of a rhombus whose numbers of cells should be computed.

Output
Print exactly one integer — the number of cells in a n-th order rhombus.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	printf("%d\n", ((2*n*n)-(2*n)+1));
}