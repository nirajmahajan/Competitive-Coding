#include <iostream>
#include <map>
#include <string>
using namespace std;

typedef map<string, int> List;

int to_type(string s){
	int ans = 0;
	bool left = false, right = false;
	for(int i = 0; i < s.length() ; i++){
		if(s[i] == 'd' || s[i] == 'f'){
			if(left == true){
				ans += 4;
			}
			else{
				ans+= 2;
			}
			left = true;
			right = false;
		}
		else{
			if(right == true){
				ans += 4;
			}
			else{
				ans+= 2;
			}
			left = false;
			right = true;
		}
	}
	return ans;
}

int main(void){
	int t;
	cin >> t;


	string input;
	for(int j = 0; j < t; j++){
			List l1;
		int word;
		int ans = 0;
		cin >> word;
		for(int i = 0; i < word; i++){
			cin >> input;
			if(l1.find(input) != l1.end()){
				ans += (l1[input] / 2);
			}
			else{
				int time = to_type(input);
				ans += time;
				l1[input] = time;
			}
		}
		cout << ans<< endl;
	}
}