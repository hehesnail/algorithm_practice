#include <iostream>
#include <queue>
#include <vector>
#include <functional>

#define MAX_V 1005
#define INF 100000000

using namespace std;

typedef pair<int, int> P;

struct edge {
	int to, cost;
	edge(int a = 0, int b = 0): to(a), cost(b) { }
};

vector<edge> G[MAX_V];
int dist[MAX_V];

int N, M, X; //V, E, dest

void dijkstra(int s) {
	fill(dist, dist+N, INF);
	dist[s] = 0;

	priority_queue<P, vector<P>, greater<P> > que;
	que.push(P(0, s));

	while(!que.empty()) {
		P p = que.top();
		que.pop();
		int v = p.second, d = p.first;
		for (int i = 0; i < G[v].size(); i++) {
			edge& e = G[v][i];
			if (dist[e.to] > d + e.cost) {
				dist[e.to] = d + e.cost;
				que.push(P(dist[e.to], e.to));
			}
		}
	}
}

int main() {
	cin >> N >> M >> X;
	X--;
	for (int i = 0; i < M; i++) {
		int s, e, t;
		cin >> s >> e >> t;
		s--, e--;
		G[s].push_back(edge(e, t));
	}

	vector<int> dto;
	for (int i = 0; i < N; i++) {
		dijkstra(i);
		dto.push_back(dist[X]);
	}

	dijkstra(X);
	int d_max = 0;
	for (int i = 0; i < N; i++) {
		d_max = max(dto[i] + dist[i], d_max);
	}

	cout << d_max << endl;

	return 0;
}