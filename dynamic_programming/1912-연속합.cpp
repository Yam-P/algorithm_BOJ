#include <iostream>
#include <algorithm>

// 1912 연속합 - 1hr 23min...

using namespace std;
#define FOR(i, n) for(int i = 1; i <= n; ++i)

int n;
int numArr[100001];
int dp[100001];

int segSum() {
	int ret = dp[1] = numArr[1];
	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i - 1] + numArr[i];
		if (numArr[i] > dp[i]) dp[i] = numArr[i];
		ret = max(ret, dp[i]);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;	
	FOR(i, n) {
		cin >> numArr[i];
	}

	cout << segSum() << "\n";
	
	return 0;
}

#if 0
int segSum(int beg, int end) {
	if (beg > end) return 0;
	int ret = -1001;
	for (int i = beg; i <= end; ++i) {
		// 다음 beg은 i + 1
		ret = max(ret, segSum(i + 1, end) + numArr[i]);
	}
	printf("max ret: %d\n", ret);
	return ret;
}
#endif
