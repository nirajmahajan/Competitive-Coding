#include <iostream>
#include <string>
using namespace std;

int main () {
	int n; cin >> n;
	string input; cin >> input;

	if (n%2 != 0) {
		printf("1\n");
	 	cout << input << endl;
		return 0;
	}
	int ones = 0, zeros = 0;
	for (int i = 0; i < n; i++) {
		if (input[i] == '0') {
			zeros++;
		} else {
			ones++;
		}
	}

	if (ones != zeros) {
	 	printf("1\n");
	 	cout << input << endl;
		return 0;
	} else {
		printf("2\n");
		cout << input[0] << " " <<  input.substr(1) << endl;
	}
}