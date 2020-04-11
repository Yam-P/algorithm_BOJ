#include <iostream>

using namespace std;

// 7568 - 덩치 29min
int N;
int inform[201][201];
int ranking[201];

void solve(int cur, int next) {
	if (next == N) return;

	if (inform[cur][0] < inform[next][0] && inform[cur][1] < inform[next][1]) {
		ranking[cur] += 1;
	}

	solve(cur, next + 1);	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> inform[i][0] >> inform[i][1];
		ranking[i] = 1;
	}		

	for (int i = 0; i < N; ++i) 
		solve(i, 0);

	for (int i = 0; i < N; ++i)
		cout << ranking[i] << " ";
	cout << "\n";
	return 0;
}
