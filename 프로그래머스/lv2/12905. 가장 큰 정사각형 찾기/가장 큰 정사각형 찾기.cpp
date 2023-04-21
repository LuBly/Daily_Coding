#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    for(int y=1;y<board.size();y++){
        for(int x=1;x<board[0].size();x++){
            if(board[y][x]>0){//해당 지점이 1일 경우
                board[y][x] = min({board[y-1][x],board[y][x-1],board[y-1][x-1]})+1;
            }
        }
    }
    
    for(int y=0;y<board.size();y++){
        for(int x=0;x<board[0].size();x++){
            answer = (board[y][x]>answer) ? board[y][x] : answer;
        }
    }
    
    return answer*answer;
}