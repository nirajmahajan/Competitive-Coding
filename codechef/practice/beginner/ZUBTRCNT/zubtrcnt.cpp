//D Triangle Count
// returns the number of equilateral triangles of a given length that are subset of given triangle
// By Niraj Mahajan, IITB, CSE
#include <iostream>
using namespace std;

int main(void){
	int t;
	cin >> t;

	for(int i = 0; i < t; i++){
		int length, sub_len;
		cin >> length >> sub_len;
		int ans = (length - sub_len + 1)*(length - sub_len + 2)/2 ;
		if(sub_len > length){
			ans = 0;
		}
		cout << "Case " << i+1 << ":  " << ans << endl;
	}
}