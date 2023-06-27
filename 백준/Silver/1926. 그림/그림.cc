//[Baekjoon C++] 그림 [그래프 탐색]
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 500
using namespace std;
//dfs로 탐색하면서 size check
//dfs 재귀 횟수 = 그림의 크기
//dfs를 실행한 횟수 = 그림의 개수
int length, width;
vector<vector<int>> board(MAX,vector<int>(MAX,0));//
vector<vector<bool>> is_visit(MAX,vector<bool>(MAX,false));
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};

int sz=1;
void dfs(int y,int x){
    is_visit[y][x]=true;
    for(int k=0;k<4;k++){
        int ny=y+dy[k];
        int nx=x+dx[k];
        if(ny>=length||nx>=width||nx<0||ny<0) continue;
        if(board[ny][nx]&&!is_visit[ny][nx]){
            sz++;
            dfs(ny,nx);
        }
    }
}
int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>length>>width;

    //board 채워넣기
    for(int y=0;y<length;y++){
        for(int x=0;x<width;x++)
            cin>>board[y][x];
    }

    int result = 0;
    int cnt=0;
    for(int y=0;y<length;y++){
        for(int x=0;x<width;x++){
            if(board[y][x]&&!is_visit[y][x]){
                dfs(y,x);
                result = max(result, sz);
                cnt++;
                sz=1;
            }
        }
    }
    cout<<cnt<<'\n'<<result;

}