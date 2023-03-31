#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;


int width, length;
int map[101][101];
int path[101][101]={0};
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
bool is_visited[101][101]={false};

void BFS(int startY, int startX, int destY, int destX){
    queue<pair<int,int>> q; // queue생성
    fill_n(&is_visited[0][0],101*101,false);
    is_visited[startY][startX] = true;
    q.push(make_pair(startY,startX));
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        if(y==destY&&x==destX) return;
        for(int k=0;k<4;k++){
            int ny=y+dy[k];
            int nx=x+dx[k];
            if(ny>=length||nx>=width||ny<0||nx<0) continue;
            if(map[ny][nx]==1&&!is_visited[ny][nx]){
                path[ny][nx]=path[y][x]+1;
                is_visited[ny][nx]=true;
                q.push(make_pair(ny,nx));
            }
        }
    }
}

int solution(vector<string> maps) {
    int answer = 0;
    int sx,sy,lx,ly,ex,ey;
    width = maps[0].size();
    length = maps.size();
    
    for(int k=0;k<length;k++){
        for(int j=0;j<width;j++){
            if(maps[k][j]=='S'){
                sy=k; sx=j;
                map[k][j]=1;
            }
            if(maps[k][j]=='O')
                map[k][j]=1;
            if(maps[k][j]=='L'){
                ly=k; lx=j;
                map[k][j]=1;
            }
            if(maps[k][j]=='X')
                map[k][j]=0;
            if(maps[k][j]=='E'){
                ey=k;ex=j;
                map[k][j]=1;
            }
        }
    }
    /*
    for(int k=0;k<length;k++){
        for(int j=0;j<width;j++){
            cout<<map[k][j]<<" ";
        }
        cout<<endl;
    }
    */
    BFS(sy,sx,ly,lx);
    if(path[ly][lx]==0) return -1;
    /*
    cout<<endl;
    for(int k=0;k<length;k++){
        for(int j=0;j<width;j++){
            cout<<path[k][j]<<" ";
        }
        cout<<endl;
    }
    */
    BFS(ly,lx,ey,ex);
    if(path[ey][ex]==0) return -1;
    /*
    cout<<endl;
    for(int k=0;k<length;k++){
        for(int j=0;j<width;j++){
            cout<<path[k][j]<<" ";
        }
        cout<<endl;
    }
    */
    answer=path[ey][ex];
    
    return answer;
}