#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FOR(i, n) for(int i = 0; i < n; ++i)

// 2309 - 일곱난쟁이 33min 
int N;
int height[10];
vector<int> chosenDwarfs;

int getSize(int set) {
	if (set == 0) return 0;
	return set % 2 + getSize(set / 2);
}

bool pick(int idx, int sum, int chosen) {
	if (getSize(chosen) == 7) {
		if(sum == 100) return true;
		else return false;
	}

	bool ret = false;
	for (int i = idx + 1; i <= 9; ++i) {
		if (chosen & (1 << i) != 0) continue;
		
		chosenDwarfs.push_back(height[i]);
		ret = pick(i, sum + height[i], chosen | 1 << i); 
		if (ret) break;
		chosenDwarfs.pop_back();
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 1; i <= 9; ++i) {
		cin >> height[i];
	}
	pick(0, 0, 0);
	sort(chosenDwarfs.begin(), chosenDwarfs.end());
	for (int i = 0; i < chosenDwarfs.size(); ++i) {
		cout << chosenDwarfs[i] << "\n";
	}	
	
	return 0;
}
