#include <string>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

// 최단거리
// 다익스트라 (일반적인 최단거리 알고리즘)
// 벨만포드 (사이클이 발생했을 때, 음의 가중치까지 계산가능)
// 플로이드-워셜 (O(n^3) = 100,000 ^3 X)

// 음의 가중치는 없으니 각 시작점(Sources 배열)을 기준으로 다익스트라 시작

//board[from] = {to, cost}
vector<int> dijkstra(int start, vector<vector<pair<int,int>>> board, int n){
    vector<int> cost(n+1,INF);
    //{cost, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});
    cost[start] = 0;
    
    while(!pq.empty()){
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        if(curCost > cost[curNode]) continue;
        
        for(int k = 0; k < board[curNode].size(); k++){
            int nextNode = board[curNode][k].first;
            int nextCost = curCost + board[curNode][k].second;
            
            if(nextCost < cost[nextNode]){
                cost[nextNode] = nextCost;
                pq.push({nextCost, nextNode});
            }
        }
    }
    return cost;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    //board[from] = {to, cost}
    vector<vector<pair<int,int>>> board(n+1);
    for(int k = 0; k < roads.size(); k++){ // 최대 500,000 반복
        int from = roads[k][0], to = roads[k][1];
        
        //왕복 가능
        board[from].push_back({to,1});
        board[to].push_back({from,1});
    }
    
    vector<int> cost = dijkstra(destination, board, n);
    
    for(int k = 0; k < sources.size(); k++){ // 최대 500 (500번의 다익스트라)
        int start = sources[k];    
        if(cost[start] == INF) cost[start] = -1;
        answer.push_back(cost[start]);
    }
    
    return answer;
}