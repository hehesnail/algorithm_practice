/*
dfs
*/
#include <iostream>

#define MAXW 20
#define MAXH 20

using namespace std;

int W, H;
char room[MAXH][MAXW];
bool visited[MAXH][MAXW];
int count;
struct point{
	int x;
	int y;
};
point di[4] = {{-1, 0}, {1, 0}, {0, -1}, {0,1}};

void dfs(int x, int y) {
	count++;
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + di[i].x;
		int ny = y + di[i].y;

		if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && room[nx][ny] == '.') {
			dfs(nx, ny);
		}
	}
}

int main() {

	while(cin >> W >> H) {
		if (W == 0 && H == 0)
			break;
		int start_x, start_y;
		count  = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> room[i][j];
				visited[i][j] = false;
				if (room[i][j] == '@') {
					start_x = i;
					start_y = j;
				}
			}
		}

		dfs(start_x, start_y);
		cout << count << endl; 
	}

	return 0;
}