#include <iostream>
#include <cstring>

using namespace std;

// 1904 - 01타일 1hr 4min
int N;
const int MOD = 15746;
#if 0
long long cache[1000001];

long long seqCnt(int idx) {
	if (idx >= N) return 0;
	if (idx == N - 1) return 1;

	long long &ret = cache[idx + 1];
	if (ret != -1) {
		//printf("repeated case!\n");
		return ret;
	}

	long long case1 = 0, case2 = 0;
	case1 += seqCnt(idx + 2) % MOD;
	case2 += seqCnt(idx + 1) % MOD;

	return ret = (case1 + case2) % MOD;
}
#endif

int seq[3];
int fibo(int n) {
	if (n <= 1) return 1;
	seq[0] = 1;
	seq[1] = 1;
	for (int i = 2; i <= n; ++i) 
		seq[i % 3] = (seq[(i - 1) % 3] + seq[(i - 2) % 3]) % MOD;

	return seq[n % 3] % MOD; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	//for (int i  = 0; i < 1000001; ++i) cache[i] = -1;
	//cout << seqCnt(-1) % MOD << "\n";
	cout << fibo(N) << "\n";

	return 0;
}
