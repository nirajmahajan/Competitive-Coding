#include <iostream>
#include <cmath>
using namespace std;

bool isInt(float a) {
	return a == round(a);
}

int main() {
	int n;
	cin >> n;

	float input[n];
	int modify[n];

	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	int net = 0;

	for (int i = 0; i < n; i++) {
		modify[i] = floor(input[i]);
		net+= modify[i];
	}

	if (net == 0) {
		for (int i = 0; i < n; i++) {
			cout << modify[i] << endl;
		}
		return 0;
	} else {
		int i = 0;
		while (net != 0) {
			if (!isInt(input[i])) {
				modify[i]++;
				net++;
			}
			i++;
		}
		for (int i = 0; i < n; i++) {
			cout << modify[i] << endl;
		}
	}

}