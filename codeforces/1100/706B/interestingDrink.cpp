/*B. Interesting drink
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vasiliy likes to rest after a hard work, so you may often meet him in some bar nearby. As all programmers do, he loves the famous drink "Beecola", which can be bought in n different shops in the city. It's known that the price of one bottle in the shop i is equal to xi coins.

Vasiliy plans to buy his favorite drink for q consecutive days. He knows, that on the i-th day he will be able to spent mi coins. Now, for each of the days he want to know in how many different shops he can buy a bottle of "Beecola".

Input
The first line of the input contains a single integer n (1 ≤ n ≤ 100 000) — the number of shops in the city that sell Vasiliy's favourite drink.

The second line contains n integers xi (1 ≤ xi ≤ 100 000) — prices of the bottles of the drink in the i-th shop.

The third line contains a single integer q (1 ≤ q ≤ 100 000) — the number of days Vasiliy plans to buy the drink.

Then follow q lines each containing one integer mi (1 ≤ mi ≤ 109) — the number of coins Vasiliy can spent on the i-th day.

Output
Print q integers. The i-th of them should be equal to the number of shops where Vasiliy will be able to buy a bottle of the drink on the i-th day.
*/

#include <iostream>
#include <algorithm>
using namespace std;

// returns the number of elements less than or equal to target
int search(int arr[], int begin, int end, int target) {
	// single element
	if (begin == end) {
		if(arr[begin] > target) {
			return begin-1;
		} else {
			return begin;
		}
	} else if (end - begin == 1) {
		if(arr[end] > target && arr[begin] > target) {
			return begin-1;
		} else if (arr[end] > target) {
			return begin;
		} else {
			return end;
		}
	} else {
		int mid = (begin + end)/2;
		if (arr[mid] > target) {
			return search(arr, begin, mid, target);
		} else {
			return search(arr, mid, end, target);
		}
	}
}

int main() {
	int n; cin >> n;
	int costs[n];
	for(int i = 0; i < n; i++){
		cin >> costs[i];
	}
	sort(costs, costs+n);
	int q; cin >> q;
	int allowance[q];
	int max = costs[n-1];
	// for(int j = 0; j < q; j++){
	// 	cin >> allowance[j];
	// }
	for(int j = 0; j < q; j++){
		int temp; cin >> temp;
		if (temp >= max) {
			printf("%d\n", n);
		}
		else {
			printf("%d\n", 1+search(costs, 0, n-1, temp));
		}
	}
}