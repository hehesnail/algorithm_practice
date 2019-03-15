#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <climits>

using namespace std;

#define MAX_R 100000
#define MAX_N 5000
#define INF INT_MAX

struct edge {
	int to, cost;
	edge(int a = 0, int b = 0): to(a), cost(b) { }
};

typedef pair<int, int> P; //first path, second vertex 

vector<edge> G[MAX_N];
int dist[MAX_N];
int dist2[MAX_N];
int R, N;

void shortest_path() {
	priority_queue<P, vector<P>, greater<P> > que;

	//initialize the dist, dist2
	fill(dist, dist+N, INF);
	fill(dist2, dist2+N, INF);

	dist[0] = 0;
	//dist2[0] = 0;

	que.push(P(0, 0));
	while (!que.empty()) {
		P p = que.top();
		que.pop();
		int v = p.second, d = p.first;
		for (int i = 0; i < G[v].size(); i++) {
			edge e = G[v][i];
			int d2 = d + e.cost;
			if (dist[e.to] > d2) {
				swap(dist[e.to], d2);
				que.push(P(dist[e.to], e.to));
			}

			//relax the secondary sp
			if (dist2[e.to] > d2 && dist[e.to] < d2) {
				dist2[e.to] = d2;
				que.push(P(dist2[e.to], e.to));
			}
		}
	}
}

int main() {
	cin >> N >> R;

	for (int i = 0; i < R; i ++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		G[from-1].push_back(edge(to-1, cost));
		G[to-1].push_back(edge(from-1, cost));
	}

	shortest_path();

	cout << dist2[N-1] << endl;

	return 0;
}