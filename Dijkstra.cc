#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <algorithm>

#define MAX_V 100
#define INF 1000000

using namespace std;

typedef pair<int,int> P;

struct edge {
	int to, cost;
	edge(int a = 0, int b = 0): to(a), cost(b) { } 
};

int V;
vector<edge> G[MAX_V];
int d[MAX_V];
int pre[MAX_V];

void dijkstra(int s) {
	priority_queue<P, vector<P>, greater<P>> que;
	fill(d, d+V, INF);
	fill(pre, pre+V, -1);

	d[s] = 0;
	que.push(P(0, s));

	while(!que.empty()) {
		P p = que.top();
		que.pop();
		int v = p.second;
		if (d[v] < p.first) continue;
		for (int i = 0; i < G[v].size(); i++) {
			int u = G[v][i].to;
			int cost = G[v][i].cost;

			if (d[u] > d[v] + cost) {
				d[u] = d[v] + cost;
				pre[u] = v;
				que.push(P(d[u], u));
			}
		}
	}

	for (int i = 0; i < V; i++) {
		cout << i << " distance: " << d[i] << endl;
		for (int j = i; j != 0; j = pre[j]) {
			cout << j << "<-";
		}
		cout << "0" << endl;
	}
}

int main () {
	V = 7;
	vector<edge> es;
	es.push_back(edge(1, 2));
	es.push_back(edge(2, 5));
	G[0] = es;
	es.clear();

	es.push_back(edge(0, 2));
	es.push_back(edge(2, 4));
	es.push_back(edge(3, 6));
	es.push_back(edge(4, 10));
	G[1] = es;
	es.clear();
	
	es.push_back(edge(0, 5));
	es.push_back(edge(1, 4));
	es.push_back(edge(3, 2));
	G[2] = es;
	es.clear();

	es.push_back(edge(2, 2));
	es.push_back(edge(1, 6));
	es.push_back(edge(5, 1));
	G[3] = es;
	es.clear();

	es.push_back(edge(2, 10));
	es.push_back(edge(5, 3));
	es.push_back(edge(6, 5));
	G[4] = es;
	es.clear();

	es.push_back(edge(3, 1));
	es.push_back(edge(4, 3));
	es.push_back(edge(6, 9));
	G[5] = es;
	es.clear();

	es.push_back(edge(4, 5));
	es.push_back(edge(5, 9));
	G[6] = es;
	es.clear();

	dijkstra(0);

	return 0;
}