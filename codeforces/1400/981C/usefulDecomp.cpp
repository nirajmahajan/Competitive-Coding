#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100001];

int endAlongAwayFrom(int along, int awayFrom) {
	if (adj[along].size() == 1) {
		return along;
	}

	int new_along;
	if (adj[along].at(0) == awayFrom) {
		new_along = adj[along].at(1);
	} else {
		new_along = adj[along].at(0);
	}

	endAlongAwayFrom(new_along, along);
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i < n; i++) {
		int a, b; scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int origin = -1;
	int tent_a = -1;
	int tent_b = -1;

	for (int i = 1; i <= n; i++) {
		if (adj[i].size() == 1) {
			if (tent_a == -1) {
				tent_a = i;
			} else {
				tent_b = i;
			}
		}

		if (adj[i].size() >= 3) {
			if (origin != -1) {
				printf("No\n");
				return 0;
			} else {
				origin = i;
			}
		}
	}

	printf("Yes\n");

	if (origin == -1) {
		printf("1\n%d %d\n", tent_a, tent_b);
		return 0;
	}


	printf("%d\n", (int)adj[origin].size());
	for(auto node : adj[origin]) {
		printf("%d %d\n", origin, endAlongAwayFrom(node, origin));
	}
}