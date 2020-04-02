#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

// 2231 - 분해합 26min.. 문제 똑바로 읽기!
int generateNum(int N) {
	int i = 1;	
	for (; i < N; ++i) {
		string num = to_string(i);
		int sum = 0;
		for (int k = 0; k < num.size(); ++k) {
			sum += num[k] - 48;
		}
		if (i + sum == N) return i;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N;
	cin >> N;

	cout << generateNum(N) << "\n";
	return 0;
}
