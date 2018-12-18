/*
dp
解法同poj 1163
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
