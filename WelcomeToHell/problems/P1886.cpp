//单调队列模板，求滑动窗口的最大值和最小值，单调队列核心：当发现不单调时，弹出队尾元素直到单调为止
#include <iostream>
#include <deque>
using namespace std;
int n, k;
int ele[1000005];
int main() {
	cin >> n >> k;
	deque<int> q;
	for (int i = 0; i < n;i++) {
		cin >> ele[i];
	}
	for (int i = 0; i < n;i++) {
		while (!q.empty() && ele[q.back()]>ele[i]) {
			q.pop_back();
		}
		while (!q.empty()&&q.front()<=i-k) {
			q.pop_front();
		}
		q.push_back(i);
		if (i >= k-1) {
			cout << ele[q.front()] << " ";
		}
	}
	q.clear();
	cout << endl;
	for (int i = 0; i < n; i++) {
		while (!q.empty() && ele[q.back()] < ele[i]) {
			q.pop_back();
		}
		while (!q.empty() && q.front() <= i - k) {
			q.pop_front();
		}
		q.push_back(i);
		if (i >= k - 1) {
			cout << ele[q.front()] << " ";
		}
	}
	return 0;
}