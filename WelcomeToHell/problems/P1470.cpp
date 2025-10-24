#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct Node {
    char c;
    Node* next[26];
	bool isWord = false;
    Node()
        : c(0)
    {
        for (int i = 0; i < 26; ++i)
            next[i] = NULL;
    }
};

// root can be file-scope or a static member as needed
Node root;
int dp[200001];
void appendStr(string& str) {
    Node* p = &root;
    int siz = str.size();
	//反过来插入字典树，因为要按后缀匹配
    for (int i = siz-1; i >= 0; --i) {
        char ch = str[i];
        int index = ch - 'A';
        if (index < 0 || index >= 26)
            continue; // ignore non A-Z characters; adjust policy if needed

        if (p->next[index] == NULL) {
            p->next[index] = new Node();
            p->next[index]->c = ch;
        }
        p = p->next[index];
    }
	p->isWord = true;
}
bool findTo(int cur,int target,Node& node,string& str,int depth = 0){
    if (depth > 10||cur<0) {
        return false;
    }
    int index = str[cur] - 'A';
    if(node.next[index]!=NULL){
        if (cur <= target+1 && node.next[index]->isWord) {
            return true;
        }
        return findTo(cur-1,target,*node.next[index],str,depth+1);
    }
    else {
        return false;
    }
}
bool matchBackward(int pos,int target, const string& s) {
    Node* p = &root;
    // 最长单词长度 <= 10
    for (int d = 0; d <= 10 && pos - d >= 0; ++d) {
        int idx = s[pos - d] - 'A';
        if (idx < 0 || idx >= 26) return false;
        p = p->next[idx];
        if (p==NULL) return false;
        if (p->isWord) {
            int start = pos - d; // 单词起始位置 (0-based)
            if (start<=target) return true; // dp[start] 表示前 start 个字符可拆分
        }
    }
    return false;
}
int main() {
	string tmp;
	int index = 0;
	do {
		cin >> tmp;
		if (tmp[0] != '.') {
            //cout << tmp << endl;
			appendStr(tmp);
		}
	} while (tmp[0]!='.');
    string model;
    /*while (getline(cin, tmp)) {
        model += tmp;
    }*/
    getline(cin, tmp); // 吃掉当前行剩余的换行
    while (getline(cin, tmp)) {
        if (!tmp.empty() && tmp.back() == '\r') tmp.pop_back();
        model += tmp;
    }
	int modelLen = model.size();
    if(root.next[model[0]-'A']!=NULL){
		dp[0] = 0;
    }
    else {
        dp[0] = -1;
    }
    for (int i = 1; i < modelLen;i++) {
        if (matchBackward(i,dp[i-1]+1, model)) {
            dp[i] = i;
        }
        else {
			dp[i] = dp[i - 1];
        }
    }
	cout << dp[modelLen - 1]+1;
	return 0;
}
