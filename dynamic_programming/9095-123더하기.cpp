#include <iostream>
#include <cstring>

using namespace std;
#define FOR(i, n) for(int i = 0; i < n; ++i)
#define MAX_SIZE (12)

int cache[MAX_SIZE];
int n;

// 9095 - 1,2,3 더하기 33min .. 파일명 , 있으면 브레이크 안된다..
int add123(int sum) {
	if (sum > n) return 0;
	if (sum == n) return 1;

	int &ret = cache[sum];
	if (ret != -1) {
		//printf("repeated case!!\n");
		return ret;
	}
	
	// 각 경우에서 sum = n을 완성하면 1씩 카운트
	ret = add123(1 + sum) + add123(2 + sum) + add123(3 + sum);

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int C;
	cin >> C;
	FOR (c, C) {
		cin >> n;
		
		memset(cache, -1, sizeof(cache));
		cout << add123(0) << "\n";
	}
	
	return 0;
}
