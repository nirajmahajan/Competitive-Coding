// Is it a cakewalk
// By Niraj Mahajan, IITB, CSE
#include <iostream>
using namespace std;

bool check(void){
	// number of people checked that have time less than 30
	int less_than = 0;
	bool ans = false;
	int temp;
	for(int j = 0; j < 100; j++){
		cin >> temp;
		if(temp <= 30){
			less_than ++;
		}
		if(less_than == 60){
			ans = true;
		}
	}
	return ans;
}

int main(void){
	int num_test;
	cin >> num_test;

	for(int i = num_test; i > 0; i--){
		bool temp = check();
		if (temp == true){
			cout << "yes\n";
		}	
		else{
			cout << "no\n";
		}
	}
}