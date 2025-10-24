#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, a[505][505];
int visitOrder[505];
bool visited[505][505];
int tmp[1006];
vector<int> edges[505];
struct Node {
	int r;
	int c;
};
int direct[] = { -1,0,1,0,0,-1,0,1 };
void merge(int arr[],int index[], int left, int right,int mid) {
	int i = left, j = mid + 1, k = left;
	while (i <= mid && j <= right) {
		if (arr[index[i]] <= arr[index[j]]) {
			tmp[k++] = index[i++];
		}
		else {
			tmp[k++] = index[j++];
		}
	}
	while (i <= mid) {
		tmp[k++] = index[i++];
	}
	while (j <= right) {
		tmp[k++] = index[j++];
	}
	for (int p = left; p <= right; p++) {
		index[p] = tmp[p];
	}
}
void mergesort(int arr[], int index[],int left,int right) {
	int mid = (left + right) / 2;
	if (left < right) {
		mergesort(arr, index, left, mid);
		mergesort(arr, index, mid + 1, right);
		merge(arr, index,left,right,mid);
	}
}
void bfs(int starti,int startj) {
	queue<Node> q;
	q.push({ starti,startj });
	while (!q.empty()) {
		Node front = q.front();
		q.pop();
		if(visited[front.r][front.c]){
			continue;
		}
		visited[front.r][front.c] = true;
		for (int dir = 0; dir < 4; dir++) {
			int newr = front.r + direct[dir*2];
			int newc = front.c + direct[dir*2+1];
			if (newr >= 1 && newr <= n && newc >= 1 && newc <= m && !visited[newr][newc]&&
				a[newr][newc] < a[front.r][front.c]
				) {
				q.push({ newr,newc });
			}
		}
	}
}
void printArray() {
	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= m; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
	cout <<"---" << endl;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= m;i++) {
		for (int j = 1; j <= n; j++) {
			memset(visited[j], 0, sizeof(visited[j]));
		}
		bfs(1,i);
		for (int j = 1; j <= m;j++) {
			if(!visited[n][j]){
				edges[i].push_back(j);
			}
		}
	}


	if (false) {

		for (int i = 1; i <= m; i++) {
			visitOrder[i] = i;
		}
		int DesertYou = 0, LetYouDown = 0;
		mergesort(a[1], visitOrder, 1, m);
		/*for (int i = 1; i <= m; i++) {
			cout << a[1][visitOrder[i]] << " ";
		}
		cout << endl << endl;
		*/
		for (int i = 1; i <= m; i++) {
			//cout << " " << visitOrder[m - i+1]<<endl;
			if (!visited[1][visitOrder[m - i + 1]]) {
				LetYouDown++;
				bfs(1, visitOrder[m - i + 1]);
			}
			else {
				continue;
			}
			//printArray();
			DesertYou = 0;
			bool allNeverGonnaGiveUp = true;
			for (int j = 1; j <= m; j++) {
				if (!visited[n][j]) {
					allNeverGonnaGiveUp = false;
					DesertYou++;
				}
			}
			if (allNeverGonnaGiveUp) {
				cout << 1 << endl << LetYouDown;
				return 0;
			}
		}
		cout << 0 << endl << DesertYou << endl;
	}
	return 0;
}