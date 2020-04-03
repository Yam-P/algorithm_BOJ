#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 2293 - 동전 1
int n, k;
vector<int> coins;

#if 0
// 완전 탐색법 - 시간초과
int pick(int restVal, int cur) {
	if (restVal == 0) return 1;

	int ret = 0;
	for (int i = 0; i < n; ++i) {
		if (restVal - coins[i] >= 0 && coins[i] <= cur ) 
			ret += pick(restVal - coins[i], coins[i]); 	
	}
	return ret;
} 
#endif

int cache[101][101];
int pick(int restVal, int cur) {
	if (restVal == 0) return 1;

	int ret = 0;
	for (int i = 0; i < n; ++i) {
		if (restVal - coins[i] >= 0 && coins[i] <= cur ) 
			ret += pick(restVal - coins[i], coins[i]); 	
	}
	return ret;
} 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	coins.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> coins[i];
	}

	sort(coins.rbegin(), coins.rend());
	cout << pick(k, coins[0]) << "\n";

	return 0;
}
