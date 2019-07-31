#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<int> neighbours[100001];
vector<int> goodInWhichCities[100001];
bool visited[100001];
int dist[101][100001];
// dist[good][city]

int distRecord(int good) {
	queue<int> Q;

	for (int i = 0; i < 100001; i++) {
		dist[good][i] = 10000000;
		visited[i] = false;
	}

	for (auto city : goodInWhichCities[good]) {
		Q.push(city);
		dist[good][city] = 0;
	}

	while(!Q.empty()) {
		int city = Q.front(); Q.pop();
		if (visited[city]) {
			continue;
		}
		visited[city] = true;

		for (auto nei : neighbours[city]) {
			Q.push(nei);
			if (dist[good][nei] > dist[good][city]+1){
				dist[good][nei] = dist[good][city]+1;
			}
		}
	}
}

int main() {
	int n, m, k, s;
	cin >> n >> m >> k >> s;

	set<int> goodList;

	for (int i = 1; i <= n; i++) {
		int goodName; cin >> goodName;
		goodList.insert(goodName);
		goodInWhichCities[goodName].push_back(i);
	}

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		neighbours[a].push_back(b);
		neighbours[b].push_back(a);
	}

	for(auto good : goodList) {
		distRecord(good);
	}

	for (int i = 1; i <= n; i++) {
	// for (int i = 2; i <= 2; i++) {
		// city i
		int ans = 0;
		priority_queue<int> values;
		for (auto good : goodList) {
			values.push(-dist[good][i]);
		}

		// cout << "values size " << values.size() << endl;

		for (int i = 0; i < s; i++) {
			ans -= values.top();
			// cout << values.top() << endl;
			values.pop();
		}
		cout << ans << " ";
	}
	cout << endl;

	// cout << endl << "Debug" << endl; 
	// cout << distBetween(1, 5) << endl;
}