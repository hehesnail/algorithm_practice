#include <iostream>
#include <algorithm>

using namespace std;

#define MAXM 1001

int N, M, R;
int dp[MAXM];

struct milk {
	int s, e, v;
	milk(int _s=0, int _e=0, int _v=0):s(_s), e(_e), v(_v) {}
	bool operator < (const milk &that) const{
			return s < that.s;
	}
};

milk intervals[MAXM];

int main() {

	cin >> N >> M >> R;
	for (int i = 1; i <= M; i++) {
		cin >> intervals[i].s >> intervals[i].e >> intervals[i].v;
		intervals[i].e += R;
	}

	sort(intervals+1, intervals+M+1);

	//dp[i]表示第i个时间段产奶量的最大值
	//等于前i-1个时间段挤奶最大值的最大值 加 第i次的产奶量
	for (int i = 1; i <= M; i++) {
		dp[i] = intervals[i].v;
		for (int j = 1; j < i; j++) {
			if (intervals[i].s >= intervals[j].e) {
				dp[i] = max(dp[i], dp[j] + intervals[i].v);
			}
		}
	}

	int res = 0;
	for (int i = 1; i <= M; i++)
		res = max(res, dp[i]);

	cout << res << endl;

	return 0;
}
