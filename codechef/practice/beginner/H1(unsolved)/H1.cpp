// A puzzle game
// returns min number of steps to solve the given puzzle
// return -1 if puzzle cannot be solved
// By Niraj Mahajan, IITB CSE

#include <cmath>
#include <iostream>
using namespace std;

// returns whether a swap is valid
bool is_valid(int array[3][3], int i1, int j1, int i2, int j2){
	int x = array[i1][j1] + array[i2][j2];
	if(x == 2 || x == 3 || x == 5 || x == 7 || x == 11 || x == 13 || x == 17){
		return true;
	}
	else{
		return false;
	}
}
// swaps two elements
void swap(int array[3][3], int i1, int j1, int i2, int j2){
	int temp = array[i1][j1];
	array[i1][j1] = array[i2][j2];
	array[i2][j2] = temp;
}
// returns the number of favourable swaps done in a single iteration over all elements
// the integer num_matches is just for the main body to realize that all the elements are in proper position
int swap_cnt(int array[3][3], int &num_matches){
	int count = 0;
	num_matches = 0;
	int i1, j1;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			i1 = (array[i][j] - 1)/3;
			j1 = (array[i][j] - 1)%3;
			if(i == i1 && j == j1){
				num_matches ++;
			}
			else if(j > j1){
				if(is_valid(array, i, j, i, j-1)){
					swap(array, i, j, i, j-1);
					count ++;
				}
			}
			else if(j < j1){
				if(is_valid(array, i, j, i, j+1)){
					swap(array, i, j, i, j+1);
					count ++;
				}
			}
			else if(i > i1){
				if(is_valid(array, i, j, i-1, j)){
					swap(array, i, j, i-1, j);
					count ++;
				}
			}
			else if(i < i1){
				if(is_valid(array, i, j, i+1, j)){
					swap(array, i, j, i+1, j);
					count ++;
				}
			}
		}
	}
	return count;
}

int main(void){
	int t;
	cin >> t;

	for(int i = 0; i < t; i++){
		int testcases[3][3];
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				cin >> testcases[i][j];
			}
		}

		int ans = 0;
		int cnt;
		int num_matches = 0;
		do{
			cnt = swap_cnt(testcases, num_matches);
			ans+= cnt;
		}
		while(cnt != 0);

		if(num_matches == 9){
			cout << ans << endl;
		}
		else{
			cout << "-1\n";
		}
	}
}