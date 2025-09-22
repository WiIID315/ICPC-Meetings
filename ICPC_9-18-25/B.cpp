#include <iostream>
#include <string>

using namespace std;


void solve() {
	int n;
	cin >> n;
	string str;
	cin >> str;

	int l = 0, r = n - 1;
	while(l < r) {
		if(str[l] == '1' && str[r] == '0' || str[l] == '0' && str[r] == '1') {
			++l;
			--r;
		} else {
			break;
		}
	}
	cout << r - l + 1 << '\n';
}

int main() {
	int t;
	cin >> t;
	while(t-- > 0) solve();
}