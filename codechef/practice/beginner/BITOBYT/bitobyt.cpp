// Bit to Byte
// returns number of nits, bytes and nibbles after a given time intervals
// By Niraj Mahajan, IITB, CSE
#include <iostream>
#include <cmath>
using namespace std;

int main(void){
	int t;
	cin >> t;

	for(int i = 0; i < t; i++){
		int time;
		cin >> time;
		// things represents the totalnumber of bits, bytes, nibbles
		long long things;
		// Consider an interval of 26 seconds, eg for time 0-26, it is zeroeth interval
		// for the ith interval, the number of things is 2^i
		// interval = time/26  (integer division)
		int rem_time;
		// the time passed ahead of the most recent '26 second interval' is given by rem_time

		things = pow(2, (time-1)/26);
		rem_time = (time-1) % 26;

		if(rem_time < 2){
			// everythings is in bits
			cout << things << " 0 0\n";
		}
		else if(rem_time < 10){
			// everything is in nibbles
			cout << "0 " << things << " 0\n";
		}
		else{
			// everything is in bytes
			cout << "0 0 " << things << endl;
		}
	}
}