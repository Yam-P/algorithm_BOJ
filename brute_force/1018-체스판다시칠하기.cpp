#include <iostream>
#include <vector>
#include <cstring>
#include <string.h>

using namespace std;

// 1018 - 체스판 다시 칠하기
int N, M;

int begWhite(vector<string> &bigBoard, int y, int x) {
	int cnt = 0;
	char next = 'W';
	char turn = 'W' + 'B';
	for (int j = 0; j < 8; ++j) {
		for (int i = 0; i < 8; ++i) {
			turn = turn - next;
			next = turn; 
			if (bigBoard[y + j][x + i] == 'turn') cnt++;
		}
	}
}

void getBoard(vector<string> &bigBoard) {
	for (int y = 0; y + 7 < N; ++y) {
		for (int x = 0; x + 7 < M; ++x) {
			begWhite(bigBoard, y, x);	
		}
	} 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
	vector<string> bigBoard;
	for (int i = 0; i < N; ++i) {
		cin >> bigBoard[i];
	}

	getBoard(bigBoard);	

    return 0;
}
