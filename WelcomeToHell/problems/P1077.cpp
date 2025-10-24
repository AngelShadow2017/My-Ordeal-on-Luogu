#include <iostream>
using namespace std;
int a[101];
int dp[101][101];
int n, m;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[0][0] = 1;
	//dp[i][j] = sum(dp[i-1][j-0~a[i]])
	for (int i = 1; i <= n;i++) {
		for (int j = 0; j <= m;j++) {
			for (int item = 0; item <= a[i];item++) {
				if (j - item < 0) {
					break;
				}
				dp[i][j] += dp[i - 1][j - item];
				dp[i][j] %= 1000007;
			}
		}
	}
	/*for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<< dp[n][m];
	return 0;
}