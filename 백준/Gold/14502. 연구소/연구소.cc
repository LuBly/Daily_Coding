//[Baekjoon C++] 연구소 [그래프 탐색]
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 9
using namespace std;

int height, width;
int maxSpreadSize = 0;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
bool isVisit[MAX][MAX] = {false,};

void spread(vector<vector<int>> map){
    
    queue<pair<int,int>> q;//y,x
    
    //바이러스 시작 지점 q에 저장
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            if(map[y][x]==2) q.push({y,x});
        }
    }

    //BFS를 사용하여 바이러스 퍼뜨리기
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int k = 0; k < 4; k++){
            int ny = y + dy[k];
            int nx = x + dx[k];
            if(ny>=height||nx>=width||ny<0||nx<0) continue;
            if(map[ny][nx]==0){
                map[ny][nx]=2;
                q.push({ny,nx});
            }
        }
    }

    //오염되지 않은 부분 체크
    int cnt = 0;
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            if(map[y][x]==0) cnt++;
        }
    }

    maxSpreadSize = max(maxSpreadSize, cnt);

}

void createWall(int wallCount,vector<vector<int>> map){
    if(wallCount == 3){
        spread(map);
        return;
    }

    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            if(map[y][x]==0){
                map[y][x]=1;
                createWall(wallCount+1,map);
                map[y][x]=0;
        }
        }
    }
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>height>>width;
    vector<vector<int>> board(height,vector<int>(width));//맵 vector 선언    
    
    //board 채우기
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            cin>>board[y][x];
        }
    }
    //1. dfs 백트래킹을 활용하여 0인 부분 3개를 골라 벽으로 막기
    //2. 벽으로 막은 이후 bfs를 통해 바이러스 퍼뜨리기
    //3. 안전 영역 크기 도출
    //4. dfs를 모두 마무리 한 후 최대 안전 영역 return
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            if(board[y][x]==0){
                vector<vector<int>> cpBoard = board;
                cpBoard[y][x]=1;
                createWall(1, cpBoard);
                cpBoard[y][x]=0;
            }
        }
    }

    cout<<maxSpreadSize;
}