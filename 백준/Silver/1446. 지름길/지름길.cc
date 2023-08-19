//[Baekjoon C++] 지름길 [다익스트라]
#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001
#define INF 987654321
using namespace std;


// shortCutCount : 지름길의 개수
// roadLength    : 고속도로의 길이
// map           : 경로 정보를 저장할 vector [from] {to, cost}
// cost          : 시작점으로 부터 특정 노드까지의 최단 거리를 저장해둘 vector
int shortCutCount, roadLength;
vector<vector<pair<int,int>>> map(MAX);
vector<int> cost(MAX, INF);
    
void dijkstra(int start, vector<vector<pair<int,int>>> map){
    // 노드별 최단거리를 담고있을 Priority Queue {dist, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});
    while(!pq.empty()){
        int curDist = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        
        for(int i = 0; i < map[curNode].size(); i++){
            int nextDist = curDist + map[curNode][i].second;
            int nextNode = map[curNode][i].first;
        
            if(nextDist < cost[nextNode]){
                cost[nextNode] = nextDist;
                pq.push({nextDist, nextNode});
            }

        }
    }
}


int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    cin >> shortCutCount >> roadLength;
    // 지름길을 사용하지 않고 그냥 지나가는 map 정보 입력
    for(int i = 0; i < roadLength; i++){
        map[i].push_back({i+1, 1});
    }
    
    // 지름길 정보 입력
    for(int cnt = 0; cnt < shortCutCount; cnt++){
        int from, to, distance;
        cin >> from >> to >> distance;
        // 도착/시작 지점이 roadLength를 넘어가면 저장 X = 역주행 불가
        // from ~ to 의 길이보다 distance가 길면 저장 X = 지름길로써의 역할 X
        if(to > roadLength || from > roadLength || ((to-from) < distance)) continue;
        map[from].push_back({to, distance});
    }

    dijkstra(0, map);
    cout << cost[roadLength];
}