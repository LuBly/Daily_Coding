//[Baekjoon C++] 아기 상어 2 [BFS]
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[8] = {1,-1,0,0,1,-1,1,-1};
int dx[8] = {0,0,1,-1,1,1,-1,-1};
int Y,X;

struct Node
{
    /* data */
    int y;
    int x;
    int cnt;
};

vector<vector<int>> board(51, vector<int>(51));

int bfs(int y, int x){
    vector<vector<bool>> isVisit(Y, vector<bool>(X, false));
    queue<Node> q;
    int cnt = 0;
    isVisit[y][x] = true;
    q.push({y,x,cnt});

    while(!q.empty()){
        int cy = q.front().y;
        int cx = q.front().x;
        int curCnt = q.front().cnt;
        q.pop();
        
        if(board[cy][cx] == 1) return curCnt;
        for(int k = 0; k < 8; k ++){
            int ny = cy + dy[k];
            int nx = cx + dx[k];
            if(ny >= Y || nx >= X || ny < 0 || nx < 0) continue;

            if(!isVisit[ny][nx]){
                isVisit[ny][nx] = true;
                q.push({ny,nx,curCnt+1});
            }
        }
    }
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    cin >> Y >> X;
    int res = 0;
    for(int y = 0 ; y < Y; y++){
        for(int x = 0; x < X; x++){
            cin >> board[y][x];
        }
    }

    for(int y = 0 ; y < Y; y++){
        for(int x = 0; x < X; x++){
            if(board[y][x] == 0)
                res = max(res, bfs(y,x));
        }
    }
    
    cout << res;
}