#include <iostream>
using namespace std;
int n, m;
int a[105];
int prefixSum[105];
int dp[105][105][15];
int dpmin[105][105][15];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i + n] = a[i];
	}
	for (int i = 1; i <= 2*n; i++) {
		prefixSum[i] = prefixSum[i - 1] + a[i];
	}
	for (int i = 1; i <= 2 * n; i++) {
		for (int j = i;  j <= 2 * n; j++) {
			for (int d = 1; d <= m;d++) {
				dpmin[i][j][d] = 16384;
			}
		}
	}
	for (int i = 1; i <= 2*n;i++) {
		for (int j = i; j < i+n&&j<=2*n;j++) {
			dpmin[i][j][1]=dp[i][j][1] = (((prefixSum[j] - prefixSum[i - 1])%10)+10)%10;
		}
	}
	for (int duan = 2; duan <= m;duan++) {
		for (int i = 1; i < n; i++) {
			for (int j = 1; j + i <= 2 * n;j++) {
				for (int k = 0; k < i;k++) {
					int head = j;
					int mid = j + k + 1;
					int end = j + i;
					for (int p = 1; p < duan; p++) {
						dpmin[j][j + i][duan] = min(dpmin[j][j + i][duan], dpmin[head][mid - 1][p] * dpmin[mid][end][duan - p]);
						dp[j][j + i][duan] = max(dp[j][j + i][duan], dp[head][mid - 1][p] * dp[mid][end][duan - p]);
					}
				}
			}
		}
	}
	/*for (int duan = 1; duan <= m; duan++) {
		cout << "duan="<<duan<<"------" << endl;
		for (int i = 1; i <= 2 * n;i++) {
			for (int j = 1; j <= 2 * n;j++) {
				cout << dpmin[i][j][duan] << " ";
			}
			cout << endl;
		}
	}*/
	int maxN=0, minN = 1e9;
	for (int i = 1; i <= n;i++) {
		maxN = max(maxN, dp[i][i + n - 1][m]);
		minN = min(minN, dpmin[i][i + n - 1][m]);
	}
	cout << minN << endl;
	cout << maxN << endl;
	//dp[i][j][m] --> i到j分成m段的最大值
	//
	return 0;
}