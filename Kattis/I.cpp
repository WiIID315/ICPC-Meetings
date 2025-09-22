#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int d1 = b - a;
	int d2 = c - b;
	if(d1 == d2) {
		cout << "cruised" << endl;
	} else if (d1 * d2 < 0) {
		cout << "turned" << endl;
	} else if (abs(d2) < abs(d1)) {
		cout << "braked" << endl;
	} else {
		cout << "accelerated" << endl;
	}


	return 0;
}