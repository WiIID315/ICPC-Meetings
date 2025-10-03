#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;
using ll = long long;

ll greed(int pos, vector<int>& score, vector<int>& perm, unordered_set<int>& visited, int k) {
	if(k == 0) return 0;
	if(visited.find(pos) != visited.end()) return 0;
	visited.insert(pos);
	return max(1ll * score[pos] * k, score[pos] + greed(perm[pos], score, perm, visited, k - 1));
}

void solve() {
	int n, k, pb, ps;
	cin >> n >> k >> pb >> ps;
	vector<int> perm(n);
	vector<int> vals(n);
	--pb;
	--ps;
	for(int i = 0; i < n; ++i) {
		cin >> perm[i];
		--perm[i];
	}
	for(int i = 0; i < n; ++i) 
		cin >> vals[i];
	unordered_set<int> visited;
	ll b = greed(pb, vals, perm, visited, k);
	visited.clear();
	ll s = greed(ps, vals, perm, visited, k);

	if(b > s)
		cout << "Bodya" << '\n';
	else if (b < s)
		cout << "Sasha" << '\n';
	else
		cout << "Draw" << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t-- > 0) solve();
	return 0;
}