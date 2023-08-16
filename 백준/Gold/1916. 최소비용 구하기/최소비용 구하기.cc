//[BaekJoon C++] 최소비용 구하기 [구현]
#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

vector<int> dijkstra(int start, vector<vector<pair<int,int>>> map, vector<int> costs){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    //{cost, dest}를 저장할 priorty queue
    //cost를 기준으로 오름차순 정렬
    pq.push({0, start});
    costs[start] = 0;
    while(!pq.empty()){
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        // 현재 들어온 경로가 기존 경로보다 cost가 높으면 그냥 패스
        if(curCost > costs[curNode]) continue;

        for(int idx = 0; idx < map[curNode].size(); idx++){
            int nextCost = curCost + map[curNode][idx].second;
            int nextNode = map[curNode][idx].first;
            // 현재 경유 노선의 cost가 기존에 저장된 경로보다 낮은 cost일 경우 그 길로 이동
            if(nextCost < costs[nextNode]){
                costs[nextNode] = nextCost;
                pq.push({nextCost, nextNode});
            }
        }
    }

    return costs;
}


int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int cityCnt, busCnt;
    cin >> cityCnt >> busCnt;

    vector<vector<pair<int,int>>> map(cityCnt+1);//cityCnt 만큼의 map vector 생성
    vector<int> costs(cityCnt+1,INF);
    for(int k = 0; k < busCnt; k++){
        int from, to, cost;
        cin >> from >> to >> cost;
        map[from].push_back({to, cost});
    }

    int start, dest;
    cin>> start >> dest;
    vector<int> result = dijkstra(start, map, costs);
    cout << result[dest];
}   
