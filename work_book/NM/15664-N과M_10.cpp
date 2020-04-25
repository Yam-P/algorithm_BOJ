#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 15664 - N과 M (10)
	
int N, M;
vector<int> seqIn;

void solve(vector<int> seq, int idx, int visited) {
	if (seq.size() == M) {
		for (int i = 0; i < seq.size(); ++i) {
			cout << seq[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int next = idx; next < N; ++next) {
		if (visited & (1 << next)) continue;
		if (next == 0 || seqIn[next - 1] != seqIn[next] || visited & (1 << next - 1)) {
			seq.push_back(seqIn[next]);
			solve(seq, next, visited | (1 << next));
			seq.pop_back();
		}
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
	solve(_seq, 0, 0);

	return 0;
}
