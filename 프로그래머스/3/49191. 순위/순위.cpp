#include <string>
#include <vector>

using namespace std;
// 플로이드 워셜의 활용?
//   1 2 3 4 5
// 1 0 1 0 0 0
// 2 0 0 0 0 1
// 3 0 1 0 0 0
// 4 0 1 1 0 2
// 5 0 0 0 0 0 
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<bool>> board(n+1, vector<bool>(n+1, false));
    for(int k = 0; k < results.size(); k++){
        int win = results[k][0];
        int lose = results[k][1];
        
        board[win][lose] = true;
    }
    
    for(int adj = 1; adj <= n; adj++){
        for(int from = 1; from <= n; from++){
            for(int to = 1; to <=n; to++){
                if(board[from][adj] && board[adj][to])
                    board[from][to] = true;
            }
        }
    }
    
    for(int from = 1; from <= n; from++){
        int count = 0;
        for(int to = 1; to <=n; to++){
            if(board[from][to] || board[to][from])
                count++;
        }
        if(count == n-1) answer++;
    }
    
    return answer;
}