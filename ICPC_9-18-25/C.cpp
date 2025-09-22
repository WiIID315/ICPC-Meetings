#include <iostream>
#include <algorithm>

using namespace std;
int girls[100];
int boys[100];

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int m;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> boys[i];
    cin >> m;
	for(int i = 0; i < m; i++) cin >> girls[i];

	sort(boys, boys + n);
	sort(girls, girls + m);

	int gp = 0, bp = 0;
	int pairs = 0;
	while(gp < m && bp < n) {
		int boy = boys[bp];
		int girl = girls[gp];

		if(abs(boy - girl) <= 1) {
			++pairs;
			++gp;
			++bp;
		} else if(boy < girl) {
			++bp;
		} else {
			++gp;
		}
	}

	cout << pairs << endl;

	return 0;
}