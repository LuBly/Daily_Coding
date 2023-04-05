//[Baekjoon C++] 연결 요소의 개수 [DFS]
#include <iostream>
#include <queue>
using namespace std;

int chess_size, sx, sy, dx, dy;
int dirY[8]={1,2,1,2,-1,-2,-1,-2};
int dirX[8]={2,1,-2,-1,-2,-1,2,1};
bool is_visited[301][301];
int path[301][301];
queue<pair<int,int>> q;

/// @brief BFS 함수
/// @param stX 시작 X좌표
/// @param stY 시작 Y좌표
/// @param deX 도착 X좌표 
/// @param deY 도착 Y좌표 
void BFS(int stX, int stY, int deX, int deY){
    q.push(make_pair(stY,stX));
    is_visited[stY][stX]=true;
    while(!q.empty()){
        int y= q.front().first;
        int x= q.front().second;
        q.pop();
        if(y==deY&&x==deX) {
            cout<<path[y][x]<<'\n';
            while(!q.empty()) q.pop(); //queue 초기화
            break;
        }
        for(int k=0;k<8;k++){
            int ny= y+dirY[k];
            int nx= x+dirX[k];
            if(ny>=chess_size||nx>=chess_size||ny<0||nx<0) continue;
            if(!is_visited[ny][nx]){
                q.push(make_pair(ny,nx));
                is_visited[ny][nx] = true;
                path[ny][nx]=path[y][x]+1;
            }
        }
    }
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int count;
    cin>>count;
    //초기화
    fill_n(&is_visited[0][0],301*301,false);
    fill_n(&path[0][0],301*301,0);

    for(int k=0;k<count;k++){
        cin>>chess_size;
        cin>>sx>>sy;
        cin>>dx>>dy;
        BFS(sx,sy,dx,dy);
        

        //모든 계산이 마무리 된 이후 초기화
        fill_n(&is_visited[0][0],301*301,false);
        fill_n(&path[0][0],301*301,0);
    }
}