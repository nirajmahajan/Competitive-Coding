/*C. PolandBall and Forest
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
PolandBall lives in a forest with his family. There are some trees in the forest. Trees are undirected acyclic graphs with k vertices and k - 1 edges, where k is some integer. Note that one vertex is a valid tree.

There is exactly one relative living in each vertex of each tree, they have unique ids from 1 to n. For each Ball i we know the id of its most distant relative living on the same tree. If there are several such vertices, we only know the value of the one with smallest id among those.

How many trees are there in the forest?

Input
The first line contains single integer n (1 ≤ n ≤ 104) — the number of Balls living in the forest.

The second line contains a sequence p1, p2, ..., pn of length n, where (1 ≤ pi ≤ n) holds and pi denotes the most distant from Ball i relative living on the same tree. If there are several most distant relatives living on the same tree, pi is the id of one with the smallest id.

It's guaranteed that the sequence p corresponds to some valid forest.

Hacking: To hack someone, you should provide a correct forest as a test. The sequence p will be calculated according to the forest and given to the solution you try to hack as input. Use the following format:

In the first line, output the integer n (1 ≤ n ≤ 104) — the number of Balls and the integer m (0 ≤ m < n) — the total number of edges in the forest. Then m lines should follow. The i-th of them should contain two integers ai and bi and represent an edge between vertices in which relatives ai and bi live. For example, the first sample is written as follows:


5 3
1 2
3 4
4 5
Output
You should output the number of trees in the forest where PolandBall lives.

Interaction
From the technical side, this problem is interactive. However, it should not affect you (except hacking) since there is no interaction.

*/

#include <iostream>
#include <set>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	int single_node_trees = 0;
	set <int> ends;
	for (int i = 1; i <= n; i++) {
		int temp; scanf("%d", &temp);
		if (temp == i) {
			single_node_trees++;
		} else {
			ends.insert(temp);
		}
	}

	printf("%d\n", (int)(single_node_trees + (ends.size()/2)));
}