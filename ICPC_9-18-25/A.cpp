#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int arr[1000];
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int l = 0;
	int r = n - 1;
	bool sTurn = true;
	ll s = 0, d = 0;
	while(l <= r) {
		int temp;
		if (arr[l] > arr[r]) {
			temp = arr[l++];
		} else {
			temp = arr[r--];
		}

		if(sTurn) s += temp;
		else d += temp;
		sTurn = !sTurn;
	}

	cout << s << " " << d << endl;
}