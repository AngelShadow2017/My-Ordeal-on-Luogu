#include <iostream>
using namespace std;
int dp[1001][1001];
int max(int a, int b) {
	return a > b ? a : b;
}
int min(int a, int b) {
	return a < b ? a : b;
}
int main() {
	string str;
	cin >> str;
	int strsize = str.size();
	for (int i = 0; i < strsize;i++) {
		//dp[i][j]-->dp[我前n个][逆序前n个]
		if (str[strsize-1] == str[i]) {
			dp[i][0] = 1;
		}
		dp[i][0] = max(dp[i][0], i > 0 ? dp[i - 1][0] : 0);
	}
	for (int i = 0; i < strsize; i++) {
		if (str[0] == str[strsize-i-1]) {
			dp[0][i] = 1;
		}
		dp[0][i] = max(dp[0][i], i > 0 ? dp[0][i - 1] : 0);
	}
	for (int i = 1; i < strsize;i++) {
		int strAIndex = i;
		for (int j = 1; j < strsize; j++) {
			int strBIndex = strsize - j - 1;
			if(str[strAIndex]==str[strBIndex]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << strsize-dp[strsize - 1][strsize - 1];
	return 0;
}