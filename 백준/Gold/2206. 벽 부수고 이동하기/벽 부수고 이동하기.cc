//[Baekjoon C++] 벽 부수고 이동하기 [BFS]
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;


//bfs를 활용하여 문제풀이.
//벽을 깬 횟수까지 포함하여 계산
//bool board[1000][1000] = {false,};
int dist[1000][1000][2]={0,};//y,x,can_break->true(벽을 안부수고) , false(벽을 부수고)
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int length,width;

int bfs(int y, int x, vector<string> &board){
    queue<pair<pair<int, int>, int>> q;
    q.push({ {0,0},1 });
    dist[0][0][1] = 1;
    while(!q.empty()){
        int cy = q.front().first.first;
        int cx = q.front().first.second;
        int can_break = q.front().second;
        q.pop();
        //도착지에 도달하면 return
        if(cy==length-1&&cx==width-1) return dist[cy][cx][can_break]; 
        for(int k=0;k<4;k++){
            int ny=cy+dir[k][0];
            int nx=cx+dir[k][1];
            if(ny>=length||nx>=width||ny<0||nx<0) continue;//범위 밖으로 나갈 경우 무시
            //다음칸이 벽이고 뚫을 수 있을 때
            if(board[ny][nx]=='1'&&can_break){
                q.push({{ny,nx},false});
                dist[ny][nx][0] = dist[cy][cx][can_break]+1;
            }
            //다음칸이 0이고 방문하지 않았을 때
            else if(board[ny][nx]=='0'&&dist[ny][nx][can_break]==0){
                q.push({{ny,nx},can_break});
                dist[ny][nx][can_break]=dist[cy][cx][can_break]+1;
            }
        }
    }
    return -1;
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    cin>>length>>width;
    vector<string> board(length);
    //board 생성
    for(int y=0;y<length;y++){
        cin>>board[y];
    }
    cout<<bfs(0,0,board);
    return 0;
}