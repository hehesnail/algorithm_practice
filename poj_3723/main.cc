#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>

#define MAX_V 20000
#define MAX_E 50000
#define INF 1000

using namespace std;

typedef pair<int, int> P; //first, cost of node, secode node v

struct edge {
	int to, cost;
	edge(int a = 0, int b = 0): to(a), cost(b) { }
};


vector<edge> G[MAX_V];
int min_cost[MAX_V];
bool used[MAX_V];
int N, M, R;

int prim(int s) {
	int res = 0;
	priority_queue<P, vector<P>, greater<P> > que;
	fill(min_cost, min_cost+N+M, INF);

	min_cost[s] = 0;
	que.push(P(min_cost[s], s));

	while(!que.empty()) {
		P p = que.top();
		que.pop();

		//add the next vertex to mst
		int v = p.second;
		if (used[v])
			continue;

		used[v] = true;
		res += min_cost[v];

		for(int i = 0; i < G[v].size(); i++) {
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

	
	int t;
	cin >> t;
	while (t--) {
		cin >> N >> M >> R;
		fill(used, used+N+M, false);
		for (int i = 0; i < R; i++) {
			int x, y, d;
			scanf("%d %d %d", &x, &y, &d);
			y = y + N;
			G[x].push_back(edge(y, -d));
			G[y].push_back(edge(x, -d));
		}

		int cost = 0;
		for (int i = 0; i < N+M; i++) {
			if (!used[i]) {
				cost += prim(i);

			}
		}

		for (int i = 0; i < N+M; i++) {
			G[i].clear();
		}

		cout << 10000*(N+M) + cost << endl;
	}

	return 0;
}