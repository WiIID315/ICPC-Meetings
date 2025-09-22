#include <iostream>

#define ll long long

using namespace std;

int dsu[100001];
int depth[100001];

int find(int idx) {
	if(dsu[idx] < 0) return idx;
	int root = find(dsu[idx]);
	dsu[idx] = root;
	return root;
}

int main() {
	int n, m;
	dsu[1] = -1;
	cin >> n >> m;
	for(int i = 0; i < n - 1; i++) {
		int val;
		cin >> val;
		dsu[i + 2] = val == 1? -1: val;
		depth[i + 2] = depth[val] + 1;
	}
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if(b == 1 || (find(a) == find(b) && depth[b] < depth[a])) {
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl;
		}
	}
	return 0;
}