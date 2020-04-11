#include <iostream>
#include <cstring>

using namespace std;

// 2602 - 돌다리 건너기
string roll;
string bridge[2];
// rollIdx, y, x
int cache[21][2][101];

int pass (int rollIdx, int y, int x) {
	if (rollIdx == roll.size()) return 1;	
	if (x >= bridge[0].size() || x >= bridge[1].size()) return 0;

	int &ret = cache[rollIdx][y][x];
	if (ret != -1) {
		//printf("repeated case\n");
		return ret;
	}

	ret = 0;
	if(bridge[y][x] == roll[rollIdx]) {
		ret += pass(rollIdx + 1, (y + 1) % 2, x + 1);
	}
	ret += pass(rollIdx, y, x + 1);

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> roll >> bridge[0] >> bridge[1];
	memset(cache, -1, sizeof(cache));
	cout << pass(0, 0, 0) + pass(0, 1, 0) << "\n";
	
	return 0;
}
