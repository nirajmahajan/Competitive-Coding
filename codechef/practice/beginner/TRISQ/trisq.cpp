//Fit Squares in Triangle
// By Niraj Mahajan, IITB CSE

#include <iostream>
using namespace std;

int trian(int side_len){
	if(side_len <= 3){
		return 0;
	}
	else{
		return (trian(side_len-2) + ((side_len-2)/2));
	}
}

int main(void){
	int num_test; cin >> num_test;
	for(int i = 0; i < num_test; i++){
		int side_len;
		cin >> side_len;
		cout << trian(side_len) << endl;
	}
}