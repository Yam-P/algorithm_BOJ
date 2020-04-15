#include <iostream>

using namespace std;

// 10448 - 유레카 이론 22min
int K;

int eureka(int rest, int triCnt) {
	if (triCnt == 3) return (rest == 0 ? 1 : 0);

	// end 조건 가지치기
	int bestTri = 0;
	for (int i = 1; (i*(i + 1)/2) < K; ++i) {
		bestTri = max(bestTri, i);
	}

	for (int next = bestTri; next >= 1; --next) {
		int triNum = next * (next + 1) / 2;
		if (rest - triNum >= 0) {
			if (eureka(rest - triNum, triCnt + 1)) return 1; 
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while (T-- > 0) {
		cin >> K;
		cout << eureka(K, 0) << "\n";
	}

	return 0;
}
