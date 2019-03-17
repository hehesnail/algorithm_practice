#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

#define MAX_V 2000+1
#define MAX_E 100000
#define INF 1000000000+100

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
	priority_queue<P, vector<P>, greater<P> > que;
	int res = -1;

	fill(min_cost, min_cost+N, INF);
	fill(used, used+N, false);

	min_cost[s] = 0;
	que.push(P(min_cost[s], s));

	while(!que.empty()) {
		P p = que.top();
		que.pop();

		int v = p.second;
		if (used[v])
			continue;
		used[v] = true;
		res = max(res, min_cost[v]);

		for (int i = 0; i < G[v].size(); i++) {
			edge &e = G[v][i];
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
		G[x].push_back(edge(y, c));
		G[y].push_back(edge(x, c));
	}

	cout << prim(0) << endl;

	return 0;
}