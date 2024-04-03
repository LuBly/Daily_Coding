#include <string>
#include <vector>
#include <iostream>
using namespace std;
// 엄청 단순해보이는데... 
/*
1. 그냥 단순 구현
// board에 skill에 해당하는 범위만큼 + -
// 최대 시간 복잡도 skill 100회, boardsize 100*100 = 10000 -> 100 * 10000 = 1,000,000
// 효율성 x
2. 누적합을 활용한 효율성 up
// 계산용 보드를 새로 생성
// skill의 값들을 누적합을 활용해서 계산
ex) 
(1,1), (2,2) => (1,1), (3,3)에 degree와 -degree 생성
(0,0), (1,1) => (0,0), (2,2)에 degree와 -degree 생성
(2,0), (2,0) => (2,0), (3,1)에 degree와 -degree 생성
누적합 계산
좌 -> 우 / 위 -> 아래
누적합 계산한 board와 기존 board 합
*/
vector<vector<int>> G_board;

/*
void ActiveTurnEnd(pair<int,int> stPt, pair<int,int> dtPt, int degree){
    for(int y = stPt.first; y <= dtPt.first; y++){
        for(int x = stPt.second; x <= dtPt.second; x++){
            G_board[y][x] += degree;
        }
    }
}

int CheckBoard(){
    int res = 0;
    for(int y = 0; y < G_board.size(); y++){
        for(int x = 0; x < G_board[0].size(); x++){
            if(G_board[y][x] > 0){
                res++;
            }
        }
    }
    
    return res;
}
*/

void MakeCalBoard(pair<int,int> stPt, pair<int,int> dtPt, int degree){
    //각 끝자리에 degree 설정
    G_board[stPt.first][stPt.second] += degree;
    G_board[dtPt.first + 1][dtPt.second + 1] += degree;
    
    G_board[stPt.first][dtPt.second + 1] += -degree;
    G_board[dtPt.first + 1][stPt.second] += -degree;
}

void Calculate(){
    // 가로 계산
    for(int y = 0; y < G_board.size(); y++){
        for(int x = 1; x < G_board[0].size(); x++){
            G_board[y][x] = G_board[y][x-1] + G_board[y][x];
        }
    }
    
    // 세로 계산
    for(int y = 1; y < G_board.size(); y++){
        for(int x = 0; x < G_board[0].size(); x++){
            G_board[y][x] = G_board[y-1][x] + G_board[y][x];
        }
    }
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    G_board.resize(board.size()+1, vector<int>(board[0].size() + 1));
    
    for(auto skillArr : skill){
        int type = skillArr[0];
        int degree = skillArr[5];
        //y,x
        pair<int,int> startPt = {skillArr[1], skillArr[2]};
        pair<int,int> destPt = {skillArr[3], skillArr[4]};
        //ActiveTurnEnd(startPt, destPt, degree);
        if(type == 1) degree *= -1;
        MakeCalBoard(startPt, destPt, degree);
    }
    
    Calculate();
    
    int answer = 0;
    
    for(int y = 0; y < board.size(); y++){
        for(int x = 0; x < board[0].size(); x++){
            if(board[y][x] + G_board[y][x] > 0) answer++;
        }
    }
    

    
    
    return answer;
}