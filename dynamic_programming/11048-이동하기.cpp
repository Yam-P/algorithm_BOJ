#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int N, M;
int candy[1001][1001];
int cache[1001][1001];

int move (int y, int x) {
	if (y >= N || x >= M) return 0;
	if (y == N - 1 && x == M - 1) return candy[y][x];
	
	int &ret = cache[y][x];
	if (ret != -1) {
		//	printf("repeated case!\n");
		return ret;
	}

	int case1 = move(y, x + 1);
	int case2 = move(y + 1, x);
	int case3 = move(y + 1, x + 1);
	
	return ret = max(case1, max(case2, case3)) + candy[y][x];

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N >> M;
	for (int j = 0; j < N; ++j) {
		for (int i = 0; i < M; ++i) {
			cin >> candy[j][i];
		}
	}

	memset(cache, -1, sizeof(cache));
	cout << move(0, 0) << "\n";

	return 0;
}
