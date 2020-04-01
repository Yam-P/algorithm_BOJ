#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

// 10844 - 쉬운 계단 수 
#define FOR(i, n) for(int i = 0; i < n; ++i)

int N;
int cache[101][10];
const int MOD = 1000000000;

int stairNumCnt(int idx, int prevNum) {
	if (idx == N) return 1;

	int &ret = cache[idx][prevNum];
	if (ret != -1) {
		//printf("repeated case!!\n");
		return ret;
	}
	ret = 0;
	if (prevNum >= 0 && prevNum <= 8) ret += stairNumCnt(idx + 1, prevNum + 1);
	if (prevNum >= 1 && prevNum <= 9) ret += stairNumCnt(idx + 1, prevNum - 1);

	return ret %= MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	int result = 0;
	memset(cache, -1, sizeof(cache));
	for (int i = 1; i <= 9; ++i) {
		// % MOD해서 더하는 것과 더하고 % MOD 하는 건 천지차이!!
		result = (result + stairNumCnt(1, i)) % MOD; 
	}
	cout << result << "\n";
	return 0;
}
