#include <iostream>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
using ii = tuple<int, int>;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<ii> vec;
	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		vec.push_back({x, y});
	}
	bool valid = false;

	for(int i = 0; i < n; i++) {
		if(valid) break;
		bool temp = true;
		int xi = get<0>(vec[i]);
		int yi = get<1>(vec[i]);
		for(int j = 0; j < n; j++) {
			if(i == j) continue;
			int xj = get<0>(vec[j]);
			int yj = get<1>(vec[j]);
			if(abs(xi - xj) + abs(yi - yj) > k) {
				temp = false;
				break;
			}
		}
		valid = temp;
	}
	if(valid) cout << 1 << '\n';
	else cout << -1 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int t;
    cin >> t;
    while(t-- > 0) solve();
	return 0;
}