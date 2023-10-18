//[Baekjoon C++] 서강그라운드 [다익스트라]
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

// placeCnt  : 지역의 개수 = node
// scanRange : 수색 범위
// roadCnt   : 길의 개수 = edge
int placeCnt, scanRange, roadCnt;

vector<int> dijkstra(int st, vector<vector<pair<int,int>>> board){
    vector<int> cost(placeCnt+1,INF);
    // cost, dt를 계산해줄 pq
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,st});
    cost[st] = 0;
    while(!pq.empty()){
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        if(cost[curNode] < curCost) continue;

        for(int k = 0; k < board[curNode].size(); k++){
            int nextCost = curCost + board[curNode][k].second;
            int nextNode = board[curNode][k].first;
            if(nextCost < cost[nextNode]){
                cost[nextNode] = nextCost;
                pq.push({nextCost, nextNode});
            }
        }
    }

    return cost;
}

// 출발점을 기준으로 모든 노드의 최단거리를 계산
// 최단 거리가 수색범위 내에 있다면 아이템 챙기기
int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);    
    
    cin >> placeCnt >> scanRange >> roadCnt;

    vector<int> item(placeCnt+1);
    for(int k = 1; k <= placeCnt; k++){
        cin >> item[k];
    }
    //[from] = {to, dist}
    vector<vector<pair<int,int>>> board(placeCnt+1);
    for(int k = 0; k < roadCnt; k++){
        int from, to, dist;
        cin >> from >> to >> dist;
        // 양방향임을 잊지말자.
        board[from].push_back({to,dist});
        board[to].push_back({from,dist});
    }

    int maxItem = 0;
    // 모든 지역에 떨어져보면서 최대 아이템을 계산
    for(int st = 1; st <= placeCnt; st++){
        // k 출발점으로 부터 각 노드들까지의 최단 거리 계산
        vector<int> res = dijkstra(st, board);
        int itemCnt = 0;
        for(int dt = 1; dt <= placeCnt; dt++){
            if(res[dt] <= scanRange) itemCnt += item[dt];
        }
        maxItem = max(maxItem, itemCnt);
    }

    cout << maxItem;
}