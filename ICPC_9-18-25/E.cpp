#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#define ll long long

using namespace std;

int students[100000];
int topics[100000];
unordered_map<int, vector<int> > map;

void findTopics(int m, int student) {
	if (map.find(student) != map.end())
		return;
	vector<int> vec;
	for(int i = 1; i <= min((double)m, sqrt(student)); i++) {
		if(student % i == 0) {
			vec.push_back(i);
			if(student / i <= m && i != student / i) {
				vec.push_back(student / i);
			}
		}
	}
	map[student] = vec;
}

void solve() {
	map.clear();
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> students[i];
		findTopics(m, students[i]);
	}

	unordered_set<int> set;
	for(int i = 1; i <= m; i++) {
		set.insert(i);
		topics[i] = 0;
	}

	sort(students, students + n);

	int left = 0;
	int ans = 1e6;
	for(int right = 0; right < n; right++) {

		vector<int> vec = map[students[right]];
		for(unsigned int i = 0; i < vec.size(); i++) {
			if(!topics[vec[i]]++) {
				set.erase(vec[i]);
			}
		}


		while(!set.size()) {
			ans = min(ans, students[right] - students[left]);
			vector<int> temp = map[students[left]];
			for(unsigned int i = 0; i < temp.size(); i++) {
				if(--topics[temp[i]] == 0) {
					set.insert(temp[i]);
				}
			}
			++left;
		}
	}
	cout << (ans == 1e6? -1: ans) << endl;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t-- > 0) solve();

    return 0;
}