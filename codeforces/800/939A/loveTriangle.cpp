/*A. Love Triangle
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
As you could know there are no male planes nor female planes. However, each plane on Earth likes some other plane. There are n planes on Earth, numbered from 1 to n, and the plane with number i likes the plane with number fi, where 1 ≤ fi ≤ n and fi ≠ i.

We call a love triangle a situation in which plane A likes plane B, plane B likes plane C and plane C likes plane A. Find out if there is any love triangle on Earth.

Input
The first line contains a single integer n (2 ≤ n ≤ 5000) — the number of planes.

The second line contains n integers f1, f2, ..., fn (1 ≤ fi ≤ n, fi ≠ i), meaning that the i-th plane likes the fi-th.

Output
Output «YES» if there is a love triangle consisting of planes on Earth. Otherwise, output «NO».

You can output any letter in lower case or in upper case.
*/

#include <iostream>
#include <vector>

using namespace std;

int loves(vector<int> v[], int i) {
	if (i == 0) {
		return -1;
	} else if (v[i].size() == 0) {
		return -1;
	} else {
		return v[i].at(0);
	}
}

int main(void){
	int n;
	scanf("%d", &n);
	// cin >> n;
	vector<int> adj[n+1];
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		// cin >> temp;
		adj[i+1].push_back(temp);
	}
	bool violation = false;

	for (int i = 1; i <= n; i++) {
		if (loves(adj, loves(adj, loves(adj, i))) == i) {
			violation = true;
			break;
		}
	}

	if(violation) {
		printf("%s\n", "YES");
	} else {
		printf("%s\n", "NO");
	}
}
