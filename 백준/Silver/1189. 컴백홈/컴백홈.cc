//[Baekjoon C++] 컴백홈 [dfs]
#include <iostream>
#include <vector>
using namespace std;



vector<string> board;
vector<vector<bool>> isVisit;
int length, width, cost;
int answer = 0;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

void dfs(int y, int x, int cnt){
    if(cnt == cost){
        if(y == 0 && x == width - 1){
            answer++;
            return;
        }
    }
    
    for(int k = 0; k < 4; k++){
        int ny = y + dy[k];
        int nx = x + dx[k];
        if(ny >= length || nx >= width || ny < 0 || nx < 0) continue;

        if(board[ny][nx] != 'T' && !isVisit[ny][nx]){
            isVisit[ny][nx] = true;
            dfs(ny,nx,cnt+1);
            isVisit[ny][nx] = false;
        }
    }
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> length >> width >> cost;
    board.resize(length);
    isVisit.resize(length, vector<bool>(width, false));

    for(int y = 0; y < length; y++){
        cin >> board[y];
    }

    isVisit[length-1][0] = true;
    dfs(length-1, 0, 1);

    cout << answer;
}