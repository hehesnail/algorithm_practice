#include <iostream>
#include <algorithm>
#include <queue>

#define MAX 101
int H[MAX][MAX];
int L[MAX][MAX];
int R, C;

using namespace std;

bool noMove(int i, int j) {
    if (i+1 <= R && H[i+1][j] < H[i][j]) return false;
    if (i-1 >= 1 && H[i-1][j] < H[i][j]) return false;
    if (j+1 <= C && H[i][j+1] < H[i][j]) return false;
    if (j-1 >= 1 && H[i][j-1] < H[i][j]) return false;

    return true;
}

struct Pos {
    int i;
    int j;
    int h;

    Pos(int ii=0, int jj=0, int hh=0):i(ii), j(jj), h(hh) {} 
    bool operator < (const Pos &that) const {
        return h > that.h;
    }
};


int main() {

    cin >> R >> C;
    priority_queue<Pos> q;

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> H[i][j];
            q.push(Pos(i, j, H[i][j]));
        }
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            L[i][j] = 1;
        }
    }

    Pos p;
    while(!q.empty()) {
        p = q.top();
        q.pop();
        int i = p.i, j = p.j, h = p.h;
        if (noMove(i, j))
            L[i][j] = 1;
        else {
            int temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0;
            if (i+1 <= R && H[i+1][j] < H[i][j])
                temp1 = L[i+1][j];

            if (i-1 >= 1 && H[i-1][j] < H[i][j])
                temp2 = L[i-1][j];

            if (j+1 <= C && H[i][j+1] < H[i][j])
                temp3 = L[i][j+1];

            if (j-1 >= 1 && H[i][j-1] < H[i][j])
                temp4 = L[i][j-1];
            L[i][j] = max(max(max(temp1, temp2), temp3), temp4) + 1;
        }
    }

    int maxL = 0;
    
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (L[i][j] > maxL)
                maxL = L[i][j];
        }
    }

    cout << maxL << endl;

    return 0;
}
