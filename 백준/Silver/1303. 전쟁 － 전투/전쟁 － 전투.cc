//[Baekjoon C++] 알고스팟 [다익스트라]
#include <iostream>
#include <vector>
#include <queue>
#define MAX 101
using namespace std;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int Y, X;
vector<vector<bool>> isVisit_W(MAX, vector<bool>(MAX));
vector<vector<bool>> isVisit_B(MAX, vector<bool>(MAX));
vector<string> board(MAX);

int bfs_W(int y, int x){
    char curColor = 'W';
    queue<pair<int,int>> q;
    int cnt = 1;

    q.push({y,x});
    isVisit_W[y][x] = true;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int k = 0; k < 4; k++){
            int ny = cy + dy[k];
            int nx = cx + dx[k];

            if(ny >= Y || nx >= X || ny < 0 || nx < 0) continue;
            if(!isVisit_W[ny][nx] && board[ny][nx] == curColor){
                q.push({ny,nx});
                isVisit_W[ny][nx] = true;
                cnt++;
            }
        }
    }
    return cnt * cnt;
}

int bfs_B(int y, int x){
    char curColor = 'B';
    queue<pair<int,int>> q;
    int cnt = 1;

    q.push({y,x});
    isVisit_B[y][x] = true;
    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        
        q.pop();

        for(int k = 0; k < 4; k++){
            int ny = cy + dy[k];
            int nx = cx + dx[k];

            if(ny >= Y || nx >= X || ny < 0 || nx < 0) continue;
            if(!isVisit_B[ny][nx] && board[ny][nx] == curColor){
                q.push({ny,nx});
                isVisit_B[ny][nx] = true;
                cnt++;
            }
        }
    }
    return cnt * cnt;
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> X >> Y;    
    for(int y = 0; y < Y; y++){
        cin >> board[y];
    }

    //W bfs한번
    int W_Power = 0;
    for(int y = 0; y < Y; y++){
        for(int x = 0; x < X; x++){
            if(board[y][x] == 'W' && !isVisit_W[y][x]){
                W_Power += bfs_W(y,x);
            }
        }
    }

    //B bfs한번
    int B_Power = 0;
    for(int y = 0; y < Y; y++){
        for(int x = 0; x < X; x++){
            if(board[y][x] == 'B' && !isVisit_B[y][x]){
                B_Power += bfs_B(y,x);
            }
        }
    }

    cout << W_Power << " " << B_Power;
}