//[Baekjoon C++] 특정한 최단 경로 [최단 경로]
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#define MAX 987654321
using namespace std;

//다익스트라 세번
//1번 노드->v1->v2->N
vector<pair<int,int>> board[801];//node, cost
vector<int> cost(801);
int node, edge;

void dijkstra(int start){
    for(int k=0;k<=node;k++) cost[k]=MAX;
    priority_queue<pair<int,int>> pq;//cost, node
    cost[start]=0;
    pq.push({0,start});
    while(!pq.empty()){
        int cur_node = pq.top().second;
        int cur_cost = -pq.top().first;
        pq.pop();
        
        for(int k=0;k<board[cur_node].size();k++){
            int next_node = board[cur_node][k].first;
            int next_cost = cur_cost+board[cur_node][k].second;
            if(next_cost<cost[next_node]){//기존 비용보다 지금 경로로 갔을 때 비용이 낮다면 갱신
                cost[next_node]=next_cost;
                pq.push({-next_cost,next_node});
            }
        }
    }
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>node>>edge;
    //board data 입력
    for(int k=0;k<edge;k++){
        int st, dt, cost;
        cin>>st>>dt>>cost;
        board[st].push_back({dt,cost});
        board[dt].push_back({st,cost});
    }
    int v1,v2;
    cin>>v1>>v2;
    dijkstra(1);//1에서 출발해서 v1, v2에 도달할 수 있는 최단 거리
    int s_v1 = cost[v1];
    int s_v2 = cost[v2];

    dijkstra(v1);//v1에서 출발해서 v2, N에 도달할 수 있는 최단거리
    int v1_v2 = cost[v2];
    int v1_N = cost[node];

    dijkstra(v2);//v2에서 출발해서 N에 도달할 수 있는 최단거리
    int v2_N = cost[node];

    int result=MAX;
    result = min(result,s_v1+v1_v2+v2_N);//s->v1->v2->N
    result = min(result,s_v2+v1_v2+v1_N);//s->v2->v1->N 

    if(v1_v2==MAX||result==MAX) cout<<-1;
    else cout<<result;

}