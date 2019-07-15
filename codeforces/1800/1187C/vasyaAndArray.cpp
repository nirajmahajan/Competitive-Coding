#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int arr[1001];
bool asc[1002];


bool execute(int l, int r) {
	for (int i = l; i < r; i++) {
		if (asc[i] == false) {
			arr[i] = arr[i+1] + 1;
			return true;
		}
	}
	return false;
}

void record(int l, int r) {
	for (int i = l; i < r; i++) {
		asc[i] = true;
	}
}

int main() {
	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++) {
		arr[i+1] = 1;
	}

	vector<pair<int, int> > descends;

	for (int i = 0; i < m; i++) {
		int t, l, r; cin >> t >> l >> r;
		if (t == 0) {
			descends.push_back(make_pair(l, r));
		} else{
			record(l, r);
		}
	}

	sort(descends.begin(), descends.end());
	reverse(descends.begin(), descends.end());

	for (auto desc : descends) {
		int l = desc.first;
		int r = desc.second;
		bool result = execute(l, r);
		if (!result) {
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	for(int i = 1; i <= n; i++) {
		cout << arr[i]  << " ";
	}
	cout << endl;
}

// 4 3
// 0 1 2
// 0 2 3
// 0 3 4