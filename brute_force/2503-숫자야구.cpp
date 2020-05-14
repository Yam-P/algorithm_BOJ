#include <iostream>

using namespace std;

// 2503 - 숫자야구
#define FOR(i, N) for(int i = 1; i <= N; ++i)
int N;
string question[101];
int strike[101];
int ball[101];

bool cmp(string newNum) {
	for (int idx = 0; idx < N; ++idx) {
		int strikeCnt = strike[idx];
		int ballCnt = ball[idx];
		for (int i = 0; i < 3; ++i) {
			if (newNum[i] == question[idx][i]) strikeCnt--;
			else {
				for (int j = 0; j < 3; ++j) {
					if (i == j) continue;
					else {
						ballCnt--;
						break;
					}
				}
			}
		}
		if (strikeCnt == 0 && ballCnt == 0) continue;
		return false;
	}
	return true;
}

int generateNum() {
	int ret = 0;
	int questionIdx = 0;
	
	FOR (i, 9) {
		FOR (j, 9) {
			FOR (k, 9) {
				string newNum = to_string(i) + to_string(j) + to_string(k);
				if(cmp(newNum)) ret++;
			}
		}
	}
	return ret;	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> question[i] >> strike[i] >> ball[i];
	}
	cout <<	generateNum() << "\n";

	return 0;
}
