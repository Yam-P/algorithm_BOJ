#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 15655 - N과 M (6)
	
int N, M;
vector<int> seqIn;

void solve(vector<int> seq, int idx) {
	if (seq.size() == M) {
		for (int i = 0; i < seq.size(); ++i) {
			cout << seq[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int next = idx + 1; next < N; ++next) {
		seq.push_back(seqIn[next]);
		solve(seq, next);
		seq.pop_back();
	} 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	seqIn.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> seqIn[i];
	}
	sort(seqIn.begin(), seqIn.end());

	vector<int> _seq;
	solve(_seq, -1);

	return 0;
}
