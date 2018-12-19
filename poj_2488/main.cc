/*
dfs + 回溯
dfs遍历问题，要注意字典序，即每次knight移动时的顺序。
需回溯，当访问到某一点无法继续访问，且此时step数没有达到棋盘总数（即未访问到所有点）的时候，
应将对应访问标记重置，返回到上一步重新遍历。
*/
#include <iostream>
#include <cstring>

using namespace std;

struct Step{
	char x;
	char y;
} path[27];

bool visited[27][27];
int p,q;
bool success;

struct direction {
	int dx;
	int dy;
};

//direction d[8] = {{-1, 2}, {1, 2}, {2, -1}, {2, 1}, {-2, 1}, {-2, -1}, {1, -2}, {-1, -2}};
direction d[8] = {{-2,-1}, {-2,1}, {-1,-2}, {-1,2}, {1,-2}, {1,2}, {2,-1}, {2,1}};

void dfs(int x, int y, int step) {
	path[step].x = x + 'A' - 1;
	path[step].y = y + '0';

	visited[x][y] = true;

	if (step == p*q) {
		success = true;
		return;
	}

	for (int i = 0; i < 8; i++) {
		int nx = x + d[i].dx;
		int ny = y + d[i].dy;

		if (nx >= 1 && nx <= q && ny >= 1 && ny <= p && !visited[nx][ny] && !success) {
			dfs(nx, ny, step+1);
		}
	}
	visited[x][y] = false;
}

int main() {

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> p >> q;
		memset(visited, false, sizeof(visited));
		success =false;

		dfs(1,1,1);

		if (!success) {
			cout << "Scenario " << "#" << i << ":" << endl;
			cout << "impossible" << endl;
		} else {
			cout << "Scenario " << "#" << i << ":" << endl;
			for (int j = 1; j <= p*q; j++)
				cout << path[j].x << path[j].y;
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}