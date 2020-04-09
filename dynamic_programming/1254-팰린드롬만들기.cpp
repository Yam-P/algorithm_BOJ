#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// 1254 - 팰린드롬 만들기 37min

bool check(string str) {
	for (int i = 0; i < str.size() / 2; ++i) {
		if (str[i] == str[str.size() - 1 - i]) continue;
		return false;
	}
	return true;
}

int palindrome(string S) {
	string concatStr = S;
	string revStr = S;
	reverse(revStr.begin(), revStr.end());
	int ret = 0;
	for (int i = 0; i <= revStr.size(); ++i) {
		if (check(concatStr + revStr.substr(i))) {
			ret = (concatStr + revStr.substr(i)).size();
		}		
	}
	return ret;	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	cout << palindrome(s) << "\n";

	return 0;
}
