#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
//BFS 사용하여 map 탐색
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int length, width;
bool is_visit[101][101]={false,};
int path[101][101]={0,};
void BFS(vector<string> board, pair<int,int> start){
    queue<pair<int,int>> q;
    q.push(start);
    is_visit[start.first][start.second]=true;
    
    while(!q.empty()){
        int y = q.front().first, x = q.front().second;
        q.pop();
        for(int k=0;k<4;k++){//방향 선택
            // 단순히 한칸씩 이동하는것 x
            // 미끌어져서 장애물이 있을 때까지 이동.
            int ny, nx;
            int cnt = 1;
            while(true){
                ny = y+dy[k]*cnt;
                nx = x+dx[k]*cnt;
                //멈추는 조건
                if(ny>=length){
                    ny = length-1;
                    break;
                }
                if(nx>=width){
                    nx = width-1;
                    break;
                }
                if(ny<0){
                    ny = 0;
                    break;
                }
                if(nx<0){
                    nx = 0;
                    break;
                }
                if(board[ny][nx]=='D'){
                    ny = y+dy[k]*(cnt-1);
                    nx = x+dx[k]*(cnt-1);
                    break;
                }
                cnt++;
            }
            
            if(!is_visit[ny][nx]){
                is_visit[ny][nx] = true;
                path[ny][nx]=path[y][x]+1;
                q.push({ny,nx});
            }
        }
    }
}

int solution(vector<string> board) {
    int answer = 0;
    length=board.size(), width=board[0].size();
    pair<int,int> st,dt;
    for(int y=0;y<length;y++){
        for(int x=0;x<width;x++){
            if(board[y][x]=='R')
                st={y,x};
            if(board[y][x]=='G')
                dt={y,x};
        }
    }
    BFS(board,st);
    answer = path[dt.first][dt.second];
    if(answer==0) answer = -1;
    return answer;
}