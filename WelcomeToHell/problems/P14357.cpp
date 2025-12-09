#include<iostream>
using namespace std;
int num[10];
char out[1000005];
int main() {
	string s;
	cin >> s;
	int si = s.size();
	for (int i = 0; i < si;i++) {
		if (s[i]-'0'<=9&&s[i]-'0'>=0) {
			num[s[i] - '0']++;
		}
	}
	int k = 9;
	int ind = 0;
	while(k>=0) {
		while (num[k] > 0) {
			out[ind++] = k + '0';
			num[k]--;
		}
		k--;
	}
	cout << out << endl;
	return 0;
}