/*A. Party
time limit per test3 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
A company has n employees numbered from 1 to n. Each employee either has no immediate manager or exactly one immediate manager, who is another employee with a different number. An employee A is said to be the superior of another employee B if at least one of the following is true:

Employee A is the immediate manager of employee B
Employee B has an immediate manager employee C such that employee A is the superior of employee C.
The company will not have a managerial cycle. That is, there will not exist an employee who is the superior of his/her own immediate manager.

Today the company is going to arrange a party. This involves dividing all n employees into several groups: every employee must belong to exactly one group. Furthermore, within any single group, there must not be two employees A and B such that A is the superior of B.

What is the minimum number of groups that must be formed?

Input
The first line contains integer n (1 ≤ n ≤ 2000) — the number of employees.

The next n lines contain the integers pi (1 ≤ pi ≤ n or pi = -1). Every pi denotes the immediate manager for the i-th employee. If pi is -1, that means that the i-th employee does not have an immediate manager.

It is guaranteed, that no employee will be the immediate manager of him/herself (pi ≠ i). Also, there will be no managerial cycles.

Output
Print a single integer denoting the minimum number of groups that will be formed in the party.
*/

#include <iostream>
#include <vector>
using namespace std;

struct Employee {
	vector <Employee *> subEmployees;

	void addSubEmployee(Employee *sub) {
		subEmployees.push_back(sub);
	}
};

int depth(Employee *emp) {
	if (emp->subEmployees.size() == 0) {
		return 1;
	} else {
		int ans = -1;
		for (auto employee : emp->subEmployees) {
			ans = max(ans, depth(employee));
		}
		return ans + 1;
	}
}

int main() {
	int n; cin >> n;

	Employee *employees[n];
	vector<Employee *> bossMan;

	for (int i = 0; i < n; i++) {
		Employee *temp = new Employee;
		employees[i] = temp;
	}

	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		if(temp == -1) {
			bossMan.push_back(employees[i]);
		} else {
			employees[temp-1]->addSubEmployee(employees[i]);	
		}
	}

	int ans = -1;
	for (auto boss : bossMan) {
		ans = max(ans, depth(boss));
	}
	printf("%d\n", ans);
}