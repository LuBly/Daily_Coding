//[Baekjoon C++] 미로만들기 [Dijkstra]
#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int boardSize;
vector<vector<int>> dijkstra(vector<string> board, vector<vector<int>> cost){
    // 해당 좌표까지 도달하는데 있어서 가장 적게 방을 바꾸는 경우를 저장할 vector
    vector<vector<int>> result = cost;

    // 방문 좌표와 cost를 저장할 priority queue
    // pq [cost, {y,x}]
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{0,0}});
    // 최초 출발지점의 cost = 0으로 초기화
    result[0][0] = 0;

    while(!pq.empty()){
        int curCost             = pq.top().first;
        pair<int,int> curNode   = pq.top().second;
        pq.pop();

        // 현재 들어온 node의 cost가 기존 최소값보다 크다면 구지 계산을 할 필요가 없다
        if(result[curNode.first][curNode.second] < curCost) continue;

        for(int k = 0; k < 4; k++){
            int nextCost            = curCost;
            pair<int,int> nextNode  = {curNode.first + dy[k], curNode.second + dx[k]};
            if(nextNode.first >= boardSize || nextNode.second >= boardSize || nextNode.first < 0 || nextNode.second < 0) continue;
            
            if(board[nextNode.first][nextNode.second] == '0') nextCost++;

            if(nextCost < result[nextNode.first][nextNode.second]){
                pq.push({nextCost, nextNode});
                result[nextNode.first][nextNode.second] = nextCost;
            }
        }
    }

    return result;
}


int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> boardSize;
    vector<string> board(boardSize);
    vector<vector<int>> cost(boardSize, vector<int>(boardSize,INF));
    for(int k = 0; k < boardSize; k++){
        cin >> board[k];
    }

    vector<vector<int>> result = dijkstra(board, cost);

    cout << result[boardSize-1][boardSize-1];
}