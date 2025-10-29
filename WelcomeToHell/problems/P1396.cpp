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
int n, m,s,t;
long long totalLen = 0;
int dsu[10005];
int find(int x) {
	if (dsu[x] != x) {
		dsu[x] = find(dsu[x]);
	}
	return dsu[x];
}
int unite(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx != fy) {
		dsu[fx] = fy;
		return 1;
	}
	return 0;
}
int main() {
	for (int i = 1; i <= 10005; i++) {
		dsu[i] = i;
	}
	cin >> n >> m>>s>>t;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		pq.push({ u,v,w });
	}
	int minMax = 0;
	while (!pq.empty()) {
		Edge tmp = pq.top();
		if (unite(tmp.from, tmp.to)) {
			minMax = tmp.len;
		}
		pq.pop();
		if(find(s)==find(t)){
			break;
		}
	}
	cout << minMax << endl;
	return 0;
}