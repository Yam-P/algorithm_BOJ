#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 14888 - 연산자 끼워넣기
int N;
const int INF = 1000000000;
int maxVal = -INF;
int minVal = INF; 

int numArr[12];
int oper[4];

void insert(int idx, int res) {
	if (idx == N) {
		maxVal = max(maxVal, res);
		minVal = min(minVal, res);
	}
	
	if (oper[0] > 0) {
		oper[0]--;
		insert(idx + 1, res + numArr[idx]);
		oper[0]++;
	}
	if (oper[1] > 0) {
		oper[1]--;
		insert(idx + 1, res - numArr[idx]);
		oper[1]++;
	}
	if (oper[2] > 0) {
		oper[2]--;
		insert(idx + 1, res * numArr[idx]);
		oper[2]++;
	}
	if (oper[3] > 0) {
		oper[3]--;
		insert(idx + 1, res / numArr[idx]);
		oper[3]++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) 
		cin >> numArr[i]; 
	
	for (int i = 0; i < 4; ++i) 
		cin >> oper[i];
	insert(1, numArr[0]);
	cout << maxVal << "\n";
	cout << minVal << "\n";
	
	return 0;
}