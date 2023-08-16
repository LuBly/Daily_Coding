//[Baekjoon C++] 숨바꼭질3 [다익스트라]
#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001
#define INF 987654321
using namespace std;

vector<int> cost(MAX, INF);

void dijkstra(int start){
    // 경로 정보를 저장할 pq 선언 {cost, node}
    priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});
    cost[start] = 0;

    while(!pq.empty()){
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        for(int dir = 0; dir < 3; dir++){
            int nextCost, nextNode;
        
            switch (dir)
            {
            case 0://X-1
                nextCost = curCost+1;
                nextNode = curNode-1;
                break;

            case 1://X+1
                nextCost = curCost+1;
                nextNode = curNode+1;
                break;

            case 2://X*2
                nextCost = curCost;
                nextNode = curNode*2;
                break;
            }
            // 범위 밖으로 나갈 경우 패스
            if(nextNode < 0 || nextNode >= MAX) continue;
            
            if(nextCost < cost[nextNode]){
                cost[nextNode] = nextCost;
                pq.push({nextCost, nextNode});
            }
        }

    }
}


int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int start, dest;
    cin >> start >> dest;
    dijkstra(start);

    cout << cost[dest];
}