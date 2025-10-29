#include <iostream>
using namespace std;
int n;
int a[105];
int dp[205][205];
int mod(int x) {
	if (x > n) {
		return x - n;
	}
	return x;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= 2*n-i-1;j++) {//不能到完整的第二个循环
			//cout << j << " " << j + i<<": ";
			for (int k = 0; k < i;k++) {
				int headNum = j;
				int midNum = j + k + 1;
				int endNum = j + i + 1;
				int combineEnergy = a[mod(headNum)] * (a[mod(midNum)]) * a[mod(endNum)];
				//cout <<"(" << k << "," << combineEnergy << "), ";
				dp[j][j + i] = max(dp[j][j + i], dp[j][k + j] + dp[k + j+1][j + i] + combineEnergy);
			}
			//cout << endl;
		}
	}
	int maxi = 0;
	for (int i = 1; i <= n;i++) {
		/*for (int j = 1; j <= 2 * n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;*/
		maxi = max(maxi, dp[i][i + n-1]);
		//cout << dp[i][i+n-1] << endl;
	}
	cout << maxi;
	return 0;
}
/*
几年前课上写的版本
#include <iostream>

using namespace std;
int n,a[210],dp[210][210],ans = -1;
int main()
{
	cin>>n;
	for(int i =1;i<=n;i++){
		cin>>a[i];
		a[i+n] = a[i];
	}
	for(int len = 2;len<=n;len++){
		for(int i=1;i<=2*n-len+1;i++){
			int j = i+len-1;
			for(int k =i;k<j;k++){
				dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[j+1]*a[k+1]);
				ans = max(dp[i][j],ans);
			}
		}
	}
	cout<<ans;
	return 0;
}



*/