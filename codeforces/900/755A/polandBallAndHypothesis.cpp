/*A. PolandBall and Hypothesis
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
PolandBall is a young, clever Ball. He is interested in prime numbers. He has stated a following hypothesis: "There exists such a positive integer n that for each positive integer m number n·m + 1 is a prime number".

Unfortunately, PolandBall is not experienced yet and doesn't know that his hypothesis is incorrect. Could you prove it wrong? Write a program that finds a counterexample for any n.

Input
The only number in the input is n (1 ≤ n ≤ 1000) — number from the PolandBall's hypothesis.

Output
Output such m that n·m + 1 is not a prime number. Your answer will be considered correct if you output any suitable m such that 1 ≤ m ≤ 103. It is guaranteed the the answer exists.
*/

#include <iostream>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	if (n == 1) {
		printf("3\n");
	} else if (n == 2) {
		printf("4\n");
	} else {
		printf("%d\n", n-2);
	}
}