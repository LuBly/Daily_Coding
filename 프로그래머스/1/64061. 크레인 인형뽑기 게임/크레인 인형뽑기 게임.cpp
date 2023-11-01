#include <string>
#include <vector>
#include <stack>
using namespace std;

// stack을 활용한 문제 풀이
// moves에 해당하는 위치에서 가장 위에 있는 0이 아닌 숫자 out
// stack의 top과 비교
// 같으면 result ++
// 다르면 stack.push

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;
    for(int k = 0; k < moves.size(); k++){
        int curIdx = moves[k] -1;
        for(int j = 0; j < board.size(); j++){
            if(board[j][curIdx] != 0){
                if(st.empty()){
                    st.push(board[j][curIdx]);
                }
                
                else{
                    if(st.top() == board[j][curIdx]){
                        answer += 2;
                        st.pop();
                    }
                    else{
                        st.push(board[j][curIdx]);
                    }
                        
                }
                board[j][curIdx] = 0;
                break;
            } 
        }
    }
    
    return answer;
}