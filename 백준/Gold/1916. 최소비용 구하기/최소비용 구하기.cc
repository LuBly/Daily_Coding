//[BaekJoon C++] 최소비용 구하기 [다익스트라]
#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
#define INF 987654321
using namespace std;

// board : 각 노드별로 연결되어 있는 노드와 cost를 저장할 vector [from] {dist, to};
// cost  : 출발 도시부터 idx 도시까지의 최소 거리를 저장할 vector
vector<vector<pair<int, int>>> board(MAX);
vector<int> cost(MAX, INF);

void dijkstra(int start){
    // pq : cost를 오름차순으로 정리해서 저장하고 있을 priority queue
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    // 초기화
    pq.push({0,start});
    cost[start] = 0;

    while(!pq.empty()){
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        // 현재 들어온 cost가 이전에 계산해놓은 cost보다 클경우 continue;
        // -> 경유지를 경유했을 때 더 짧은 길이 있는지를 확인하려는 것
        // -> 경유지를 경유하기도 전에 cost가 더 크다면 구지 확인할 필요가 없다.
        if(curCost > cost[curNode]) continue;

        for(int k = 0; k < board[curNode].size(); k++){
            int nextCost = curCost + board[curNode][k].first;
            int nextNode = board[curNode][k].second;
            // 신규 경로의 cost가 기존 cost 보다 작다면 신규 경로 및 cost 저장
            if(nextCost < cost[nextNode]){
                cost[nextNode] = nextCost;
                pq.push({nextCost, nextNode});
            }
        }
    }
}

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    // cityCnt : 도시의 개수 (node 수)
    // busCnt  : 버스의 개수 (edge 수)
    int cityCnt, busCnt;
    cin >> cityCnt >> busCnt; 

    for(int k = 0; k < busCnt; k++){
        int from, to, dist;
        cin >> from >> to >> dist;
        board[from].push_back({dist, to});
    }   
    // st : 시작점
    // dt : 목적지
    int st, dt;
    cin>> st >> dt;
    dijkstra(st);

    cout<<cost[dt];
}   
