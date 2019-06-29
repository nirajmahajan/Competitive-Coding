/*A. Protect Sheep
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Bob is a farmer. He has a large pasture with many sheep. Recently, he has lost some of them due to wolf attacks. He thus decided to place some shepherd dogs in such a way that all his sheep are protected.

The pasture is a rectangle consisting of R × C cells. Each cell is either empty, contains a sheep, a wolf or a dog. Sheep and dogs always stay in place, but wolves can roam freely around the pasture, by repeatedly moving to the left, right, up or down to a neighboring cell. When a wolf enters a cell with a sheep, it consumes it. However, no wolf can enter a cell with a dog.

Initially there are no dogs. Place dogs onto the pasture in such a way that no wolf can reach any sheep, or determine that it is impossible. Note that since you have many dogs, you do not need to minimize their number.

Input
First line contains two integers R (1 ≤ R ≤ 500) and C (1 ≤ C ≤ 500), denoting the number of rows and the numbers of columns respectively.

Each of the following R lines is a string consisting of exactly C characters, representing one row of the pasture. Here, 'S' means a sheep, 'W' a wolf and '.' an empty cell.

Output
If it is impossible to protect all sheep, output a single line with the word "No".

Otherwise, output a line with the word "Yes". Then print R lines, representing the pasture after placing dogs. Again, 'S' means a sheep, 'W' a wolf, 'D' is a dog and '.' an empty space. You are not allowed to move, remove or add a sheep or a wolf.

If there are multiple solutions, you may print any of them. You don't have to minimize the number of dogs.
*/

#include <iostream>
#include <vector>
#include <string>
#include<utility>
using namespace std;

// checks all neighbours if they exist for sheeps
bool checkNeighbours(int r, int c, char elements[501][501], int maxR, int maxC) {
	if (0 == maxR && 0 == maxC) {
		return false;
	} else if (0 == maxR) {
		if (c == 0) {
			return (elements[0][c+1] == 'S');
		} else if (c == maxC) {
			return (elements[0][c-1] == 'S');
		} else {
			return ((elements[0][c+1] == 'S') || (elements[0][c-1] == 'S'));
		}
	} else if (0 == maxC) {
		if (r == 0) {
			return (elements[1][0] == 'S');
		} else if (r == maxR) {
			return (elements[r-1][0] == 'S');
		} else {
			return ((elements[r+1][0] == 'S') || (elements[r-1][0] == 'S'));
		}
	} else if(r==0 && c == 0) {
		return ((elements[0][1] == 'S')||(elements[1][0] == 'S'));
	} else if (r == 0 && c == maxC) {
		return ((elements[0][maxC-1] == 'S')||(elements[1][maxC] == 'S'));
	} else if (r == maxR && c == 0) {
		return ((elements[maxR][1] == 'S')||(elements[maxR-1][0] == 'S'));
	} else if (r == maxR && c == maxC) {
		return ((elements[maxR-1][maxC] == 'S')||(elements[maxR][maxC-1] == 'S'));
	} else if (r == 0) {
		return ((elements[r][c-1] == 'S')||(elements[r][c+1] == 'S') || (elements[r+1][c] == 'S'));
	} else if (r == maxR) {
		return ((elements[r][c-1] == 'S')||(elements[r][c+1] == 'S') || (elements[r-1][c] == 'S'));
	} else if (c == 0){
		return ((elements[r-1][c] == 'S')||(elements[r+1][c] == 'S') || (elements[r][c+1] == 'S'));
	} else if (c == maxC) {
		return ((elements[r-1][c] == 'S')||(elements[r+1][c] == 'S') || (elements[r][c-1] == 'S'));
	} else {
		return ((elements[r-1][c] == 'S')||(elements[r+1][c] == 'S') || (elements[r][c+1] == 'S') || (elements[r][c-1] == 'S'));
	}
}

int main() {
	int r, c;
	scanf("%d", &r);
	scanf("%d", &c);

	vector<pair<int, int> > wolves;
	char elements[501][501];

	// take input
	for (int i = 0; i < r; i++) {
		string row; cin >> row;
		for (int j = 0; j < c; j++) {
			char temp = row[j];
			if (temp == 'W') {
				wolves.push_back(make_pair(i, j));
				elements[i][j] = temp;
			} else {
				elements[i][j] = temp;
			}
		}
	}

	// check if any sheep has adjacent wolf
	for(auto u : wolves) {
		int row = u.first;
		int col = u.second;
		if(checkNeighbours(row, col, elements, r-1, c-1)){
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (elements[i][j] == '.') {
				printf("D");
			} else {
				cout << elements[i][j];
			}
		}
		printf("\n");
	}
}