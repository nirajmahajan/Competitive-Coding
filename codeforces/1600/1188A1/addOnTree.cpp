#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100005];

int main() {
	int n; cin >> n;

	for (int i = 1; i < n; i++) {
		int a , b; cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (adj[i].size() == 2) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}