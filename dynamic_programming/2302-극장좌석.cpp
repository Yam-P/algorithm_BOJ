#include <iostream>
#include <vector>

using namespace std;

// 2302 - 극장 좌석
int N;

int seat(int cur, long long visited) {
	if (visited == (1 << (N + 1)) - 1 ) return 1;

	// VIP인 경우
	if (visited & (1 << (cur - 1)) && visited & (1 << cur)) 
		return seat(cur + 1, visited); 

	int ret = 0;
	for (int next = cur - 1; next <= cur + 1; ++next) {
		if (visited & (1 << next)) continue;
		if (next > N) continue;
		ret += seat(cur + 1, visited | (1 << next));	

	}

	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int M;
	cin >> N >> M;
	long long visited = 1; 
	for (int i = 0; i < M; ++i) {
		int sat;
		cin >> sat;
		visited |= 1 << sat;
	}

	cout << seat(1, visited); 

	return 0;
}
