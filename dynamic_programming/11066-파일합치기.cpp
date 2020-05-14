#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 11066 - 파일 합치기
// 참고: https://jaimemin.tistory.com/371?category=988050

int K;
bool visited[501];
const int INF = 987654321;

#if 0
int combine(vector<int> &fSize) {
	if (fSize.size() == 1) return 0;

	sort(fSize.rbegin(), fSize.rend());	
	int newVal = fSize[fSize.size() - 1] + fSize[fSize.size() - 2];
	fSize.pop_back();
	fSize.pop_back();
	fSize.push_back(newVal);

	return newVal + combine(fSize);
}
#endif

#if 0
int combine(int cur, vector<int> &fSize) {
	if (fSize.size() == 1) return 0;
	int ret = INF;
	for (int next = 0; next + 1 < fSize.size(); ++next) {
		int first = fSize[next];
		int second = fSize[next + 1];
		int sum = first + second;

		fSize.insert(fSize.begin() + next, sum);

		fSize.erase(fSize.begin() + next + 1);
		fSize.erase(fSize.begin() + next + 1);
		
		ret = min(ret, sum + combine(next, fSize));
		
		fSize.erase(fSize.begin() + next);
		fSize.insert(fSize.begin() + next, first);
		fSize.insert(fSize.begin() + next + 1, second);
	}	
	return ret;	
}
#endif



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	vector<int> _fSize(K);
	for (int i = 0; i < _fSize.size(); ++i) 
		cin >> _fSize[i]; 
	cout << combine(0, _fSize) << "\n";

	return 0;
}
