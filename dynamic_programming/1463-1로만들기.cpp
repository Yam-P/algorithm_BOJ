#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
#define FOR(i, n) for(int i = 0; i < n; ++i)
#define INF (987654321)
#define MAX_SIZE (1000001)

int cache[MAX_SIZE];

int makeOne(int N) {
	if (N == 0) return 0; // 1을 만들지 못한 경우
	if (N == 1) return 1;

	int &ret = cache[N];
	if (ret != -1) {
		//printf("repeated case!!\n");
		return ret;
	}

	int case1 = INF, case2 = INF, case3 = INF;

	// case3 경우를 마친 후 밑에 두 경우 가서 확인
	case3 = 1 + makeOne(N - 1);
	if (N % 3 == 0) case1 = 1 + makeOne(N / 3);
	if (N % 2 == 0) case2 = 1 + makeOne(N / 2);

	ret = min(case3, min(case1, case2));	

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	
	memset(cache, -1, sizeof(cache));
	// 1인 경우도 한번 세므로
	cout << makeOne(N) - 1 << "\n";
	
	return 0;
}
