/*
dfs
无向图连通分量
*/
#include <iostream>

using namespace std;

#define MAXN 101
#define MAXM 101

char D[MAXN][MAXM];
bool marked[MAXN][MAXM];
int N, M;

int dx[3] = {-1, 0, 1};
int dy[3] = {-1, 0, 1};

void dfs(int x, int y) {
    marked[x][y] = true;
    for (int ix = 0; ix < 3; ix++) {
        for (int iy = 0; iy < 3; iy++) {
            int xx = x + dx[ix];
            int yy = y + dy[iy];

            if (xx >= 1 && xx <= N && yy >= 1 && yy <= M && D[xx][yy] == 'W' && !marked[xx][yy]) 
                dfs(xx, yy);
        }
    }
}

int main() {

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) 
            cin >> D[i][j];
    }

    int count = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (!marked[i][j] && D[i][j] == 'W') {
                dfs(i,j);
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
