#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
#define FOR(i, n) for(int i = 0; i < n; ++i)
#define INF (987654321)

// 여행 짐싸기 문제와 유사
// 2156 - 포도주 시식 47min 
int n;
int volume[10001 + 1] = { 0, };

// step, # of wines
int cache[3][10001 + 1];

int drinkWine(int step, int idx) {
	if (idx >= n + 1) return 0; 

	int &ret = cache[step][idx];
	if (ret != -1) {
	    //printf("repeated case!\n");
		return ret;
	}

	int singleStep = 0;
	// 선택 하지 않고 건너 뛰는 것으로 생각. step은 채우지 않음
	int doubleStep = drinkWine(0, idx + 1);
	if ((step + 1) % 3 != 0) singleStep = drinkWine(step + 1, idx + 1) + volume[idx]; 
	return ret = max(singleStep, doubleStep);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n + 1; ++i) {
		cin >> volume[i];
	}
	
	memset(cache, -1, sizeof(cache));

	// 중간에는 연달아 두칸만 가능
	cout << drinkWine(0, 0) << "\n";
	
	return 0;
}
