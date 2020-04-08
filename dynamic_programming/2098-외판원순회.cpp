#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// 2098 - 외판원 순회

#define INF (987654321)
int N;
int W[16][16];
int cache[16][1 << 16];

// 0부터 출발해서 0으로 끝나는 결과가 최소이면 이루트 그대로 다른 곳에서 출발해서 다른 곳으로 끝나는 결과도 최소
// 0 - 1 - 2 - 3 - 4 - 0 = 2 - 3 - 4 - 0 - 1 - 2
int travel(int here, int visited) {
	if (visited == ((1 << N) - 1)) {
		if (W[here][0] == 0) return INF;
		else return W[here][0];
	}

	int &ret = cache[here][visited];
	if (ret != -1) {
		//printf("repeated case!\n");
		return ret;
	}

	ret = INF;
	for (int next = 0; next < N; ++next) {
		// 거리 값이 0인 경우 패스
		if (W[here][next] == 0) continue;
		if (visited & (1 << next)) continue;
		//visited |= 1 << next; // 가장 큰 실수!!.. 누적시키면 안되지..
		ret = min(ret, travel(next, visited | (1 << next)) + W[here][next]);
	}

	return ret;	
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int j = 0; j < N; ++j) {
		for (int i = 0; i < N; ++i) {
			cin >> W[j][i];
		}	
	}
	
	memset(cache, -1, sizeof(cache));
	cout << travel(0, 1) << "\n";
	return 0;
}
