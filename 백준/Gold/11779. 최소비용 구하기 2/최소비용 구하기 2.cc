//[Baekjoon C++] 최소비용 구하기2 [다익스트라]
#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

vector<int> route(1001, 0);

vector<int> dijkstra(int start, vector<vector<pair<int,int>>> map, vector<int> dist){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;//{cost, node}
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()){
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        // 예외 처리
        // 현재 들어온 node의 cost가 지금까지 온 최소 cost보다 크다면 구지 검사할 필요 X
        if(curCost > dist[curNode]) continue;

        for(auto next : map[curNode]){//map {node, cost}
            int nextCost = curCost + next.second;
            int nextNode = next.first;
            if(nextCost < dist[nextNode]){
                dist[nextNode] = nextCost;
                pq.push({nextCost, nextNode});
                route[nextNode] = curNode;
            }
        }
    }

    return dist;
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int CityCnt, BusCnt;
    cin >> CityCnt >> BusCnt;
    vector<vector<pair<int,int>>> map(CityCnt+1);//{목적지, 비용}
    vector<int> dist(CityCnt+1, INF);

    for(int idx = 0; idx < BusCnt; idx++){
        int from, to, cost;
        cin >> from >> to >> cost;
        map[from].push_back({to,cost});
    }
    int start, dest;
    cin >> start >> dest;

    vector<int> result = dijkstra(start, map, dist);
    
    vector<int> routeArr;
    routeArr.push_back(dest);
    int chk = route[dest];
    while(chk){
        routeArr.push_back(chk);
        chk = route[chk];
    }

    cout<<result[dest]<<'\n';
    cout<<routeArr.size()<<'\n';
    for(int k = routeArr.size()-1; k >= 0; k--){
        cout<< routeArr[k] << " ";
    }
    cout<<'\n';
    
}