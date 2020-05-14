#include <iostream>
#include <cstring>

using namespace std;

// 1890 - 점프
int N;
int map[101][101];
long long cache[101][101];

long long jump(int y, int x) {
	if (y >= N || x >= N) return 0;
	if (y == N - 1 && x == N - 1) return 1;

	long long &ret = cache[y][x];
	if (ret != -1) {
		//printf("repeated case!\n");
		return ret;
	}

	ret = 0;
	long long right = jump(y + map[y][x], x);
	long long down  = jump(y, x + map[y][x]);
	
	ret = right + down;
	
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int j = 0; j < N; ++j) {
		for (int i = 0; i < N; ++i) {
			cin >> map[j][i];
            cache[j][i] = -1;
		}
	}

	cout << jump(0, 0) << "\n";
	return 0;
}
