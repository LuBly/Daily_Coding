#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;
/*
1부터 돌면서 덩어리 체크
8, 1~3
7, 4~7
2, 7~8

1. 맵 전체로 그냥 bfs 한번 싹 돌리기
-> 돌리면서 지나친 x값들 저장
2. 각 인덱스에 시추할 수 있는 석유량 저장
-> 저장해둔 x값에 석유량 +
3. idx 돌면서 최대값 산출
*/
// x좌표별 오일양을 가지고 있을 vector
vector<int> oilData;
vector<vector<bool>> isVisit;
vector<vector<int>> board;
int length, width;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

struct Data{
    int y, x;
};

void bfs(int y, int x){
    int maxOil = 1;
    set<int> visitX;
    visitX.insert(x);
    
    queue<Data> q;
    q.push({y, x});
    isVisit[y][x] = true;
    
    while(!q.empty()){
        int curY = q.front().y;
        int curX = q.front().x;
        q.pop();

        visitX.insert(curX);
        
        for(int k = 0; k < 4; k++){
            int nextY = curY + dy[k];
            int nextX = curX + dx[k];
            
            if(nextY >= length || nextX >= width || nextY < 0 || nextX < 0) continue;
            
            if(board[nextY][nextX] == 1 && !isVisit[nextY][nextX]){
                q.push({nextY, nextX});
                isVisit[nextY][nextX] = true;
                maxOil++;
            }
        }
    }
    
    for(auto iter : visitX){
        oilData[iter] += maxOil;
    }
}

int solution(vector<vector<int>> land) {
    board = land;
    length = land.size();
    width = land[0].size();
    oilData.resize(width, 0);
    isVisit.resize(length, vector<bool>(width, false));
    
    for(int y = 0; y < length; y++){
        for(int x = 0; x < width; x++){
            if(land[y][x] == 1 && !isVisit[y][x])
                bfs(y, x);
        }
    }
    
    int answer = *max_element(oilData.begin(),oilData.end());
    return answer;
}