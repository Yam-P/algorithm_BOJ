#include <iostream>

using namespace std;

// 1182 - 부분수열의 합

int N, S;
int seq[21];
bool startFlag = true;
int cnt = 0;

void count(int cur, int sum) {
	if (!startFlag && (sum == S)) cnt++;
	if (cur == N - 1) return;

	for (int next = cur + 1; next < N; ++next) {
		startFlag = false;
		count(next, sum + seq[next]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; ++i) {
		cin >> seq[i];
	}

	count(-1, 0);
	cout << cnt << "\n"; 

	return 0;
}
