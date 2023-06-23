#include <string>
#include <vector>
#include <iostream>
#include <queue>
#define MAX 102
using namespace std;

int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};
vector<vector<int>> board(MAX,vector<int>(MAX,0));//경로가 있으면 true, 없으면 false


int bfs(pair<int,int> st, pair<int,int>dt){//각각 {x좌표, y좌표}
    queue<pair<int,int>> q;//{x좌표, y좌표}
    q.push(st);
    while(!q.empty()){
        int y=q.front().second;
        int x=q.front().first;
        q.pop();
        if(y==dt.second&&x==dt.first) break;
        
        for(int k=0;k<4;k++){
            int ny=y+dy[k];
            int nx=x+dx[k];
            if(board[ny][nx]==1){
                board[ny][nx]=board[y][x]+1;
                q.push({nx,ny});
            }
        }
    }
    return board[dt.second][dt.first]/2;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    //겹친 사각형들의 외곽포인트를 맵데이터로 저장
    //해당 map 데이터를 bfs로 탐색
    //각 직사각형의 겹치는 부분을 전부 제외해줘야하므로 직사각형의 내부를 0으로 채워넣으면 됨
    
    //1. 사각형들이 있는 범위에 1 채워넣기
    for(int k=0;k<rectangle.size();k++){
        int stX=rectangle[k][0]*2;
        int stY=rectangle[k][1]*2;        
        int dtX=rectangle[k][2]*2;
        int dtY=rectangle[k][3]*2;
        //직사각형 부분을 1로 채워넣기
        for(int y=stY;y<=dtY;y++){
            for(int x=stX;x<=dtX;x++)
                board[y][x]=1;
        }
    }
    //2. 사각형의 내부에 0 채워넣기
    for(int k=0;k<rectangle.size();k++){
        int stX=rectangle[k][0]*2;
        int stY=rectangle[k][1]*2;        
        int dtX=rectangle[k][2]*2;
        int dtY=rectangle[k][3]*2;
        //내부를 0으로 채우기
        for(int y=stY+1;y<dtY;y++){
            for(int x=stX+1;x<dtX;x++)
                board[y][x]=0;
        }
    }
    //1,2번 절차를 통해 사각형의 테두리에만 1이 채워짐
    
    //ㄷ 형태의 경우 bfs에 문제가 생길 수 있으므로 각 포인트들을 *2하여 문제풀이
    pair<int,int> character = {characterX*2,characterY*2};
    pair<int,int> item = {itemX*2,itemY*2};
    int answer = bfs(character,item);
    return answer;
    
}