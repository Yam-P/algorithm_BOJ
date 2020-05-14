#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, n) for(int i = 0; i < n; i++)
#define INF (987654321)
int N;
int dist[16][16] = { 0, };
vector<bool> visited(16, false);
vector<int> path;

int shortestDist(vector<int> &path, vector<bool> visited, int curLen) {
	int here = path.back();
	if (path.size() == N) {
		return curLen + dist[path.back()][path[0]];
	}

	int res = INF;
	FOR(next, N) {
		if (visited[next]) continue;

		path.push_back(next);
		visited[next] = true;
#if 0
		FOR(k, path.size()) {
			cout << path[k] << " ";
		}
		cout << "\n";
#endif
		int cand = shortestDist(path, visited, curLen + dist[here][next]); // return 값: curLen + dist[path.back()][path[0]]
		
		res = cand < res ? cand : res;

		// 새로운 조합으로 path.size() == n이 되기 전까지 return은 최근 완성된 최소거리값
		path.pop_back();
		visited[next] = false;
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	FOR(i, N) {
		FOR(j, N) {
			cin >> dist[i][j];
		}
	}

	path.push_back(0);
	visited[0] = true;
	cout << shortestDist(path, visited, 0) << "\n";
	
	system("pause");

	return 0;
 }
