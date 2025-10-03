#include <iostream>
#include <vector>


using namespace std;

void solve() {
	int n, s;
	cin >> n >> s;
	--s;
	vector<int> b(n);
	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> b[i];
	for(int i = 0; i < n; ++i) cin >> a[i];
	bool open = false;
	for(int i = s; i < n; ++i) {
		if(b[i] && a[i]) {
			open = true;
			break;
		}
	}

	if(b[0] && b[s] || (b[0] && a[s] && open)) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}