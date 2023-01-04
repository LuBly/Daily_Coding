//[Programmers C++] 크레인 인형뽑기 게임
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> box;
    for(int k=0;k<moves.size();k++){
        for(int j=0;j<board.size();j++){
            //cout<<"board["<<j<<"][moves["<<moves[k]-1<<"]: "<<board[j][moves[k]-1]<<endl;
            if(board[j][moves[k]-1]!=0) {
                if(box.empty()) {
                    box.push_back(board[j][moves[k]-1]);
                    board[j][moves[k]-1]=0;
                    break;
                }
                else{
                    if(box.back()==board[j][moves[k]-1]) {
                        box.pop_back();
                        board[j][moves[k]-1]=0;
                        answer+=2;
                        break; 
                    }
                    else{
                        box.push_back(board[j][moves[k]-1]);
                        board[j][moves[k]-1]=0;
                        break;
                    }
                }
            }
        }
    }
    return answer;
}