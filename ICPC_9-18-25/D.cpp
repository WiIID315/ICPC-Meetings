#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;
int books[100000];

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;
    for(int i = 0; i < n; i++) cin >> books[i];
    int left = 0;
	int ans = 0;
	for(int right = 0; right < n; right++) {
		t -= books[right];
		while(t < 0) {
			t += books[left++];
		}
		ans = max(ans, right - left + 1);
	}

	cout << ans << '\n';

	return 0;
}