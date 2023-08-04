//[Baekjoon C++] 특정한 최단 경로 [최단 경로]
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 987654321
using namespace std;

vector<vector<pair<int,int>>> board(801);//시작지점 / 도착지점,cost
vector<int> cost(801);
int nodeCount, edgeCount;

void dijkstra(int start){
    for(int k = 0; k <= nodeCount; k++) cost[k] = MAX;
    priority_queue<pair<int,int>> pq; //cost, node
    cost[start]=0;
    pq.push({0,start});
    while(!pq.empty()){
        int curNode = pq.top().second;
        int curCost = -pq.top().first;
        pq.pop();

        for(int k = 0; k < board[curNode].size(); k++){
            int nextNode = board[curNode][k].first;
            int nextCost = curCost + board[curNode][k].second;
            //dest까지 도달하는데 현재 저장된 cost보다 현재 방문한 노드를 거치는 cost가 더 적다면 
            //cost 변경
            if(nextCost < cost[nextNode]){
                cost[nextNode] = nextCost;
                pq.push({-nextCost, nextNode});
            }
        }
    }
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>nodeCount>>edgeCount;

    for(int k = 0; k < edgeCount; k++){
        int start, dest, cost;
        cin>>start>>dest>>cost;
        board[start].push_back({dest,cost});
        board[dest].push_back({start,cost});
    }

    int adj1, adj2;
    cin>>adj1>>adj2;

    //1에서 시작해서 모든 노드에 도달하는 최단거리
    dijkstra(1);
    int fromStartToAdj1 = cost[adj1];
    int fromStartToAdj2 = cost[adj2];

    dijkstra(adj1);
    int fromAdj1ToAdj2 = cost[adj2];
    int fromAdj1ToDest = cost[nodeCount];

    dijkstra(adj2);
    int fromAdj2ToDest = cost[nodeCount];

    int result = MAX;
    result = min(result, fromStartToAdj1+fromAdj1ToAdj2+fromAdj2ToDest);//s->adj1->adj2->N
    result = min(result, fromStartToAdj2+fromAdj1ToAdj2+fromAdj1ToDest);//s->adj2->adj1->N

    if(fromAdj1ToAdj2 == MAX || result == MAX) cout << -1;
    else cout << result;
}