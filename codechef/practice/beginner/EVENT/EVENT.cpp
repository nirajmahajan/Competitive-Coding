// EVENT
// By Niraj Mahajan, IITB CSE
#include <iostream>
#include <map>
#include <string>
using namespace std;

void learn(map <string, int> &Day){
	Day["sunday"] = 0;
	Day["monday"] = 1;
	Day["tuesday"] = 2;
	Day["wednesday"] = 3;
	Day["thursday"] = 4;
	Day["friday"] = 5;
	Day["saturday"] = 6;
}

int check(int & ans_val, const string &day1,const string &day2, const int &l, const int &r, map <string, int> &Day){
	int ans = 0;
	int diff1 = Day[day2] - Day[day1];
	if(diff1 < 0){
		diff1 += 7;
	}
	diff1++;
	while(true){
		if(diff1 > r){
			return ans;
		}
		else if(diff1 >= l && diff1 <= r){
			ans_val = diff1;
			ans++;
			diff1 += 7;
		}
		else{
			diff1 += 7;
		}
	}
}

int main(void){
	// map to remember the values of days
	map<string, int> Day;
	// learn the values of days
	learn(Day);

	int num_test;
	cin >> num_test;

	for(int i = 0; i < num_test; i++){
		string day1, day2;
		cin >> day1 >> day2;

		int l, r;
		cin >> l >> r;

		int ans_val;
		int ans = check(ans_val, day1, day2, l, r, Day);

		if(ans == 0){
			cout << "impossible\n";
		}
		else if (ans == 1){
			cout << ans_val << endl;
		}
		else{
			cout << "many\n";
		}
	}
}