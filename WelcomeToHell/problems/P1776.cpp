// Problem: P1776 进制优化多重背包，因为k个物品可以看成是logk(或+1)组物品，每组物品数量是2的1~logk次方+余量
//这样就可以随意组成1~k个物品的组合，于是等价于展开k个物品
#include <iostream>
using namespace std;
int v[105], w[105],m[105];
long long dp[40005];
int n, W;
int main() {
	cin >> n >> W;
	int vi, wi, mi;
	for (int i = 1; i <= n;i++) {
		cin >> vi >> wi >> mi;
		v[i] = vi;
		w[i] = wi;
		m[i] = mi;
	}
	//如果w[i]>wtmp就不能选
	//dp[wtmp][i] = max(dp[wtmp][i-1],dp[wtmp-w[i]][i-1]+v[i])
	for (int i = 1; i <= n;i++) {
		int nowLeft = m[i];
		int count = 1;
		while (nowLeft > 0) {
			if (count > nowLeft) count = nowLeft;
			//for(int k = 0;k<m[i];k++)
			long long weight = count * w[i];
			for (int j = W; j >= weight; j--) {
				dp[j] = max(dp[j], dp[j - weight] + count*v[i]);
			}
			nowLeft -= count;
			count <<= 1;
		}
	}
	cout << dp[W];
	return 0;
}