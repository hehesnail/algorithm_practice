/*
动态规划

要求得从第一行到第n行数字的最大和,可用maxSum数组保存对应位置的最大和.
maxSum(i,j)为点(i,j)到第n行的最大和,临界状态为第n行的数字本身就是其最大和.
可得状态转移方程为maxSum(i,j) = max(maxSum(i+1,j), maxSum(i+1, j+1)) + D(i,j)
*/
#include <iostream>
#include <algorithm>

#define MAX 351

using namespace std;

int D[MAX][MAX];
int maxSum[MAX][MAX];

int main() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> D[i][j];
        }
    }

    //initial the starting state
    for (int i = 1; i <= n; i++) {
        maxSum[n][i] = D[n][i];
    }

    for (int i = n-1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            maxSum[i][j] = max(maxSum[i+1][j], maxSum[i+1][j+1]) + D[i][j];
        }
    }

    cout << maxSum[1][1] << endl;

    return 0;
}
