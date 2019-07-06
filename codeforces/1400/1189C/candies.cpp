#include <iostream>
using namespace std;

#define scf(n) scanf("%d", &n)
#define ptf(n) printf("%d\n", n)

int main() {
	int n; scf(n);
	int prefSum[n+1];
	prefSum[0] = 0;

	for (int i = 1; i <= n; i++) {
		int temp; scf(temp);
		prefSum[i] = temp + prefSum[i-1];	
	}

	int queries; scf(queries);
	for(int i = 0; i < queries; i++) {
		int a, b; scf(a); scf(b);
		ptf((prefSum[b] - prefSum[a-1])/10);
	}
}