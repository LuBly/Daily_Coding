//[Baekjoon C++] 트리 [dfs] 17 15 ~
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;
/*
기존 tree에서 leef노드 수 계산
삭제하면서 사라지는 leef노드 수 계산

두 값 minus
*/
int leaf = 0;
int deleteNode;

int dfs(int node) {
	if (node == deleteNode) return -1;
	if (!tree[node].size()) {
		leaf++;
		return 0 ;
	}
	for (int k = 0; k < tree[node].size(); k++) {
		int tmp = dfs(tree[node][k]);
        // 부모의 유일한 자식이었다면, 부모노드가 리프노드가 되므로 리프 노드를 하나 증가시켜줘야한다.
		if (tmp == -1 && tree[node].size() == 1)
			leaf++;
	}
	return 0;
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int nodeCnt;
    cin >> nodeCnt;
    tree.resize(nodeCnt);

    int rootNode;
    for(int k = 0; k < nodeCnt; k++){
        int from;
        cin >> from;
        if(from == -1) 
            rootNode = k;
        else
            tree[from].push_back(k);
    }
    cin >> deleteNode;
    dfs(rootNode);
    cout << leaf;
}