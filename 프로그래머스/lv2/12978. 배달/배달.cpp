#include <iostream>
#include <vector>
#include <queue>
#define MAX 100000000
using namespace std;
//dijkstra 알고리즘 활용
//1번 노드를 시작으로 이동거리가 K 이하인 node들을 계산
vector<int> dijkstra(int start, int N, vector<pair<int,int>> adj[]){
    vector<int> cost(N+1,MAX);
    priority_queue<pair<int,int>> pq;//cost,node//cost는 최소값으로 정렬하기 위해 음수로 저장
    cost[start]=0;
    pq.push({0,start});
    while(!pq.empty()){
        int cur_node = pq.top().second;
        int cur_cost = -pq.top().first;
        pq.pop();
        for(int k=0;k<adj[cur_node].size();k++){
            int next_node = adj[cur_node][k].first;
            int next_cost = cur_cost+adj[cur_node][k].second;
            if(next_cost<cost[next_node]){
                cost[next_node]=next_cost;
                pq.push({-next_cost,next_node});
            }
        }
    }
    return cost;
}
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<pair<int,int>> adj[N+1];//각 노드에 인접한 node, cost
    for(int k=0;k<road.size();k++){
        int st = road[k][0];
        int dt = road[k][1];
        int cost = road[k][2];
        adj[st].push_back({dt,cost});
        adj[dt].push_back({st,cost});
    }
    vector<int> cost = dijkstra(1,N,adj);
    for(auto iter : cost){
        if(iter<=K) answer++;
    }
    return answer;
}