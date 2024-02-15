#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define MAX 987654321
using namespace std;

//bfs? backtracking
/*
각각의 visit 정보를 가지고 동시에 진행
backTracking을 활용하면서 dfs 진행
RedSt, RedDt, BlueSt, BlueDt 항상 일정
dfs(RSt, RDt, BSt, BDt, 0);
*/
struct Node{
    int y, x;
};

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
vector<vector<bool>> RVisit(5,vector<bool>(5,false));
vector<vector<bool>> BVisit(5,vector<bool>(5,false));
vector<vector<int>> board;
int length, width;
bool redEnd = false, blueEnd = false;
// 시작 포인트와 카운트만 가지고 있다.

bool isPossible(Node curR, Node nextR, Node curB, Node nextB){
    // 각 포인트가 칸을 벗어나는 경우, 벽을 만나는 경우 false
    if(nextR.y >= length || nextR.x >= width || nextR.y < 0 || nextR.x < 0 
    || nextB.y >= length || nextB.x >= width || nextB.y < 0 || nextB.x < 0
    || board[nextR.y][nextR.x] == 5 || board[nextB.y][nextB.x] == 5) 
        return false;
    
    // 두 수레의 switch check, 자리를 뒤바꾸는 경우 false
    if((curR.x == nextB.x && curR.y == nextB.y) 
    && (curB.x == nextR.x && curB.y == nextR.y)) return false;
    
    // end가 아니면서 중복 방문이라면 false
    if((!redEnd && RVisit[nextR.y][nextR.x]) || (!blueEnd && BVisit[nextB.y][nextB.x])) return false;
    
    // 두 수레가 동일한 지점에 위치할 경우
    if(nextR.y == nextB.y && nextR.x == nextB.x) return false;
    
    return true;
}

int dfs(Node curR, Node curB, int cnt){
    if(redEnd && blueEnd) return cnt;
    
    int answer = MAX;
    
    for(int rIdx = 0; rIdx < 4; rIdx++){
        for(int bIdx = 0; bIdx < 4; bIdx++){
            Node nextR, nextB;
            if(redEnd){
                nextR = curR;
            }
            else
                nextR = {curR.y + dy[rIdx], curR.x + dx[rIdx]};
            
            if(blueEnd){
                nextB = curB;
            }
            else{
                nextB = {curB.y + dy[bIdx], curB.x + dx[bIdx]};
            }
            
            if(!isPossible(curR, nextR, curB, nextB)) continue;
            RVisit[nextR.y][nextR.x] = true;
            BVisit[nextB.y][nextB.x] = true;
            
            if(board[nextR.y][nextR.x] == 3) redEnd = true;
            if(board[nextB.y][nextB.x] == 4) blueEnd = true;
            
            // 가장 적게 걸리는 턴 수 저장
            answer = min(answer, dfs(nextR, nextB, cnt + 1));
            
            // 방문 기록 및 도착 기록 초기화
            redEnd = false;
            blueEnd = false;
            RVisit[nextR.y][nextR.x] = false;
            BVisit[nextB.y][nextB.x] = false;
        }
    }
    return answer;
}

int solution(vector<vector<int>> maze) {
    
    Node RSt, BSt;
    length = maze.size();
    width = maze[0].size();
    board = maze;
    
    for(int y = 0; y < length; y++){
        for(int x = 0; x < width; x++){
            switch(maze[y][x]){
                case 1 :
                    RSt = {y,x};
                    break;
                case 2 :
                    BSt = {y,x};
                    break;
            }
        }
    }
    
    RVisit[RSt.y][RSt.x] = true;
    BVisit[BSt.y][BSt.x] = true;
    int answer = dfs(RSt, BSt, 0);
    return (answer == MAX) ? 0 : answer;
    return answer;
}