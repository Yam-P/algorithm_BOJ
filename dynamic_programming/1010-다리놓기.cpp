#include <iostream>
#include <cstring>

using namespace std;
// 1010 - 다리놓기 40min
int N, M;
int cache[31][31];

int putBridge(int n, int m) {
	if (n == 1) return m; 

	int &ret = cache[n][m];
	if (ret != -1) {
	//	printf("repeated case!\n");
		return ret;
	}

	ret = 0;
	for (int i = 0; i <= m - n; ++i) {
		ret += putBridge(n - 1, m - (i + 1));
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> N >> M;
		memset(cache, -1, sizeof(cache));
		cout << putBridge(N, M) << "\n";	
	}

	return 0;
}