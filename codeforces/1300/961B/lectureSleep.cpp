#include <iostream>
using namespace std;

#define scf(n) scanf("%d", &n)
#define ptf(n) printf("%d\n", n)

int main (){

	int n,k; scf(n); scf(k);
	int theorem[n];
	bool awake[n];

	for (int i = 0; i < n; i++) {scf(theorem[i]);}
	for (int i = 0; i < n; i++) {cin >> awake[i];}

	int sum = 0;
	int max_bonus = 0;

	for (int i = 0; i < n; i++) {
		if (awake[i]) {
			sum += theorem[i];
			theorem[i] = 0;
		}
	}
	int total_sum = sum;

	sum = 0;
	for (int i = 0; i < k; i++) {
		sum += theorem[i];
	}

	int j = k;
	int start = 0;
	max_bonus = sum;
	while (j != n) {
		sum = sum - theorem[start]+ theorem[j];
		max_bonus = max(sum, max_bonus);
		start++;
		j++;
	}

	cout << max_bonus + total_sum << endl;
}