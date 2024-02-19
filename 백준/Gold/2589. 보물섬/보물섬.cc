//[Baekjoon C++] 보물섬 [BFS]
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
각 출발점 -> 도착점 간의 최단거리가 가장 긴 곳을 찾는 문제

1. 모든 출발점에서 갈 수 있는 모든 경로 체크, 최장거리 저장 => 결과
*/

vector<string> board;
int length, width;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

struct Land
{
    int y;
    int x;
    int dist;
};

int res = 0;

void bfs(int y, int x){
    vector<vector<bool>> isVisit(length, vector<bool>(width, false));
    queue<Land> q;
    q.push({y,x,0});
    isVisit[y][x] = true;

    while(!q.empty()){
        int cy = q.front().y;
        int cx = q.front().x;
        int cDist = q.front().dist;
        q.pop();
        
        res = max(res, cDist);

        for(int k = 0; k < 4; k++){
            int ny = cy + dy[k];
            int nx = cx + dx[k];

            if(ny >= length || nx >= width || ny < 0 || nx < 0) continue;
            if(board[ny][nx] != 'W' && !isVisit[ny][nx]){
                q.push({ny,nx,cDist+1});
                isVisit[ny][nx] = true;
            }   
        }
    }
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    cin >> length >> width;

    board.resize(length);
    for(int y = 0; y < length; y++){
        cin >> board[y];
    }

    for(int y = 0; y < length; y++){
        for(int x = 0; x < width; x++){
            if(board[y][x] == 'L')
                bfs(y,x);
        }
    }

    cout << res;
}