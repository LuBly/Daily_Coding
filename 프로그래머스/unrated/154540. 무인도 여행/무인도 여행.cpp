#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int Length, Height, Count=0;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

int map[101][101]={0,};
bool is_visited[101][101]={false};


void dfs(int y, int x){
    is_visited[y][x] = true;
    for(int k=0;k<4;k++){
        int ny = y+dy[k];
        int nx = x+dx[k];
        if(nx>=Length||ny>=Height||nx<0||ny<0) continue;
        if(map[ny][nx]>0&&!is_visited[ny][nx]){
            Count+=map[ny][nx];
            dfs(ny,nx);
        }
    }
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    Height = maps.size(); Length = maps[0].size(); 
    for(int k=0;k<Height;k++){ //map 정보 int형으로 변환
        for(int j=0;j<Length;j++){
            if(maps[k][j]=='X') map[k][j]=0;
            else map[k][j]= maps[k][j]-'0';
        }
    }
    
    for(int k=0;k<Height;k++){
        for(int j=0;j<Length;j++){
            if(map[k][j]>0&&!is_visited[k][j]){//matrix 전부 순환
                Count+=map[k][j];
                dfs(k,j);
                answer.push_back(Count);
                Count=0;
            }
        }
    }
    sort(answer.begin(),answer.end());
    if(answer.empty()) answer.push_back(-1);
    return answer;
}