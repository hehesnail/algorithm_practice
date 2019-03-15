#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

#define MAX_V 600
#define INF 1000000000

struct edge {
	int from, to, cost;
	edge(int a=0, int b=0, int c=0): from(a), to(b), cost(c) { }
};

vector<edge> G;
int dist[MAX_V];

int F, N, M, W;

bool bellman_ford() {
	
	fill(dist, dist+N, INF);
	dist[0] = 0;
	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < G.size(); j++) {
			edge e = G[j];
			if (dist[e.to] > dist[e.from] + e.cost) {
				dist[e.to] = dist[e.from] + e.cost;

				if (i == N-1)
					return true;
			}
		}
	}

	return false;
}

int main() {
	cin >> F;
	while(F--) {
		cin >> N >> M >> W;
		for (int i = 0; i < M; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			G.push_back(edge(s-1, e-1, t));
			G.push_back(edge(e-1, s-1, t));
		}

		for (int i = 0; i < W; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			G.push_back(edge(s-1, e-1, -t));
		}

		bool travel = bellman_ford();
		G.clear();
		if (travel)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}