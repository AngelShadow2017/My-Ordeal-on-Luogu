#include <iostream>
using namespace std;
int arr[100005];
int dp[100005];
int len = 0;
int main() {
	int k;
	while (cin >> k) {
		if (k == 0) {
			break;
		}
		arr[++len] = k;
	}
	int cnt = 1,maxx=0;
	for (int i = 1; i <= len;i++) {
		dp[i] = 1;
		for (int k = 1; k < i;k++) {
			if (arr[k] < arr[i]) {
				continue;
			}
			if(dp[i]<dp[k]+1){
				dp[i] = dp[k] + 1;
			}
		}
		maxx = max(maxx, dp[i]);
	}
	for (int i = 1; i <= len; i++) {
		dp[i] = 1;
		for (int k = 1; k < i; k++) {
			if (arr[k] >= arr[i]) {
				continue;
			}
			if (dp[i] < dp[k] + 1) {
				dp[i] = dp[k] + 1;
			}
		}
		cnt = max(cnt, dp[i]);
	}
	cout << maxx << endl<< cnt;
	return 0;
}