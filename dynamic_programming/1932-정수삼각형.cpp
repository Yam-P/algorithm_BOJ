#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// 1932 - 정수 삼각형 10min
int triangle[501][501];
int cache[501][501];
int N;

int path(int y, int x) {
	if (y == N - 1) 
        return triangle[y][x];
    int &ret = cache[y][x];
    if (ret != -1)
        return ret;

    return ret = max(path(y + 1, x), path(y + 1, x + 1)) + triangle[y][x];
}


int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            cin >> triangle[i][j];

    memset(cache, -1, sizeof(cache));
    cout << path(0, 0) << endl;

    return 0;
}