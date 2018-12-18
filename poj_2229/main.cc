/*
dp

关键在于找到规律
L(i)保存数字i有多少种分解方法, i=1时 L(i)=1为初始状态.
递推方程为: 当L(i)为奇数时,此时i相对于i-1仅是所有情况+1, 所以L(i)=L(i-1).
           当L(i)为偶数是,此时i相对于i-1除去+1的情形之外,还多了i/2对应的情形(均乘以2), L(i)=L(i-1)+L(i/2)
*/
#include <iostream>

using namespace std;

#define M 1000000000
#define N 1000000+1
int L[N];

int main() {

    int n;
    cin >> n;
    L[1] = 1;

    for (int i = 2; i <= n; i++) {
        L[i] = (i % 2 ? L[i-1] : L[i-1]+L[i/2]) % M;
    }

    cout << L[n] << endl;

    return 0;
}
