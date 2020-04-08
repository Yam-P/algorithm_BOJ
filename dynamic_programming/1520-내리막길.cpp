#include <iostream>
#include <cstring>

using namespace std;

// 1520 - 내리막길
int N, M;
int map[501][501];
int cache[501][501];

int move(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= M) return 0;
	if (y == N - 1 && x == M - 1) return 1;

	int &ret = cache[y][x];
	if (ret != -1) {
		//printf("repeated case!\n");
		return ret;
	}
	
	ret = 0;
	if (y - 1 >= 0 && (map[y - 1][x] < map[y][x])) ret += move(y - 1, x);
	if (y + 1 <= N && (map[y + 1][x] < map[y][x])) ret += move(y + 1, x);
	if (x - 1 >= 0 && (map[y][x - 1] < map[y][x])) ret += move(y, x - 1);	
	if (x + 1 <= M && (map[y][x + 1] < map[y][x])) ret += move(y, x + 1);
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int j = 0; j < N; ++j) {
		for (int i = 0; i < M; ++i) {
			cin >> map[j][i];
		}
	}

	memset(cache, -1, sizeof(cache));
	cout << move(0, 0) << "\n";
	return 0;
}
