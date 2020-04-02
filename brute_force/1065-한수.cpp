#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;
#define FOR(i, n) for(int i = 0; i < n; ++i)

// 1065 - 한수 - 52min
int N;

int seq(string num) {
	if (num.size() < 2) return true;

	for (int i = 1; i < num.size(); ++i) {
		if (num[i] - num[i - 1] != num[1] - num[0]) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;
	
	int result = 0;
	for (int i = 1; i <= N; ++i) {
		if(seq(to_string(i))) result += 1;
	}
	cout << result << "\n";
	
	return 0;
}
