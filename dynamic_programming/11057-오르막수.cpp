#include <iostream>
#include <cstring>

using namespace std;

// 11057 - 오르막 수 2hr..?
int N;
const int MOD = 10007;
int cache[1001][10];

int incNum(int step, int curNum) {
	int &ret = cache[step][curNum];
	if (ret != -1) {
		printf("repeated case!\n");
		return ret % MOD;
	}

	if (step == N) return ret = 10 - curNum;
	
	ret = 0;
	for (int i = curNum; i <= 9; ++i) {
		ret += incNum(step + 1, i);
	}
	return ret % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	memset(cache, -1, sizeof(cache));
	cout << incNum(1, 0) % MOD << "\n";

	return 0;
}
