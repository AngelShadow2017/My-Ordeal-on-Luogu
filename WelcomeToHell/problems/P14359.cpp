#include <iostream>
using namespace std;
int pre[500005];
int dp[500005];
int n, k;
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> pre[i];
		pre[i] += pre[i - 1];
	}
	return 0;
}