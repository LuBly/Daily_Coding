//[Baekjoon C++] 쉬운 최단거리 [최단거리]
#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int YSize, XSize;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

vector<vector<int>> dijkstra(vector<vector<int>> board, pair<int,int> st){
    vector<vector<int>> res(YSize, vector<int>(XSize, INF));
    //cost, node
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
    pq.push({0, st});
    res[st.first][st.second] = 0;

    while(!pq.empty()){
        int curCost = pq.top().first;
        pair<int,int> curNode = pq.top().second;
        pq.pop();
        for(int k = 0; k < 4; k++){
            pair<int,int> nextNode = {curNode.first + dy[k], curNode.second + dx[k]};
            if(nextNode.first >= YSize || nextNode.second >= XSize || nextNode.first < 0 || nextNode.second < 0) continue;

            if(board[nextNode.first][nextNode.second] == 0){
                res[nextNode.first][nextNode.second] = 0;
                continue;
            }
            
            int nextCost = curCost + 1;
            if(nextCost < res[nextNode.first][nextNode.second]){
                res[nextNode.first][nextNode.second] = nextCost;
                pq.push({nextCost, nextNode});
            }
        }
    }

    return res;
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);    
    
    cin >> YSize >> XSize;

    vector<vector<int>> board(YSize, vector<int>(XSize));
    pair<int,int> st;
    for(int y = 0; y < YSize; y++){
        for(int x = 0; x < XSize; x++){
            cin >> board[y][x];
            if(board[y][x] == 2) 
                st = {y,x};
        }
    }
    vector<vector<int>> res = dijkstra(board, st);
    // 모든 위치에서 도착점까지의 최단거리 계산
    // ->다익스트라 (2인 좌표에서 시작)
    // 플로이드 워셜 (1000 * 1000 * 1000) = 1,000,000,000 X
    // 시작지점 2에서 시작해서 모든 포인트(0 제외하고 싹다 계산)
    for(int y = 0; y < YSize; y++){
        for(int x = 0; x < XSize; x++){
            if(res[y][x] == INF){
                if(board[y][x] == 1) res[y][x] = -1;
                else res[y][x] = 0;
            } 
            cout << res[y][x] << " ";
        }
        cout << '\n';
    }
}