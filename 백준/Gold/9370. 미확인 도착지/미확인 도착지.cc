//[Baekjoon C++] 미확인 도착지 [최단거리알고리즘]
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

// 최단거리 알고리즘
// 다익스트라 (양의 가중치만 가지고 있을 때, 하나의 출발지로 부터 나머지 도착지들에 대한 최단거리를 계산할 수 있음.)
// 벨만-포드 (사이클 형성 여부에 관계없이 음의 가중치까지도 고려하여 계산)
// 플로이드 워셜 (음 양 상관x, 모든 출발지 및 도착지의 최단 거리 계산 가능)

// dijkstra를 활용
// 1. st -> smellNode_1 -> smellNode_2 -> dest
// 2. st -> smellNode_2 -> smellNode_1 -> dest
// cost 중 최단거리인 것을 출력

vector<int> dijkstra(int st, vector<vector<pair<int,int>>> board, vector<int> dist){
    vector<int> result = dist;
    // cost, node
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,st});
    result[st] = 0;

    while(!pq.empty()){
        int curNode = pq.top().second;
        int curCost = pq.top().first;
        pq.pop();
        // 0 , INF
        if(curCost > result[curNode]) continue;

        for(int k = 0; k < board[curNode].size(); k++){
            int nextNode = board[curNode][k].first;
            int nextCost = curCost + board[curNode][k].second;

            if(nextCost < result[nextNode]){
                result[nextNode] = nextCost;
                pq.push({nextCost, nextNode});
            }
        }
    }

    return result;
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int testCase;
    cin >> testCase;
    for(int k = 0; k < testCase; k++){
        // 첫 번째 줄에 3개의 정수 n, m, t /교차로, 도로, 목적지 후보의 개수
        int node, edge, targetCnt;
        cin >> node >> edge >> targetCnt;
        
        //두 번째 줄에 3개의 정수 s, g, h / s는 예술가들의 출발지이고, g, h는 문제 설명에 나와 있다.
        //g,h = 냄새를 맡은 도로 = 반드시 포함해야 하는 경로
        int start, smellNode_1, smellNode_2, adjToAdj;
        cin >> start >> smellNode_1 >> smellNode_2;
        // [시작] = {도착, cost}
        
        vector<vector<pair<int,int>>> board(node+1);
        vector<int> dist(node+1,INF);

        for(int p = 0; p < edge; p++){
            int st, dt, cost;
            cin >> st >> dt >> cost;
            board[st].push_back({dt, cost});
            board[dt].push_back({st, cost});
            if((st == smellNode_1 && dt == smellNode_2)||(st == smellNode_2 && dt == smellNode_1)){
                adjToAdj = cost;
            }
        }

        vector<int> fromStart = dijkstra(start, board, dist);
        int crossRoad_1, crossRoad_2;
        
        // 가까운 쪽이 cross 1, 먼쪽이 2
        if(fromStart[smellNode_1] < fromStart[smellNode_2]){
            crossRoad_1 = smellNode_1;
            crossRoad_2 = smellNode_2;
        }
        else{
            crossRoad_1 = smellNode_2;
            crossRoad_2 = smellNode_1;
        }
        
        int stToadj = fromStart[crossRoad_1];
        
        // st -> 1 -> 2 -> 목적지 == 출발 -> 목적지 정답
        
        vector<int> target;
        for(int p = 0; p < targetCnt; p++){
            int t;
            cin >> t;
            target.push_back(t);
        }
        sort(target.begin(), target.end());

        vector<int> fromAdj = dijkstra(crossRoad_2, board, dist);
        for(int p = 0; p < targetCnt; p++){
            int dest = target[p];
            int adjToDest = fromAdj[dest];
            if(fromStart[dest] == stToadj + adjToAdj + adjToDest) cout << dest << " ";
        }
        cout << '\n';
    }
}