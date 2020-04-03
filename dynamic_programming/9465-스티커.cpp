#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// 9465 - 스티커 40min
int n;
int board[2][100001];
int cache[2][100001];

int sticker(int y, int x) {
	if (x >= n) return 0;

	int &ret = cache[y][x];
	if (ret != -1) {
	//	printf("repeated case!\n");
		return ret;
	}

	int case1 = 0, case2 = 0, case3 = 0;
	case1 = sticker(1 - y, x + 1);
	case2 = sticker(0, x + 2);
	case3 = sticker(1, x + 2);
	
	return ret = max(case1, max(case2, case3)) + board[y][x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> n;
		memset(board, 0, sizeof(board));
		memset(cache, -1, sizeof(cache));

		for (int j = 0; j < 2; ++j) {
			for (int i = 0; i < n; ++i) {
				cin >> board[j][i];
			}
		}

		cout << max(sticker(0, 0), sticker(1, 0)) << "\n";
	}

	return 0;
}
