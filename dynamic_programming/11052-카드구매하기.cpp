#include <iostream>
#include <cstring>

using namespace std;
#define FOR(i, n) for(int i = 0; i < n; ++i)
#define MAX_SIZE (41)
int N;
int P[1001];
int cache[1001][1001];

#if 0 // 완전탐색
// 11052 - 카드구매하기 
int pick(int rest) {
	if (rest == 0) return 0;

	int ret = 0;

	for (int i = 1; i <= N; ++i) {
		if (rest - i >= 0) ret = max(ret, pick(rest - i) + P[i]);  	
	}
	return ret;
}
#endif

// 동적 계획법
int pick(int rest, int idx) {
	if (rest == 0) return 0;

	int &ret = cache[rest][idx];
	if (ret != -1) {
		//printf("repeated case!\n");
		return ret;
	}
	for (int i = 1; i <= N; ++i) {
		if (rest - i >= 0) ret = max(ret, pick(rest - i, i) + P[i]);  	
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	
	for (int i = 1; i <= N; ++i) {
		cin >> P[i];
	}	
	memset(cache, -1, sizeof(cache));
	//cout << pick(N) << "\n";	
	cout << pick(N, 1) << "\n";
	
	return 0;
}
