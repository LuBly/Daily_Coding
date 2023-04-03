#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];
    int width=board[0].size(), length=board.size();
    for(int k=1; k<length; k++){
        for(int j=1; j<width; j++){
            if(board[k][j]==1){//방문한 위치가 1일 경우, 해당 위치를 기점으로 위, 왼쪽, 왼 대각 위가 모두 같다면 정사각형이 구성되고, 아니라면 숫자가 낮아지므로 체크
                board[k][j]+=min({board[k-1][j],board[k][j-1],board[k-1][j-1]});
                answer = max(board[k][j],answer);
            }
        }
    }
    
    return answer*answer;
}