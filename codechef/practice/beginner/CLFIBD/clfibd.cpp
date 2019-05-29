// Fibonacci string
// By Niraj Mahajan, IITB CSE
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef map <char, int> List;

void update(List &l1, char c1){
	List::iterator li = l1.find(c1);
	if(li == l1.end()){
		l1[c1] = 1;
	}
	else{
		l1[c1] ++;
	}
}

// PC list is sorted
bool is_dynamic(List &l1){
	if(l1.size() <= 2){
		return true;
	}
	int freq[l1.size()];
	List::iterator li = l1.begin();
	for(int i = 0; i< l1.size(); i++){
		freq[i] = li->second;
		li++;
	}
	sort(freq, freq+l1.size());

	if(freq[3] != freq[2] + freq[1] && freq[3] != freq[2] + freq[0]){
		return false;
	}

	for(int j = 2; j < l1.size() - 2; j++){
		if(freq[j+2] != (freq[j] + freq[j+1])){
			return false;
		}
	}
	return true;
}

int main(void){
	int t;
	cin >> t;

	string data;
	for(int i = 0; i < t; i++){
		List l1;
		cin >> data;
		for(int j = 0; j < data.length(); j++){
			update(l1, data[j]);
		}
		if(is_dynamic(l1)){
			cout << "Dynamic\n";
		}
		else{
			cout << "Not\n";
		}
	}
}