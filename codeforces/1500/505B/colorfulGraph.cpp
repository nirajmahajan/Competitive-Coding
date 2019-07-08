#include <iostream>
#include <vector>
using namespace std;

#define ptf(n) printf("%d\n", n)
#define ptfd(n) printf("%.15f\n", n)
#define scf(n) scanf("%d", &n)
#define pb(n) push_back(n)

// double count = 0;
// double total_distance = 0;
vector<pair<int, int> > adj[101];

int dfs(bool visited[], int curr_city, int color, int target_city) {
	if (curr_city == target_city) {
		return 1;
	}
	visited[curr_city] = true;
	int ans = 0;
	for (auto neighbour_node : adj[curr_city]){
		int neighbour_color = neighbour_node.second;
		int neighbour = neighbour_node.first;
		if (!visited[neighbour] && neighbour_color == color) {
			int output = dfs(visited, neighbour, color, target_city);
			if (output == 1) {return 1;}
			visited[neighbour] = false;
		}
	}
	return ans;
}

int main() {
	int n; scf(n);
	int m; scf(m);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		scf(a); scf(b); scf(c);

		adj[a].pb(make_pair(b, c));
		adj[b].pb(make_pair(a, c));
	}

	int test_cases; scf(test_cases);

	for (int i = 0; i < test_cases; i ++) {
		bool colorTaken[m+1] = {false};
		int a, b; scf(a); scf(b);
		int ans = 0;
		for (auto node_pair : adj[a]) {
			int node = node_pair.first;
			int color = node_pair.second;
			bool visited[101] = {false};
			visited[a] = true;
			int temp_ans = dfs(visited, node, color, b); 
			if (!colorTaken[color] && temp_ans == 1) {
				colorTaken[color] = true;
				ans += temp_ans;
			}
		}
		ptf(ans);
	}
}
