#include <iostream>
#include <cstring>

using namespace std;

// 2193 - 이친수 27min
#define FOR(i, n) for(int i = 0; i < n; ++i)

int N;
long long cache[91][2];

long long  getPinary(int idx, int curNum) {
	if (idx == N) return 1;

	long long &ret = cache[idx][curNum];
	if (ret != -1) {
		printf("repeated case!\n");
		return ret;
	}

	ret = 0;
	if (curNum == 0) {
		ret += getPinary(idx + 1, 1) + getPinary(idx + 1, 0);
	}	
	else {
		ret += getPinary(idx + 1, 0);
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	FOR (j, 91) {FOR (i, 2) cache[j][i] = -1;}
	//memset(cache, -1, sizeof(cache));
	cout << getPinary(1, 1) << "\n";	
	return 0;
}
