// TRACE
// returns the maximum trace of a matrix
#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int> > Matrix;

int matrix_length;

int find_trace(Matrix matrix, int length, int i, int j){
	int curr_trace = 0;
	for(int k = 0; k < length; k++){
		curr_trace += matrix[i+k][j+k];
	}
	return curr_trace;
}

int find_max(Matrix matrix){
	int ans = find_trace(matrix, matrix_length, 0, 0);
	for(int i = 1; i < matrix_length; i++){
		ans = max(ans, find_trace(matrix, matrix_length-i, 0, i));
		ans = max(ans, find_trace(matrix, matrix_length-i, i, 0));
	}
	return ans;
}

int main(void){
	int t;
	cin >> t;

	for(int i = 0; i < t; i++){
		// length of a matrix
		// necessarily square
		int length;
		cin >> length;
		matrix_length = length;
		// matrix[row][column]
		Matrix matrix;

		for(int i = 0; i < length; i++){
			matrix.push_back(vector<int> (length));
			for(int j = 0; j < length; j++){
				cin >> matrix[i][j];
			}
		}

		int ans = find_max(matrix);
		cout << ans << endl;
	}
}