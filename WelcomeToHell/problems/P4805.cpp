//合并饭团
//区间dp分三段的dp
//去掉break就是真正的三段合并的dp
//此题特殊，有解就一定是最大值
#include <iostream>
using namespace std;
int n;
int a[405];
long long dp[405][405];
long long minmin = -2147483647;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = minmin;
		}
		cin >> a[i];
	}
	for (int i = 1; i <= n;i++) {
		dp[i][i] = a[i];
	}
	for (int i = 1; i < n;i++) {
		for (int j = 1; j+i <= n;j++) {
			for (int k = 0; k < i; k++) {
				int start = j;
				int mid = j + k;
				int end = j + i;
				/*if (j == 3 && i == 3) {
					cout << "debug: "<<k<<" " << dp[start][mid] << " " << dp[mid + 1][end] << endl;
				}*/
				if (dp[start][mid]==dp[mid+1][end]&& dp[start][mid]!=minmin) {
					dp[start][end] = max(dp[start][end],dp[start][mid] * 2);
					break;
				}
				//start~mid mid+1~third third+1~end
				for (int third = mid+1; third < end; third++) {
					//如果可以合并
					if (dp[mid+1][third] > minmin && dp[start][mid] == dp[third+1][end]) {
						dp[start][end] = max(dp[start][end], dp[start][mid] + dp[third + 1][end] + dp[mid+1][third]);
						break;
					}
				}
			}
			
		}
	}
	long long maxmax = minmin;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			//cout<< dp[i][j] << " ";
			maxmax = max(maxmax, dp[i][j]);
		}
		//cout << endl;
	}
	cout << maxmax<<endl;
	return 0;
}