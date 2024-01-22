//[Baekjoon C++] 알고리즘 수업 - 깊이 우선 탐색 1 [DFS] 14 30
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<priority_queue<int, vector<int>, greater<int>>> board;
vector<int> isVisit;
int cnt = 1;
void dfs(int start){
    isVisit[start] = cnt++;
    while(!board[start].empty()){
        int nextNode = board[start].top();
        board[start].pop();
        if(!isVisit[nextNode]){
            dfs(nextNode);
        }
    }
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int nodeCnt, edgeCnt, startNode;
    cin >> nodeCnt >> edgeCnt >> startNode;

    board.resize(nodeCnt+1);
    isVisit.resize(nodeCnt+1, 0);
    for(int k = 0; k < edgeCnt; k++){
        int st, dt;
        cin >> st >> dt;
        board[st].push(dt);
        board[dt].push(st);
    }

    dfs(startNode);

    for(int k = 1; k <= nodeCnt; k++){
        cout << isVisit[k] << '\n';
    }
}