#include <iostream>
#include <vector>

using namespace std;

// 11047 - 동전 0

int N, K;
vector<int> A;
int minimum = 987654321;

void coin(int cnt, int rest) {
	if (rest == 0) {
		minimum = min(minimum, cnt);
		return;
	} 

#if 1
	int start = 0;
	for (int i = A.size() - 1; i >= 0; --i) {
		if (rest > A[i]) {
			start = i;
			break;
		}
	}
#endif
	
	for (int i = A.size() - 1; i >= 0; --i) {
		if (rest >= A[i]) {
			coin(cnt + 1, rest - A[i]);		
			return;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}	
	
	coin(0, K);
	cout << minimum << "\n";
	return 0;
}
