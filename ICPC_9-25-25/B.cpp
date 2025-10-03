#include <iostream>


using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	if(n % m == 0) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int t;
    cin >> t;
    while(t-- > 0) solve();
	return 0;
}