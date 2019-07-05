/*C. Petya and Catacombs
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A very brave explorer Petya once decided to explore Paris catacombs. Since Petya is not really experienced, his exploration is just walking through the catacombs.

Catacombs consist of several rooms and bidirectional passages between some pairs of them. Some passages can connect a room to itself and since the passages are built on different depths they do not intersect each other. Every minute Petya arbitrary chooses a passage from the room he is currently in and then reaches the room on the other end of the passage in exactly one minute. When he enters a room at minute i, he makes a note in his logbook with number ti:

If Petya has visited this room before, he writes down the minute he was in this room last time;
Otherwise, Petya writes down an arbitrary non-negative integer strictly less than current minute i.
Initially, Petya was in one of the rooms at minute 0, he didn't write down number t0.

At some point during his wandering Petya got tired, threw out his logbook and went home. Vasya found his logbook and now he is curious: what is the minimum possible number of rooms in Paris catacombs according to Petya's logbook?

Input
The first line contains a single integer n (1 ≤ n ≤ 2·105) — then number of notes in Petya's logbook.

The second line contains n non-negative integers t1, t2, ..., tn (0 ≤ ti < i) — notes in the logbook.

Output
In the only line print a single integer — the minimum possible number of rooms in Paris catacombs.
*/

#include <iostream>
#include <set>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	set <int> times;
	times.insert(0);
	for (int i = 1; i <= n; i++) {
		int temp; scanf("%d", &temp);
		if (times.count(temp) == 1) {
			times.erase(temp);
			times.insert(i);
		} else {
			times.insert(i);
		}
	}
	printf("%d\n", (int) times.size());
}