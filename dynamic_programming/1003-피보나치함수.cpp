#include <iostream>

using namespace std;
#define FOR(i, n) for(int i = 0; i < n; ++i)
#define MAX_SIZE (41)

// 1003 - 피보나치 함수 1hr 30m .. 
// runtime error / time over..
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	int	zero[MAX_SIZE] = {1, 0}; 
	int	one[MAX_SIZE] = {0, 1}; 

	for (int i = 2; i <= MAX_SIZE; ++i) {
		zero[i] = zero[i - 1] + zero[i - 2]; 	
		one[i] = one[i - 1] + one[i - 2]; 	
	}

	FOR (t, T) {
		int N;
		cin >> N;
		cout << zero[N] << " " << one[N] << "\n";
	}
	
	return 0;
}

#if 0
int cache[MAX_SIZE][2];
int zeroCnt = 0, oneCnt = 0;

int fibonacciFunction(int N, int zeroCnt, int oneCnt) {
	if (N == 0) {
		zeroCnt++;
		return 0;
	}
	if (N == 1) {
		oneCnt++;
		return 0;
	}

	return fibonacciFunction(N - 1) + fibonacciFunction(N - 2);
}
#endif
