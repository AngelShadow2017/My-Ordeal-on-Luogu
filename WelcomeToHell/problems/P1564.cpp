#include <iostream>
#include <cstring>
using namespace std;
int dp[2505];
int type[2505];
int n, m;
int main() {
	memset(dp, 0x3f, sizeof(dp));
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> type[i];
		type[i]--;
		type[i] += type[i - 1];
	}
	dp[0] = 0;
	dp[1] = 1;
	//没有人的时候那肯定是0组
	{
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < j;k++) {
				//尝试把k+1到j合并成一组，则(type[j] - type[k])>i?1:0
				int delta = (type[j] - type[k]);//有这么多个人选了第二组
				delta = abs((j - k) - 2*delta);//人数差
				//cout <<"(" << delta << ", " << i << ") ";
				if(delta<=m||delta==j-k){
					dp[j] = min(dp[j], dp[k] + 1);//把k+1~j合成一组分配一个教室
				}
			}
			//cout << endl;
		}
	}
	cout << dp[n];
	return 0;
}