/*
DFS搜索
因为一行一列只能放一个棋子，从第一行开始搜索可以放棋子的列的位置
为列设置一个标记数组记录列j是否被访问过。
搜索对应两种情况: 1). 该行会在某列放置棋子，则枚举所有列并在合法地方放置，注意需清除列标记。
				  2). 该行不放置，则搜索下一行
*/
#include <iostream>
#include <cstring>

using namespace std;

int n, k;
bool chess[8][8];
bool colUsed[8];
int ans;

void dfs(int row, int count) {

	//若放置了k个位置，则计数加1并返回，从其他地方搜索。
	if (count == k) {
		ans++;
		return;
	}

	//当前行数超过n,越界返回。
	if (row > n)
		return;

	//在row行对应的列中寻找可以放置的列,若可以放置，则标记对应的列，并向下一行接着搜索
	for (int j = 0; j < n; j++) {
		if (!colUsed[j] && chess[row][j]) {
			colUsed[j] = true;
			dfs(row+1, count+1);
			colUsed[j] = false;
		}
	}

	//搜索row行不取点的情况
	dfs(row+1, count);
	return;
}

int main() {
	while (cin >> n >> k) {

		if (n == -1 && k == -1) 
			break;
		ans = 0;
		memset(colUsed, false, sizeof(colUsed));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				char c;
				cin >> c;
				if (c == '.')
					chess[i][j] = false;
				else 
					chess[i][j] = true;
			}
		}



		dfs(0, 0);
		cout << ans << endl;
	}

	return 0;
}