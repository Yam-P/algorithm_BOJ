#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 15665 - N과 M (11)
	
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

	for (int next = 0; next < seqIn.size(); ++next) {
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
	seqIn.erase(unique(seqIn.begin(), seqIn.end()), seqIn.end());

	vector<int> _seq;
	solve(_seq, 0);

	return 0;
}
