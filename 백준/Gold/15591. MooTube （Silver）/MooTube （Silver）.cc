//[Baekjoon C++] MooTube (Silver) [BFS]
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
#define MAX 5001
#define INF INT_MAX
using namespace std;

//[st]={dt, usado}
vector<vector<pair<int,int>>> board(MAX);
int netCnt, questionCnt;

int bfs(int K, int start){
    vector<int> usadoData(MAX, INF);
    int result = 0;
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        int curNode = q.front();
        q.pop();
        for(int k = 0; k < board[curNode].size(); k++){
            int nextNode = board[curNode][k].first;
            int nextUsado = board[curNode][k].second;
            if(usadoData[nextNode] == INF){
                usadoData[nextNode] = min(usadoData[curNode], nextUsado);
                q.push(nextNode);
            }
        }
    }

    for(int k = 1; k <= netCnt; k++){
        if(usadoData[k] >= K && k != start) result++;
    }
    return result;
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);        
    cin >> netCnt >> questionCnt;

    for(int i = 0; i < netCnt-1; i++){
        int vidio_1, vidio_2, usado;
        cin >> vidio_1 >> vidio_2 >> usado;
        board[vidio_1].push_back({vidio_2,usado});
        board[vidio_2].push_back({vidio_1,usado});
    }

    for(int i = 0; i < questionCnt; i++){
        int K, start, result;
        cin >> K >> start;
        result = bfs(K, start);
        cout << result << '\n';
    }
}