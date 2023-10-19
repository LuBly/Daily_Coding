#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#define INF 987654321
#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

using namespace std;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
vector<vector<vector<int>>> cost(25,vector<vector<int>>(25,vector<int>(4,INF)));

void dijkstra(vector<vector<int>> board){
    //{cost, {{y,x},dir}}
    priority_queue<pair<int, pair<pair<int,int>,int>>, vector<pair<int, pair<pair<int,int>,int>>>, greater<pair<int, pair<pair<int,int>,int>>>> pq;
    pq.push({0,{{0,0},-1}});
    for(int k = 0; k < 4; k++){
        cost[0][0][k] = 0;    
    }
    
    while(!pq.empty()){
        int curCost = pq.top().first;
        pair<int,int> curNode = pq.top().second.first;
        int curDir = pq.top().second.second;
        pq.pop();
        
        //if(curCost > cost[curNode.first][curNode.second][curDir]) continue;
        for(int k = 0; k < 4; k++){
            pair<int,int> nextNode = {curNode.first + dy[k], curNode.second + dx[k]};
            
            // nextNode가 범위 밖으로 나간 경우 continue
            if(nextNode.first >= board.size() || nextNode.second >= board.size() || nextNode.first < 0 || nextNode.second < 0) continue;
            // nextNode가 벽일 경우 continue
            if(board[nextNode.first][nextNode.second] == 1) continue;
            
            int nextCost  = curCost + 100;
            // 둘다 아닐경우 최소비용 계산
            // 코너인 경우
            if(curDir == UP || curDir == DOWN){
                if(k == LEFT || k == RIGHT){
                    nextCost += 500;
                }
            }
            if(curDir == LEFT || curDir == RIGHT){
                if(k == UP || k == DOWN){
                    nextCost += 500;
                }
            }
            
            
            if(nextCost < cost[nextNode.first][nextNode.second][k]){
                cost[nextNode.first][nextNode.second][k] = nextCost;
                pq.push({nextCost, {nextNode, k}});
            }
        }
    }
}

// dijkstra를 활용한 최소비용 계산
// 직선일 경우 비용 100, 코너일 경우 비용 500
// nextCost를 직선인지, 코너인지 판단하여 계산
int solution(vector<vector<int>> board) {
    int answer;
    dijkstra(board);
    answer = min({cost[board.size()-1][board.size()-1][0], cost[board.size()-1][board.size()-1][1], cost[board.size()-1][board.size()-1][2], cost[board.size()-1][board.size()-1][3]});
    return answer;
}