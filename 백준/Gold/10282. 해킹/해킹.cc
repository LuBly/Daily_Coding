//[Baekjoon C++] 해킹 [Dijkstra]
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
#define INF INT_MAX
using namespace std;

vector<int> dijkstra(int start, vector<vector<pair<int,int>>> board, vector<int> cost){
    vector<int> result = cost;
    // {cost, to}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});
    result[start] = 0;
    
    while(!pq.empty()){
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        if(curCost > result[curNode]) continue;

        for(int k = 0; k < board[curNode].size(); k++){
            int nextCost = curCost + board[curNode][k].second;
            int nextNode = board[curNode][k].first;
            if(nextCost < result[nextNode]){
                result[nextNode] = nextCost;
                pq.push({nextCost, nextNode});
            }
        }
    }

    return result;
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int testCnt;
    cin >> testCnt;
    for(int testIdx = 0; testIdx < testCnt; testIdx++){
        // n : 컴퓨터 개수 (node)
        // d : 의존성 개수 (edge)
        // c : 해킹당한 컴퓨터의 번호(시작점)
        int n, d, c;
        cin >> n >> d >> c;

        vector<vector<pair<int,int>>> board(n+1);
        vector<int> cost(n+1, INF);
        //[from] = {to, cost}
        for(int edge = 0; edge < d; edge++){
            // b -> a, cost :s
            int from, to, s;
            cin >> to >> from >> s;
            board[from].push_back({to,s});
        }
        vector<int> result = dijkstra(c, board, cost);
        
        int cnt = 0;
        int sec = 0;
        for(int k = 1; k <= n; k++){
            if(result[k]!=INF) {
                cnt++;
                if(result[k] > sec)
                    sec = result[k];    
            }
        }
        cout << cnt << " " << sec << '\n';
    }
}