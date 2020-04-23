#include <iostream>
#include <vector>

using namespace std;

// 15650 - N과 M (3)
int N, M;

void solve(vector<int> seq, int idx) {
	if (seq.size() == M) {
		for (int i = 0; i < seq.size(); ++i) {
			cout << seq[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int next = 0; next < N; ++next) {
		seq.push_back(next + 1);
		solve(seq, next);
		seq.pop_back();
	} 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	vector<int> _seq;
	solve(_seq, 0);

	return 0;
}
