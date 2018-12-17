/*
动态规划

利用L(i,j)表示从点(i,j)出发的滑行长度,由此可以得到状态方程.
若L(i,j)比周围的四个点(合法)都低的话,L(i,j)=1即从该点出发无法滑行到下一个点.
否则,L(i,j)等于周围比L(i,j)低的点中具有最大滑行长度的点的L值+1.

对所有点排序,均初始化L值为1,可利用优先队列实现.
从小到大依次求得所有点的L值,最后遍历L数组求得最大的滑行长度.
*/
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
