/*B. Mahmoud and Ehab and the bipartiteness
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Mahmoud and Ehab continue their adventures! As everybody in the evil land knows, Dr. Evil likes bipartite graphs, especially trees.

A tree is a connected acyclic graph. A bipartite graph is a graph, whose vertices can be partitioned into 2 sets in such a way, that for each edge (u, v) that belongs to the graph, u and v belong to different sets. You can find more formal definitions of a tree and a bipartite graph in the notes section below.

Dr. Evil gave Mahmoud and Ehab a tree consisting of n nodes and asked them to add edges to it in such a way, that the graph is still bipartite. Besides, after adding these edges the graph should be simple (doesn't contain loops or multiple edges). What is the maximum number of edges they can add?

A loop is an edge, which connects a node with itself. Graph doesn't contain multiple edges when for each pair of nodes there is no more than one edge between them. A cycle and a loop aren't the same .

Input
The first line of input contains an integer n — the number of nodes in the tree (1 ≤ n ≤ 105).

The next n - 1 lines contain integers u and v (1 ≤ u, v ≤ n, u ≠ v) — the description of the edges of the tree.

It's guaranteed that the given graph is a tree.

Output
Output one integer — the maximum number of edges that Mahmoud and Ehab can add to the tree while fulfilling the conditions.
*/

#include <iostream>
#include <queue>
#include <set>
using namespace std;

vector<int> edges[100001];
bool processed[100001];
set <int> alpha, beta;

void allocate(int j) {
	if  (processed[j]) {
		return;
	}

	processed[j] = true;

	if (alpha.count(j) == 1) {
		for (auto node : edges[j]) {
			beta.insert(node);
			allocate(node);
		}
	} else {
		for (auto node : edges[j]) {
			alpha.insert(node);
			allocate(node);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	alpha.insert(1);
	
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	allocate(1);

	long long beta_size = beta.size();
	long long alpha_size = alpha.size();
	long long ans = (beta_size * alpha_size) - n + 1;
	cout << ans << endl;
}