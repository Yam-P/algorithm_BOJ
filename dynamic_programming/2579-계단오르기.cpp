#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
#define FOR(i, n) for(int i = 0; i < n; ++i)
#define INF (987654321)

// 2579 - 계단 오르기  
int N;
int score[301 + 1] = { 0, };

// step, # of stairs
int cache[3][301 + 1];

int downStair(int step, int idx) {
	if (idx <= 1) return score[idx];

	int &ret = cache[step][idx];
	if (ret != -1) {
	    //printf("repeated case!\n");
		return ret;
	}

	int singleStep = 0;
	// 문제 해결 -  여기서 step을 1로 주기
	int doubleStep = downStair(1, idx - 2);
	if ((step + 1) % 3 != 0) singleStep = downStair(step + 1, idx - 1);
	return ret = max(singleStep, doubleStep) + score[idx];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> score[i];
	}
	
	memset(cache, -1, sizeof(cache));
	// 문제: 시작할 때는 연달아 세칸이 되는데
	// 중간에는 연달아 두칸만 가능
	cout << downStair(1, N) << "\n";
	
	return 0;
}

#if 0
int upStair(int step, int idx) {
	if (idx > N) return -INF;
	if (idx == N) return score[idx];

	int &ret = cache[step][idx];
	if (ret != -1) {
	    //printf("repeated case!\n");
		return ret;
	}

	int singleStep = 0;
	// 문제 해결 -  여기서 step을 1로 주기
	int doubleStep = upStair(1, idx + 2);
	if ((step + 1) % 3 != 0) singleStep = upStair(step + 1, idx + 1);
	printf("%d vs %d\n", singleStep, doubleStep);
	return ret = max(singleStep, doubleStep) + score[idx];
}
#endif
