#include <iostream>
#include <vector>

using namespace std;

// 1966 - 프린터 큐
int N;
vector<pair<int, int> > list;

int start = 0;
void arrange(int start, int end) {
	if (start == N) return;
	for (int i = start; i < end; ++i) {
		if (list[start].first < list[i].first) {
			list.push_back(list[start]);
			list.erase(list.begin() + start);
			i = start;
		}		
	}
	arrange(start + 1, end - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	while(T-- > 0) {
		int M;
		cin >> N >> M;
		list.clear();
		for (int i = 0; i < N; ++i) {
			int priority;
			cin >> priority;
			list.push_back(make_pair(priority, i));
		}

		arrange(0, N);
		int cnt = 1;
		for (int i = 0; i < N; ++i) {
			if (list[i].second == M) break;
			else cnt++;
		}
		cout << cnt << "\n";
	}

	return 0;
}