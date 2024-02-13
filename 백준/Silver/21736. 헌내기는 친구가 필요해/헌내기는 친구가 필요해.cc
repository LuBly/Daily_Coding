//[Baekjoon C++] 헌내기는 친구가 필요해 [DFS]
#include <iostream>
#include <vector>
using namespace std;

vector<string> board;
vector<vector<bool>> isVisit;
int result = 0;
int N, M;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

void dfs(int y, int x){
    for(int k = 0; k < 4; k++){
        int ny = y + dy[k];
        int nx = x + dx[k];

        if(ny >= N || nx >= M || ny < 0 || nx < 0) continue;

        if(!isVisit[ny][nx] && board[ny][nx] != 'X'){
            isVisit[ny][nx] = true;
            if(board[ny][nx] == 'P') result++;
            dfs(ny,nx);
        }
    }
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);    
    cin >> N >> M;
    board.resize(N);
    isVisit.resize(N, vector<bool>(M, false));
    for(int y = 0; y < N; y++){
        cin >> board[y];
    }

    for(int y = 0; y < N; y++){
        for(int x = 0; x < M; x++){
            if(board[y][x] == 'I'){
                isVisit[y][x] = true;
                dfs(y,x);
                break;
            }
        }
    }
    if(result == 0) cout << "TT";
    else cout << result;
}