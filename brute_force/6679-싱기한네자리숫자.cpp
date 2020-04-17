#include <iostream>

using namespace std;

// 6679 - 싱기한 네자리 숫자
int mod[3] = {10, 12, 16};
bool searchNum(int num) {
	int digitSum = 0;
	int digitSumArr[3] = {0, 0, 0};
	for (int i = 0; i < 3; ++i) {
		int digit1 = num%mod[i]%mod[i]%mod[i];
		int digit2 = num/mod[i]%mod[i]%mod[i];
		int digit3 = num/mod[i]/mod[i]%mod[i];
		int digit4 = num/mod[i]/mod[i]/mod[i];
		digitSumArr[i] = digit1 + digit2 + digit3 + digit4;
	} 
	if (digitSumArr[0] == digitSumArr[1] && digitSumArr[1] == digitSumArr[2])
		return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	for (int i = 1000; i <= 9999; ++i) {
		if (searchNum(i)) {
			cout << i << "\n";
		}
	}

	return 0;
}