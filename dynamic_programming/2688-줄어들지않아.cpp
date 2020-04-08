#include <iostream>
#include <cstring>

using namespace std;

// 2688 - 줄어들지 않아 25min

int n;
long long cache[65][65];

long long incNum(int curIdx, int curNum) {
	if (curIdx == n) return 1;

	long long &ret = cache[curIdx][curNum];
	if (ret != -1) {
		//printf("repeated case!\n");
		return ret;
	}

	ret = 0;
	for (int i = curNum; i < 10; ++i) {
		ret += incNum(curIdx + 1, i);	
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while(T-- > 0) {
		cin >> n;
		//memset(cache, -1, sizeof(cache));
		for (int j = 0; j < 65; ++j) {
			for (int i = 0; i < 65; ++i) {
				cache[j][i] = -1;
			}
		}
		cout << incNum(0, 0) << "\n";
	}

	return 0;
}
