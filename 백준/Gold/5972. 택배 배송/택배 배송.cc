//[Baekjoon C++] 택배 배송 [다익스트라]
#include <iostream>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

struct Node{
    int to;
    int cost;
};

int N, M;

void dijkstra(int st, vector<vector<Node>> board){
    vector<int> cost(N + 1, INF);
    //cost, node
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    cost[st] = 0;
    pq.push({0,st});

    while(!pq.empty()){
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        if(curCost > cost[curNode]) continue;
        
        for(int k = 0; k < board[curNode].size(); k++){
            int nextCost = curCost + board[curNode][k].cost;
            int nextNode = board[curNode][k].to;
            if(nextCost < cost[nextNode]){
                cost[nextNode] = nextCost;
                pq.push({nextCost, nextNode});
            }
        }
    }
    
    cout << cost[N];
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    cin >> N >> M;
    vector<vector<Node>> board(N+1);
    for(int k = 0; k < M; k++){
        int from, to, cost;
        cin >> from >> to >> cost;

        board[from].push_back({to,cost});
        board[to].push_back({from,cost});
    }

    dijkstra(1,board);
}