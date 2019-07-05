#include <iostream>
#include <set>
#include <string>
using namespace std;

#define scf(n) scanf("%d", &n);
#define ptf(n) printf("%d\n", n);

int main() {
	int n, m; scf(n); scf(m);
	set<string> pol;
	set<string> enemy;
	set<string> common;

	for (int i = 0; i < n; i++) {
		string temp; cin >> temp;
		pol.insert(temp);
	}
	for (int i = 0; i < m; i++) {
		string temp; cin >> temp;
		enemy.insert(temp);
		if (pol.count(temp) == 1) {
			common.insert(temp);
		}
	}

	int pol_size = n;
	int en_size = m;
	int common_size = common.size();

	if (common_size % 2 == 1) {
		en_size -= 1;
	}

	if (pol_size > en_size) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}