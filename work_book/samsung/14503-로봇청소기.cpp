#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

// 14503 - 로봇 청소기

int N, M;
int r, c, d;
int map[51][51];
int cnt = 0;

const int go[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void drawMap() {
	vector<string> MAP(N, "");
	for (int j = 0; j < N; ++j) {
		for (int i = 0; i < M; ++i) {
			MAP[j] += to_string(map[j][i]);
		}
	}
	cout << MAP[0] << "\n";
}

void clean(int y, int x, int dir, int rot) {
	if (y < 0 || y >= N || x < 0 || x >= M) return;  

	//drawMap();

	if (rot == 4) {
		int _nDir = (dir + 2) % 4;
		int _ny = y + go[_nDir][0];
		int _nx = x + go[_nDir][1];
		clean(_ny, _nx, dir, 0);
	} 
	
	else {
		if (!map[y][x]) {
			map[y][x] = 1;
			cnt++;
		}

		int nDir  = (dir + 3) % 4;
		int ny = y + go[nDir][0];
		int nx = x + go[nDir][1];
		// 보는 방향 기준 왼쪽이 0인 경우 -> 방향 바꾸고 이동하기
		if (map[ny][nx] == 0) {
			clean(ny, nx, nDir, 0);
		}
			// 보는 방향 기준 왼쪽이 1인 경우 -> 방향만 바꾸기
		else if (map[ny][nx] == 1 || map[ny][nx] == -1) {
			clean(y, x, nDir, rot + 1);
		}
	}
	
	#if 0
	// 네 방향 모두 청소가 된 경우 -> 후진하기
	bool fourDirCheck = true;
	for (int i = 0; i < 4; ++i) {
		if (map[y + go[i][0]][x + go[i][1]])
			fourDirCheck = false;	
	}
	// 후진하며 방향은 그대로
	if (fourDirCheck) {
		int _nDir = (dir + 2) % 4;
		int _ny = y + go[_nDir][0];
		int _nx = x + go[_nDir][0];
		clean(_ny, _nx, dir);
	}
	#endif
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	cin >> r >> c >> d;
	
	memset(map, -1, sizeof(map));
	for (int j = 0; j < N; ++j) {
		for (int i = 0; i < M; ++i) {
			cin >> map[j][i];
		}
	}
	
	clean(r, c, d, 0);
	cout << cnt << "\n";

	drawMap();
	return 0;
}
