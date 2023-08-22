//[Baekjoon C++] 탈출 [BFS]
#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
// length  : 세로
// width   : 가로
// mapData : 맵 정보(Line 단위로 입력되기 때문에 string 사용)를 입력받을 vector
// dy, dx  : 비버 및 물의 이동을 계산하기 위한 방향 벡터
int length, width;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
vector<string> mapData(50);
// BFS를 동시에 진행
// 물(채우기) -> 고슴도치 -> 물 -> 고슴도치 순서대로 

// stQ    : 고슴도치의 이동을 관리할 Queue
// waterQ : 물의 이동을 관리할 Queue
queue<pair<int,int>> stQ;
queue<pair<int,int>> waterQ;
int result = 0;

void BFS(pair<int,int> dt){
    while(!stQ.empty()){
        // 물 먼저 채우고
        int waterCnt = waterQ.size();
        for(int i = 0; i < waterCnt; i++){
            pair<int,int> curWater = waterQ.front();
            waterQ.pop();
            for(int dir = 0; dir < 4; dir++){
                int ny = curWater.first + dy[dir];
                int nx = curWater.second + dx[dir];
                if(ny < 0 || nx < 0 || ny >= length || nx >= width) continue;
                if(mapData[ny][nx] == '.'){
                    waterQ.push({ny,nx});
                    mapData[ny][nx] = '*';
                }
            }
        }
        
        // 이동
        int hedgehogCnt = stQ.size();
        for(int i = 0; i < hedgehogCnt; i++){
            int y = stQ.front().first;
            int x = stQ.front().second;
            stQ.pop();
            for(int dir = 0; dir < 4; dir++){
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                // 목적지 도착하면 결과 출력 및 함수 종료
                if(ny == dt.first && nx == dt.second){
                    cout << result + 1;
                    return;
                }
                // 범위 밖으로 나가거나, 이동경로가 아닐 경우 이동 X
                if(ny < 0 || nx < 0 || ny >= length || nx >= width) continue;
                if(mapData[ny][nx] == '.'){
                    stQ.push({ny,nx});
                    mapData[ny][nx] = 'S';
                }
            }
        }
        // 고슴도치가 비버 소굴까지 가고 있는 시간 
        result++;
    }
    // 목적지에 도달하지 못하고 bfs가 종료되는 경우
    cout << "KAKTUS";
    return;
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);    
    // 세로, 가로 정보 입력
    cin >> length >> width;
    
    // 지도 정보 입력
    for(int y = 0; y < length; y++){
        cin >> mapData[y];
    }

    // dt - 비버의 좌표 {y,x}
    pair<int,int> dt;
    for(int y = 0; y < length; y++){
        for(int x = 0; x < width; x++){
            if(mapData[y][x]=='S') stQ.push({y,x});
            else if(mapData[y][x]=='D') dt = {y,x};
            else if(mapData[y][x]=='*') waterQ.push({y,x});
        }
    }

    BFS(dt);
}