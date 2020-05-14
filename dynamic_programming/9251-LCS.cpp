#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// 9251 - LCS

string strIn1, strIn2;
int cache[1001][1001];

int check(int idx1, int idx2) {
	if (strIn1[idx1] == strIn2[idx2]) return 1;
	else return 0;
}

int lcs(int idx1, int idx2) {
	if (idx1 == strIn1.size() || idx2 == strIn2.size()) 
		return 0;
	
	int &ret = cache[idx1][idx2];
	if (ret != -1) {
		//printf("repeated case!\n");
		return ret;
	}

	// 한쪽 고정시키고 다른쪽은 순회
	int case1 = lcs(idx1 + 1, idx2);
	int case2 = lcs(idx1, idx2 + 1);
	// 각 인덱스의 문자값이 같으면 1을 더하고 같지 않다면 0을 더하기.
	// 그 후 두 idx값 모두 증가시켜 다음 경우 탐사.
	int case3 = idx1 == idx2 ? lcs(idx1 + 1, idx2 + 1) + 1 : 0;

	return ret = max(max(case1, case2), case3);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	

	cin >> strIn1 >> strIn2;
	
	memset(cache, -1, sizeof(cache));
	cout << lcs(0, 0) << "\n";

	return 0;
}

#if 0
bool search(char char1, int &idx2) {
	for (int i = idx2; i < strIn2.size(); ++i) {
		if (strIn2[i] == char1) {
			idx2 = i + 1;
			return true;
		} 
	}
	return false;
}

int lcs(int idx1, int idx2) {
	if (idx1 >= strIn1.size() || idx2 >= strIn2.size()) return 0;
	
	int &ret = cache[idx1][idx2];
	if (ret != -1) {
		//	printf("repeated case!\n");
		return ret;
	}

	ret = 0;
	for (int next = idx1; next < strIn1.size(); ++next) {
		// 가지치기 strIn2에서 search 끝나면 이 외의 경우 search 중지
		if (idx2 >= strIn2.size()) break;
		// 두 수열 모두에 있는 경우
		if (search(strIn1[next], idx2))
			ret = max(ret, 1 + lcs(next + 1, idx2));		
	}

	return ret;
}
#endif
