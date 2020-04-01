#include <iostream>

using namespace std;
#define FOR(i, n) for(int i = 0; i < n; ++i)

// 9461 - 파도반 수열 12min
long long dp[101];
long long seq(int N) {
	dp[0] = dp[1] = dp[2] = 1;
	for (int i = 3; i < N; ++i) {
		dp[i] = dp[i - 3] + dp[i - 2];
	}

	return dp[N - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	
	FOR(t, T) {
		int N;
		cin >> N;
		cout << seq(N) << "\n";
	}

	return 0;
}
