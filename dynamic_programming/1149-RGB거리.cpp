#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
#define FOR(i, n) for(int i = 0; i < n; ++i)
#define INF (987654321)

// 1149 - RGB 거리 
int dist[1001][3];
int cache[1001][3];
int N;

int rgbDist (int y, int color) {
	if (y == N) return dist[y][color];

	int &ret = cache[y][color];
	if (ret != -1) {
		//printf("repeated case\n");
		return ret;
	}

	ret = INF;
	for (int idx = 0; idx < 3; ++idx) {
		if (color != idx) {
			ret = min(ret, dist[y][color] + rgbDist(y + 1, idx)); 
		}
	} 
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	FOR (j, N) {
		FOR (i, 3) {
			cin >>	dist[j][i];
		}
	}
	
	int result = INF;
	memset(cache, -1, sizeof(cache));
	FOR (i, 3) {
		result = min(result, rgbDist(0, i));
	}
	cout << result << "\n";
	return 0;
}
