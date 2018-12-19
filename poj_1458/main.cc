/*
dp LCS
maxLen(i,j) 表示a左边i个字符和b左边j个字符之间的最长公共子序列
maxLen(len1, len2)
初始状态 maxLen(0, n) = 0, maxLen(n, 0) = 0
状态转移方程
maxLen(i,j)
左边i个字符对应字符串下标为i-1
if (a[i-1] == b[j-1]) maxLen(i,j) = maxLen(i-1, j-1) + 1
else 
   maxLen(i,j) = max(maxLen(i, j-1), maxLen(i-1, j))
*/

#include <iostream>
#include <cstring>

using namespace std;

#define MAX 1001

int maxLen[MAX][MAX];

int main() {

	string a, b;
	while (cin >> a >> b) {
		int len1 = a.length(), len2 = b.length();
		memset(maxLen, 0, sizeof(maxLen));
		
		for (int i = 0; i <= len1; i++)
			maxLen[i][0] = 0;
		for (int j = 0; j <= len2; j++)
			maxLen[0][j] = 0;

		for (int i = 1; i <= len1; i++) {
			for (int j = 1; j <= len2; j++) {
				if (a[i-1] == b[j-1])
					maxLen[i][j] = maxLen[i-1][j-1] + 1;
				else {
					maxLen[i][j] = max(maxLen[i][j-1], maxLen[i-1][j]);
				}
			}
		}

		cout << maxLen[len1][len2] << endl;
	}

	return 0;
}
