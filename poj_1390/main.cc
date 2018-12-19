/*
DP
此时块指的的是一段颜色相同的多个block
click_block(i,j,exlen) 指从i,j段消除后可得到的最大分数，且j右边和它颜色相同的块长度为exlen
状态转移方程:
click_block(i,j,exlen)
1. 直接消去j和exlen合并后的大块, click_block(i,j-1,0) + (len(j)+exlen)^2
2. 在j左边寻找可与j合并的块k, 消去k到j中间的块
	click_block(i,k,len(j)+exlen) + click_block(k+1, j-1, 0)
click_block = max(1., 2.)
递归求解，终止条件为i == j, 即没有多余的块
*/
#include <iostream>
#include <cstring>

using namespace std;

struct Block {
	int color;
	int len;
};

Block segments[200];
int scores[200][200][200];

int click_block(int start, int end, int exlen) {
	if (scores[start][end][exlen] > 0)
		return scores[start][end][exlen];
	int result = segments[end].len + exlen;
	result = result * result;

	if (start == end) {
		scores[start][end][exlen] = result;
		return scores[start][end][exlen];
	}

	result += click_block(start, end-1, 0);
	for (int i = end-1; i >= start; i--) {
		if (segments[i].color != segments[end].color)
			continue;
		int temp = click_block(start, i, segments[end].len+exlen) + click_block(i+1, end-1, 0);
		if (temp < result)
			continue;
		result = temp;
	}

	scores[start][end][exlen] = result;
	return scores[start][end][exlen];
}

int main() {
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		int end = 0; // number of different color block segements
		cin >> segments[end].color;
		segments[end].len = 1;
		for (int j = 1; j < n; j++) {
			int color;
			cin >> color;
			if (color == segments[end].color) segments[end].len++;
			else {
				end++;
				segments[end].color = color;
				segments[end].len = 1;
			}
		}

		memset(scores, 0, sizeof(scores));
		cout << "Case " << i+1 << ": " << click_block(0, end, 0) << endl;
	}

	return 0;
}
