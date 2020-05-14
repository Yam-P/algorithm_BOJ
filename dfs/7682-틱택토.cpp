#include <iostream>
#include <algorithm>

using namespace std;

// 7682 - 틱택토
#define NEXT_TURN(turn) ('O' + 'X' - turn)

char whoseTurn;
int preCalc(string &boardIn) {
	int ret = 0;
	int cntX = 0;
	int cntO = 0;
	for (int k = 0; k < 9; ++k) {
			ret *= 3; // shift
			if (boardIn[k] == 'X') {
				cntX++;
				ret += 1;
			}
			else if (boardIn[k] == 'O') {
				cntO++;
				ret += 2;	
			}
	}
	whoseTurn = cntX > cntO ? cntO : cntX;
	return ret;
}

bool isFinished(string &board, char turn) {
	int cnt = 0;
	for (int i = 0; i < 9; i += 3) {
		if (board[i] != turn) break;
		if (i == 2) return true;
	}
	cnt = 0;
	for (int i = 0; i < 9; i += 3) {
		if (board[i] != turn) break;
		
	}

	return false;
}

int canWin(string &board, char turn) {
	// 상대 턴에 세줄을 모두 채운 경우 
	if (isFinished(board, NEXT_TURN(turn)) return -1;
	
	int minVal = 2;
	for (int i = 0; i < 9; ++i) {
		if (board[i] == '.') {
			board[i] = turn;
			ret = min(ret, canWin(board, NEXT_TURN(turn));
			board[i] = '.';
		}
	}

	if (minVal == 2 || minVal == 0) return ret = 0;

	return ret = -minVal;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	string boardIn;
	cin >> boardIn;
	int board;
	int boardCvt = preCalc(boardIn);
	
	int res = canWin(board, whoseTurn);
	
	

	return 0;
}
