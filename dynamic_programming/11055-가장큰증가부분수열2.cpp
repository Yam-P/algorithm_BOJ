#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// 가장 큰 증가 부분 수열
int N;
int A[1000001];
int cache[1000001];

int lis(int cur) {
	int &ret = cache[cur + 1];
	if (ret != -1) return ret;
	ret = 0;
	for (int next = cur + 1; next < N; ++next) {
		if (cur == -1) 
			ret = max(ret, 1 + lis(next));
		else if (A[cur] < A[next])
			ret = max(ret, 1 + lis(next));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i]; 
	}
	memset(cache, -1, sizeof(cache));
	cout << lis(-1) << "\n";

	return 0;
}

