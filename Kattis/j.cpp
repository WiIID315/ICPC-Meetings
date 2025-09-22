#include <iostream>
#include <string>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
	int score = 0;
	int ymax = 0;
	int ymin = 0;
	int yStreak, nStreak = 0;
	int currStreak = 0;
	string winner;
	char prev = '@';

	int n;
	cin >> n;

	for(int t = 0; t < n; t++) {
		cin >> winner;
		if(winner[0] == 'Y') {
			++score;
			ymax = max(score, ymax);
			if(prev == 'Y') {
				++currStreak;
			} else {
				currStreak = 1;
				prev = 'Y';
			}
			yStreak = max(yStreak, currStreak);
		} else {
			--score;
			ymin = min(score, ymin);
			if(prev == 'N') {
				++currStreak;
			} else {
				prev = 'N';
				currStreak = 1;
			}
			nStreak = max(currStreak, nStreak);
		}
	}

	if(nStreak > yStreak && -ymin > ymax || yStreak > nStreak && ymax > -ymin || yStreak == nStreak & ymax == -ymin) {
		cout << "Agree" << endl;
	} else {
		cout << "Disagree" << endl;
	}

	return 0;
}