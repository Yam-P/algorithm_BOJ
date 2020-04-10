#include <iostream>
#include <cstring>

using namespace std;

// 10164 - 격자상의 경로 25min
int N, M, K;
int map[17][17];
int cache[17][17];

int move (int y, int x, bool visit) {
	if (y > N || x > M) return 0;
	if ((y == N && x == M) && visit) return 1;
	
	#if 0
	int &ret = cache[y][x];
	if (ret != -1) {
		printf("repeated case!\n");
		return ret;
	}
	#endif
	if (map[y][x] == K) visit = true; 	

	int case1 = move(y + 1, x, visit);
	int case2 = move(y, x + 1, visit);
	visit = false;	

	return case1 + case2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	int val = 0;
	for (int j = 1; j <= N; ++j) {
		for (int i = 1; i <= M; ++i) {
			val++;
			map[j][i] = val; 	
		}
	}	
	memset(cache, -1, sizeof(cache));
	if (K != 0) cout << move(1, 1, false) << "\n";
	else cout << move(1, 1, true) << "\n";
	
	return 0;
}
