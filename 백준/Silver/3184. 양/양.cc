//[Baekjoon C++] 양 [BFS]
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<string> board;
vector<vector<bool>> isVisit;
int sheepCnt = 0, wolfCnt = 0;
int length, width;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

void bfs(int y, int x){
    int curSheep = 0, curWolf = 0;
    queue<pair<int,int>> q;
    q.push({y,x});
    isVisit[y][x] = true;
    
    if(board[y][x] == 'v') curWolf++;
    else if(board[y][x] == 'o') curSheep++;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int k = 0; k < 4; k++){
            int ny = cy + dy[k];
            int nx = cx + dx[k];

            if(ny >= length || nx >= width || ny < 0 || nx < 0) continue;
            if(board[ny][nx] != '#' && !isVisit[ny][nx]){
                isVisit[ny][nx] = true;
                q.push({ny,nx});
                if(board[ny][nx] == 'v') curWolf++;
                else if(board[ny][nx] == 'o') curSheep++;
            }
        }
    }

    if(curSheep > curWolf) sheepCnt += curSheep;
    else wolfCnt += curWolf;
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);    
    cin >> length >> width;
    board.resize(length);
    isVisit.resize(length, vector<bool>(width, false));

    for(int y = 0; y < length; y++){
        cin >> board[y];        
    }

    for(int y = 0; y < length; y++){
        for(int x = 0; x < width; x++){
            if((board[y][x] == 'v' || board[y][x] == 'o')&&(!isVisit[y][x])){
                bfs(y,x);
            }
        }
    }

    cout << sheepCnt << " " << wolfCnt;
}