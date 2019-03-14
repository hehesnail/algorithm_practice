#include <iostream>
#include <vector>

#define MAX_E 100
#define MAX_V 100
#define INF 10000000

using namespace std;

struct edge {
	int from, to, cost;
};

edge es[MAX_E];
int d[MAX_V];
int predecessor[MAX_V];
int V, E;

void shortest_path(int s) {
	for (int i = 0; i < V; i++) 
		d[i] = INF;
	d[s] = 0;

	for (int i = 0; i < V-1; i++) {
		for (int j = 0; j < E; j++) {
			edge e = es[j];
			if (d[e.to] > d[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
				predecessor[e.to] = e.from;
			}
		}
	}

	for (int i = 0; i < V; i++) {
		cout << d[i] << endl;
		cout << i << "<-";
		for (int j = predecessor[i]; j != 0; j = predecessor[j]) {
			cout << j << "<-";
		} 
		cout << "0" << endl;
	}

	cout << endl;
}

int main() {
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> es[i].from >> es[i].to >> es[i].cost;
	}

	shortest_path(0);

	return 0;
}