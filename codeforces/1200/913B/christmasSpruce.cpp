/*B. Christmas Spruce
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Consider a rooted tree. A rooted tree has one special vertex called the root. All edges are directed from the root. Vertex u is called a child of vertex v and vertex v is called a parent of vertex u if there exists a directed edge from v to u. A vertex is called a leaf if it doesn't have children and has a parent.

Let's call a rooted tree a spruce if its every non-leaf vertex has at least 3 leaf children. You are given a rooted tree, check whether it's a spruce.

The definition of a rooted tree can be found here.

Input
The first line contains one integer n — the number of vertices in the tree (3 ≤ n ≤ 1 000). Each of the next n - 1 lines contains one integer pi (1 ≤ i ≤ n - 1) — the index of the parent of the i + 1-th vertex (1 ≤ pi ≤ i).

Vertex 1 is the root. It's guaranteed that the root has at least 2 children.

Output
Print "Yes" if the tree is a spruce and "No" otherwise.
*/

#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int id;
	vector <Node *> children;

	Node(int new_id) {
		id = new_id;
	}

	void addChild(Node * child) {
		children.push_back(child);
	}
	bool isSpruce() {
		if (children.size() == 0) {
			return true;
		}
		int leafCount = 0;
		for(auto child : children) {
			if (child->children.size() == 0) {
				leafCount++;
			}
		}
		return (leafCount >= 3);
	}
};

int main(){
	int n;
	cin >> n;
	Node *nodes[n+1];
	Node temp = Node(1);
	nodes[1] = &temp;
	for (int i = 2; i <= n; i++) {
		int temp; cin >> temp;
		Node *node_temp = new Node(i);
		nodes[i] = node_temp;
		nodes[temp]->addChild(nodes[i]);
	}

	for (int i = 1; i <= n; i++) {
		Node *node = nodes[i];
		if (node->isSpruce() == false) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
}