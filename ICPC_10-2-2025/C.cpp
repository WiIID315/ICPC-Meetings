#include <iostream>
#include <algorithm>

using namespace std;

int depths[1000][1000];

int dfs(int i, int j, int n, int m) {
	if(i < 0 || i >= n || j < 0 || j >= m || !depths[i][j]) return 0;
	int val = depths[i][j];
	depths[i][j] = 0;
	return val + dfs(i - 1, j, n, m) + dfs(i + 1, j, n, m) + dfs(i, j - 1, n, m) + dfs(i, j + 1, n, m);
}

void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> depths[i][j];
		}
	}
	int best = 0;
	for(int i =0 ; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(depths[i][j]) best = max(best, dfs(i, j, n, m));
		}
	}
	cout << best << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t-- > 0) solve();
	return 0;
}