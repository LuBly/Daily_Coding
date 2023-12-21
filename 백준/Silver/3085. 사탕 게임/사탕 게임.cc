//[Baekjoon C++] 사탕 게임 [구현]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bomboni(vector<string> board){
    int rMax = 0, cMax = 0;
    
    // X좌표를 기준으로 세로줄 판별
    for(int x = 0; x < board[0].size(); x++){
        int tmpMax = 1;
        char curWord = board[0][x];
        for(int y = 1; y < board.size(); y++){
            if(board[y][x] == curWord) tmpMax++;
            else{
                curWord = board[y][x];
                rMax = max(rMax, tmpMax);
                tmpMax = 1;
            }
        }
        if(tmpMax != 1) rMax = max(rMax, tmpMax);
    }
    
    // Y좌표를 기준으로 세로줄 판별
    for(int y = 0; y < board.size(); y++){
        int tmpMax = 1;
        char curWord = board[y][0];
        for(int x = 1; x < board.size(); x++){
            if(board[y][x] == curWord) tmpMax++;
            else{
                curWord = board[y][x];
                cMax = max(cMax, tmpMax);
                tmpMax = 1;
            }
        }
        if(tmpMax != 1) cMax = max(cMax, tmpMax);
    }

    return max(rMax, cMax);
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int size;
    cin >> size;

    vector<string> board(size);

    for(int y = 0; y < size; y++){
        cin >> board[y];
    }

    //우측과 아래방향으로만 체크
    int res = bomboni(board);

    for(int y = 0; y < size; y++){
        for(int x = 0; x < size; x++){
            if(y < size-1){
                if(board[y][x] != board[y+1][x]){
                    swap(board[y+1][x], board[y][x]);
                    res = max(res, bomboni(board));
                    swap(board[y+1][x], board[y][x]);
                }
            }
            

            if(x < size - 1){
                if(board[y][x] != board[y][x+1]){
                    swap(board[y][x + 1], board[y][x]);
                    res = max(res, bomboni(board));
                    swap(board[y][x + 1], board[y][x]);
                }
            }
            
        }
    }

    cout << res;

    /*
    func) 보드에서 가장 긴 부분을 체크
    1. 색이 다른 인접한 두 칸 한번씩 바꿔서 모든 줄 체크 (2500 * 2500) 
    */
}