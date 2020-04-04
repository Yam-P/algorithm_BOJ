#include <iostream>
#include <cstring>

using namespace std;
#define INF (987654321)

// 1699 - 제곱수의 합
int cache[100001];
int squareSum(int num) {
	int &ret = cache[num];
	if (ret != -1) {
		//	printf("repeated case!\n");
		return ret;
	}

	if (num == 0) return 0; 

	ret = INF;
	for(int i = 1; i * i <= num; ++i) {
		if (num - i * i >= 0) ret = min(ret, 1 + squareSum(num - i * i));
	}	
	return ret;	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	memset(cache, -1, sizeof(cache));
	cout << squareSum(N) << "\n";

	return 0;
}
