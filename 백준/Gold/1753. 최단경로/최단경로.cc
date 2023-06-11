//[BaekJoon C++] 최단경로 [Dijkstra]
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#define MAX 20001//최대 노드 갯수
#define INF INT_MAX
using namespace std;

int node, edge;

vector<int> dijkstra(int start, int node, vector<pair<int,int>> data[]){
    vector<int> cost(node+1,INF);
    priority_queue<pair<int,int>> pq;//cost, node_idx를 우선순위에 따라 저장할 pq
    cost[start]=0;
    pq.push({0,start});
    while(!pq.empty()){
        int cur_cost = -pq.top().first;
        int cur_idx = pq.top().second;
        pq.pop();
        for(int k = 0; k < data[cur_idx].size(); k++){
            int next_cost = cur_cost+data[cur_idx][k].second;
            int next_idx = data[cur_idx][k].first;
            if(cost[next_idx]>next_cost){
                pq.push({-next_cost,next_idx});
                cost[next_idx] = next_cost;
            }
        }
    }
    return cost;
}

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>node>>edge;
    int start;
    cin>>start;
    vector<pair<int,int>> data[MAX];
    for(int k=0;k<edge;k++){
        int st,dt,cost;
        cin>>st>>dt>>cost;
        //한방향 데이터 저장 
        data[st].push_back({dt,cost});
    }
    vector<int> cost = dijkstra(start,node, data);
    for(int k=1;k<=node;k++){
        if(cost[k]==INF) cout<<"INF"<<'\n';
        else cout<<cost[k]<<'\n';
    }
}    