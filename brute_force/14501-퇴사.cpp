#include <iostream>

using namespace std;

// 14591 - 퇴사 1hr 04min
int N;
int T[16 + 1], P[16 + 1];

long long selectConsult(int idx) {
	long long ret = 0;
	for (int i = idx + 1; i <= N; ++i) {
		if (i + T[i] - 1 > N) continue;
		ret = max(ret, selectConsult(i + T[i] - 1) + P[i]);	
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> T[i] >> P[i];
	}
	
	cout << selectConsult(0) << "\n";

	return 0;
}
