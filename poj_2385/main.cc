/*
dp
F[i][j]表示在第i次下落，移动了j次可以接到苹果的最大值
等于第i-1次下落,移动了j-1次(F[i-1][j-1])和第i-1次下落,移动了j次(F[i-1][j])两者的较大值
加上j次移动过后是否在对应的树下面，是则加上1否则为0
*/
#include <iostream>

using namespace std;

#define MAXT 1001
#define MAXW 31

int t[MAXT];
int F[MAXT][MAXW];

int main() {

    int T, W;
    cin >> T >> W;

    for (int i = 1; i<= T; i++)
        cin >> t[i];

    // first drop T = 1
    for (int i = 0; i <= W; i++) {
        F[1][i] = (i%2+1 == t[1]);
    }

    // along whole T drops, no move, test t[i] == 1 thus under first tree
    for (int i = 2; i <= T; i++) {
        if (t[i] == 1)
            F[i][0] = F[i-1][0] + 1;
        else 
            F[i][0] = F[i-1][0];
    }

    //F[1][0->W], F[1->T][0] initialized
    for (int i = 2; i <= T; i++) {
        for (int j = 1; j <= W; j++) {
            F[i][j] = max(F[i-1][j-1], F[i-1][j]);
            
            //if after j moves under the right tree
            if (j % 2 + 1 == t[i])
                F[i][j]++;
        }
    }

    int res = 0;
    for (int i = 0; i <= W; i++)
        res = max(res, F[T][i]);

    cout << res << endl;

    return 0;
}
