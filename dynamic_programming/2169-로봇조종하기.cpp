#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// 2169 - 로봇 조종하기 50min
const long long MIN = -2e9;

int N, M;
int value[1001][1001];
bool visited[1001][1001];

long long cache[1001][1001][3];

int moving[3][2] = {{0, 1}, {0, -1}, {1, 0}};

long long explore(int y, int x, int dir) {
	if (y >= N || x >= M || x < 0) return MIN;
	if (y == N - 1 && x == M - 1) return value[y][x];

	long long &ret = cache[y][x][dir];
	if (ret != MIN) {
		//printf("repeated case!\n");
		return ret;
	}
	
	ret = MIN;

	visited[y][x] = true;
	for (int i = 0; i < 3; ++i) {
		int ny = y + moving[i][0];
		int nx = x + moving[i][1];
		if (!visited[ny][nx])
			ret = max(ret, explore(ny, nx, i));
	}
	visited[y][x] = false;

	return ret += value[y][x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int j = 0; j < N; ++j) {
		for (int i = 0; i < M; ++i) {
			cin >> value[j][i];
			cache[j][i][0] = cache[j][i][1] = cache[j][i][2] = MIN;
		}
	}
	
	cout << explore(0, 0, 0) << "\n";

	return 0;
}
