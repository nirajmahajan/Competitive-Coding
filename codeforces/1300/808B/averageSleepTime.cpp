#include <iostream>
using namespace std;

#define scf(n) scanf("%d", &n)
#define ptf(n) printf("%d\n", n)

int main (){
	int n,k; scf(n); scf(k);
	int nums[n];
	int start = 0;
	int end = k;
	double total_sum = 0;
	double sum = 0;

	// initialize sum
	for (int i = 0; i < k; i++) {
		int temp; scf(temp);
		nums[i] = temp;
		sum += temp;
	}
	total_sum += sum;
	for (int i = k; i < n; i++) {
		if (end == n) {
			break;
		}
		int temp; scf(temp);
		nums[i] = temp;
		sum = sum - nums[start] + nums[end];
		total_sum += sum;
		start ++;
		end++;
	}

	printf("%.6f\n", total_sum/(n-k+1));
}