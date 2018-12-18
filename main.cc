#include <iostream>

using namespace std;

#define MAXN 101
#define MAXM 101

int D[MAXN][MAXM];
bool marked[MAXN][MAXM];

int main() {

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) 
            cin >> D[i][j];
    }

    int count = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <=M; j++) {
            if (!marked[i][j]) {
                dfs(i, j);
                count++;
            }
        }
    }


    return 0;
}
