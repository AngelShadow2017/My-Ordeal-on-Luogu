#include <iostream>
using namespace std;
int n, m;
int main() {
	cin >> n >> m;
	int my;
	cin >> my;
	int greater = 0;
	int tot = n * m; int tmp;
	for (int i = 1; i < tot;i++) {
		cin >> tmp;
		if (tmp>my) {
			greater++;
		}
	}
	int num = greater % n;
	int sig = (greater / n) % 2 == 0 ? num+1 : n - num;
	cout << (greater / n + 1)<<" " << sig;
	return 0;
}