#include <algorithm>
#include <iostream>
using namespace std;

pair<int, int> arr[1000002];

bool check_ap(int l, int r) {
	if (l == r) {
		return true;
	}

	int val = arr[l+1].first - arr[l].first;

	for (int i = l; i < r; i++) {
		if (val != arr[i+1].first - arr[i].first) {
			return false;
		}
	}
	return true;
}

int main() {
	int n; cin >> n;

	if (n <= 3) {
		printf("1\n");
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		arr[i] = make_pair(temp,i);
	}

	sort(arr+1, arr+n+1);

	if (check_ap(2, n)) {
		cout << arr[1].second << endl;
		return 0;
	} else if (check_ap(3, n) && (arr[3].first - arr[4].first) == (arr[1].first - arr[3].first)) {
		cout << arr[2].second << endl;
		return 0;
	}

	int val = arr[2].first - arr[1].first;
	int ans = -3;
	for (int i = 2; i < n; i++) {
		if (val != arr[i+1].first - arr[i].first) {
			if (ans != -3) {
				if (ans == arr[i].second && arr[i+1].first - arr[i-1].first == val) {
					continue;
				}
				printf("-1\n");
				return 0;
			} else {
				if ((i == n-1) || (arr[i+2].first-arr[i].first == val)) {
					ans = arr[i+1].second;
				} else {
					printf("-1\n");
					return 0;
				}
			}
		}
	}
	printf("%d\n", ans);
}