#include <iostream>


using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	if(k >= n - 1) cout << 1 << '\n';
	else cout << n << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t-- > 0) solve();
	return 0;
}