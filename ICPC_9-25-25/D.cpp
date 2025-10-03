#include <iostream>
#include <tuple>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using ii = tuple<int, int>;
using ll = long long;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> hops;
	for(int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		hops.push_back(temp);
	}

	int maxHops = 1000000000;
	for(auto& dist: hops) {
		if(x % dist == 0) maxHops = min(maxHops, x / dist);
		else if (dist > x) {
			maxHops = min(maxHops, 2);
		} else {
			maxHops = min(maxHops, x / dist + 1);
		}
	}
	cout << maxHops << '\n';

}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int t;
    cin >> t;
    while(t-- > 0) solve();
	return 0;
}