/*
 * simple 0/1 knaspack problem
 */
#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 3403
#define MAXM 12881

int dp[MAXM];
int w[MAXN];
int d[MAXN];

int main() {

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> d[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = M; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j-w[i]]+d[i]);
        }
    }

    /*
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;

    }
    */

    cout << dp[M] << endl;

    return 0;
}

