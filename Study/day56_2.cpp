//[Programmers c++] 가장 큰 정사각형 찾기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer=board[0][0];
    for(int a=1;a<board.size();a++){
        for(int b=1;b<board[a].size();b++){
            if(board[a][b]==1){
                board[a][b] += min({board[a-1][b],board[a][b-1],board[a-1][b-1]});
                answer = max(board[a][b],answer);
            }
        }
    }
    
    answer*=answer;
    return answer;
}