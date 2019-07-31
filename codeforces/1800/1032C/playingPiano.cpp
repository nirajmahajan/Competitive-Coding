#include <iostream>
#include <string>
using namespace std;

int canPlay[100001][6];
int arr[100001];

int specInc(int a){
	if (a+1 == 6) {
		a = 1;
	}
	else {
		a = a + 1;
	}
	return a;
}

int main() {
	int n;
	cin >> n;	

	int prev = 0;



	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


	for (int i = 0; i < n; i++) {
		if (i == 0) {
			canPlay[0][5] = -2;
			canPlay[0][1] = -2;
			canPlay[0][2] = -2;
			canPlay[0][3] = -2;
			canPlay[0][4] = -2;
			continue;
		}
		for (int k = 1; k < 6; k++) {
			for (int j = 1; j < 6; j++){
				if (canPlay[i-1][j] == -1) {
					continue;
				}
				if ((arr[i-1] == arr[i] && j != k) || (arr[i-1] < arr[i] && j < k) || (arr[i-1] > arr[i] && j > k)) {
					canPlay[i][k] = j;
				}
			}
			if (canPlay[i][k] == 0) {
				canPlay[i][k] = -1;
				// cout << "cutting for "<< i+1 << k << endl;
			}
		}
	}


	for (int i = 1; i < 6; i++){
		// for (int j = 0; j < n; j++) {
		// 	if (canPlay[j][i] < 0) {
		// 		cout << canPlay[j][i] << " ";
		// 	} else {
		// 		cout << canPlay[j][i] << "  ";
		// 	}
		// }
		// cout << endl;
		string ans = "";
		if (canPlay[n-1][i] == -1) {
			continue;
		}

		int pos = n-1;
		int val = i;
		ans += to_string(i);
		while(true) {
			if (canPlay[pos][val] == -2){
				cout << ans << endl;
				return 0;
			} else {
				ans = to_string(canPlay[pos][val]) + " " + ans;
				val = canPlay[pos][val];
				pos--;
			}
		}
	}

	cout << "-1" << endl;
}