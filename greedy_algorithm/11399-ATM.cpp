#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 11399 ATM

vector<int> P;

int solve() {
	int ret = P[0];
	int tmpSum = P[0];

	for (int i = 1; i < P.size(); ++i) {
		tmpSum += P[i];
		ret += tmpSum;
	}

	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	P.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> P[i];
	}

	sort(P.begin(), P.end());
	cout << solve() << "\n";

	return 0;
}
