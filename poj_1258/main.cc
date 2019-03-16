#include <iostream>
#include <functional>
#include <queue>
#include <algorithm>
#include <vector>

#define MAX_V 100
#define INF 100000000

using namespace std;

struct edge {
	int to, cost;
	edge(int a, int b): to(a), cost(b) { }
};

typedef pair<int, int> P;

int V;
vector<edge> G[MAX_V];
int min_cost[MAX_V];

int prim() {
	priority_queue<P, vector<P>, greater<P> > que;
	int res = 0;

	fill(min_cost, min_cost+V, INF);
	min_cost[0] = 0;
	que.push(P(min_cost[0], 0));

	while(!que.empty()) {
		P p = que.top();
		que.pop();

		int v = p.second;
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
	while(cin >> V) {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				int w;
				cin >> w;
				G[i].push_back(edge(j, w));
				G[j].push_back(edge(i, w));
			}
		}

		cout << prim() << endl;
		for (int i = 0; i < V; i++) {
			G[i].clear();
		}
	}

	return 0;
} 