#include <iostream>
#include <vector>

using namespace std;

// 6603 - 로또 22min

int k;
vector<int> _set;
void getLotto(int idx, vector<int> set) {
	if (set.size() == 6) {
		for (int i = 0; i < set.size(); ++i) {
			cout << set[i] << " ";
		}
		cout << "\n";
	}
	
	for (int i = idx; i < _set.size(); ++i) {
		set.push_back(_set[i]);
		getLotto(i + 1, set);
		set.pop_back();
	} 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (true) {
		cin >> k;
		if (k == 0) break;

		_set.clear();
		_set.resize(k);
		for (int i = 0; i < k; ++i) {
			cin >> _set[i];
		}
		vector<int> empty;
		getLotto(0, empty); 
		cout << "\n";
	}

	return 0;
}
