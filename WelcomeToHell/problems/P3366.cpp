/// Kruskal's algorithm to find the Minimum Spanning Tree (MST) of a graph
#include <iostream>
#include <queue>
using namespace std;
struct Edge {
	int from, to, len;
};
bool operator <(const Edge& a, const Edge& b) {
	return a.len > b.len;
}
priority_queue<Edge> pq;
int n, m;
long long totalLen = 0;
int dsu[5005];
int find(int x) {
	if (dsu[x] != x) {
		dsu[x] = find(dsu[x]);
	}
	return dsu[x];
}
int unite(int x,int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx != fy) {
		dsu[fx] = fy;
		return 1;
	}
	return 0;
}
int main() {
	for (int i = 1; i <= 5005;i++) {
		dsu[i] = i;
	}
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		pq.push({ u,v,w });
	}
	int used = 0;
	while (!pq.empty()) {
		if (used == n - 1) {
			break;
		}
		Edge tmp = pq.top();
		if(unite(tmp.from,tmp.to)){
			totalLen += tmp.len;
			used++;
		}
		pq.pop();
	}
	if (used != n - 1) {
		cout << "orz" << endl;
	}
	else {
		cout << totalLen << endl;
	}
	return 0;
}