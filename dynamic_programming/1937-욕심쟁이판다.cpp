#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// 1937 - 욕심쟁이 판다
const int MAX_SIZE = 501 + 1;
int n;
int map[MAX_SIZE][MAX_SIZE];
int cache[MAX_SIZE][MAX_SIZE];

typedef struct {
	int y, x;
} direction;

direction dir[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int moving(int y, int x) {
	if (y <= 0 || y > n || x <= 0 || x > n) return 0;
	
	int &ret = cache[y][x];
	if (ret != -1) {
		//printf("repeated case!\n");
		return ret;
	}

	ret = 0;
	for (int k = 0; k < 4; ++k) {
		int ny = y + dir[k].y;
		int nx = x + dir[k].x;
		if (map[ny][nx] > map[y][x])
			ret = max(ret, 1 + moving(ny, nx));
	}

	return ret;
}

int solve() {
	int res = -1;
	for (int j = 1; j <= n; ++j) {
		for (int i = 1; i <= n; ++i) {
			res = max(res, moving(j, i));
		}
	}
	return res + 1; // 시작하는 지점도 한번으로 세기
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	memset(map, 0, sizeof(map));	
	for (int j = 1; j <= n; ++j) {
		for (int i = 1; i <= n; ++i) {
			cin >> map[j][i];	
		}
	}
	
	memset(cache, -1, sizeof(cache));
	cout << solve() << "\n";

	return 0;
}
