#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

#define MAX_N 300
#define INF 100000000
int N, M;
int d[MAX_N][MAX_N];

void floyd() {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			d[i][j] = INF;

	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		vector<int> pairs;
		for (int j = 0; j < num; j++) {
			int temp;
			cin >> temp;
			pairs.push_back(temp-1);
		}

		for (int k = 0; k < pairs.size(); k++) {
			for (int kk = k+1; kk < pairs.size(); kk++) {
				int nodei = pairs[k];
				int nodej = pairs[kk];
				d[nodei][nodej] = 1;
				d[nodej][nodei] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		d[i][i] = 0;
	}

	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << d[i][j] << " ";
		cout << endl;
	}
	*/

	floyd();

	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << d[i][j] << " ";
		cout << endl;
	}
	*/

	int degree = INF;
	for (int i = 0; i < N; i++) {
		double temp_d = 0;
		int count = 0;
		for (int j = 0; j < N; j++) {
			if (d[i][j] != INF && i != j) {
				count++;
				temp_d += d[i][j];
			}
		}
		temp_d = temp_d / count;
		temp_d = temp_d*100;
		degree = min((int)temp_d, degree);
	}

	cout << degree <<endl;

	return 0;
}