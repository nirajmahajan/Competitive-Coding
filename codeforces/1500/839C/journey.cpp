#include <iostream>
#include <vector>
using namespace std;

#define ptf(n) printf("%d\n", n)
#define ptfd(n) printf("%.15f\n", n)
#define scf(n) scanf("%d", &n)
#define pb(n) push_back(n)

// double count = 0;
// double total_distance = 0;
vector<int> adj[100001];

double dfs(bool visited[], int curr_city) {
	visited[curr_city] = true;
	int options = 0;
	double ans = 0;
	for (auto neighbour : adj[curr_city]){
		if (!visited[neighbour]) {
			options++;
			ans += 1 + dfs(visited, neighbour);
			visited[neighbour] = false;
		}
	}
	if (options == 0) {return 0;}
	ans = ans / options;
	return ans;
}

int main() {
	int n; scf(n);

	for (int i = 1; i < n; i++) {
		int a, b;
		scf(a); scf(b);

		adj[a].pb(b);
		adj[b].pb(a);
	}

	bool visited[n+1] = {false};
	
	double ans = dfs(visited, 1);

	ptfd(ans);
}
