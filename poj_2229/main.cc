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
