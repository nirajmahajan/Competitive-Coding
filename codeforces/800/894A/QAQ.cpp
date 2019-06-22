/*"QAQ" is a word to denote an expression of crying. Imagine "Q" as eyes with tears and "A" as a mouth.

Now Diamond has given Bort a string consisting of only uppercase English letters of length n. There is a great number of "QAQ" in the string (Diamond is so cute!).

Bort wants to know how many subsequences "QAQ" are in the string Diamond has given. Note that the letters "QAQ" don't have to be consecutive, but the order of letters should be exact.

Input
The only line contains a string of length n (1 ≤ n ≤ 100). It's guaranteed that the string only contains uppercase English letters.

Output
Print a single integer — the number of subsequences "QAQ" in the string.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin >> str;
	int ans = 0;

	for (int i = 0; i < str.length(); i++) {
		if(str[i] == 'Q') {
			for (int j = i+1; j < str.length(); j++){
				if(str[j] == 'A') {
					for(int k = j+1; k < str.length(); k++) {
						if(str[k] == 'Q'){
							ans++;
						}
					}
				}
			}
		}
	}

	printf("%d\n", ans);
}