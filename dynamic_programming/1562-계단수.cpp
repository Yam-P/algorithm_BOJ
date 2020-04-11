#include <iostream>
#include <cstring>

using namespace std;

// 1562 - 계단 수
const int MOD = 1000000000;
int N;
int cache[101][10][1 << 10];
int num;
int stair(int idx, int curNum, int num) {
	if (idx == N) {
		return (num == ((1 << 10) - 1)) ? 1 : 0;
	}

	int &ret = cache[idx][curNum][num];
	// 232와 432는 32부분 연산이 겹치는 경우.
	// 숫자 진행이 다르면 다른 경우로 취급
	if (ret != -1) {
		//printf("repeated case!\n");
		return ret;
	}

	ret = 0;
	// 가지치기 해당 경우 재귀 X
	if (curNum + 1 <= 9)
		ret += stair(idx + 1, curNum + 1, num | (1 << (curNum + 1))); 
	if (curNum - 1 >= 0)
		ret += stair(idx + 1, curNum - 1, num | (1 << (curNum - 1)));

	return ret %= MOD;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	
	int result = 0;
	for (int i = 1; i <= 9; ++i) {
		memset(cache, -1, sizeof(cache));
		result += stair(1, i, 1 << i);
		result %= MOD;
	}
	cout << result % MOD << "\n";

	return 0;
}