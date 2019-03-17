#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

#define MAX_V 1001
#define MAX_E 20000+1

#define INF 1000

using namespace std;

typedef pair<int, int> P;

struct edge {
	int to, cost;
	edge(int a, int b): to(a), cost(b) { }
};

int N, M;
vector<edge> G[MAX_V];
int min_cost[MAX_V];
bool used[MAX_V];

int prim(int s) {
	int res = 0;
	priority_queue<P, vector<P>, greater<P> > que;
	
	fill(min_cost, min_cost+N, INF);
	
	min_cost[s] = 0;
	que.push(P(min_cost[s], s));

	while(!que.empty()) {
		P p = que.top();
		que.pop();
		int v = p.second;
		if (used[v])
			continue;

		used[v] = true;
		res += min_cost[v];

		for (int i = 0; i < G[v].size(); i++) {
			edge e = G[v][i];
			if (min_cost[e.to] > e.cost) {
				min_cost[e.to] = e.cost;
				que.push(P(min_cost[e.to], e.to));
			}
		}
	}

	return res;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		x--, y--;

		G[x].push_back(edge(y, -c));
		G[y].push_back(edge(x, -c));
	}

	int low_cost = -prim(0);

	bool flag = false;
	for (int i = 0; i < N; i++) {
		if (!used[i])
			flag = true;
	}

	if (flag)
		cout << "-1" << endl;
	else 
		cout << low_cost << endl;

	return 0;
}