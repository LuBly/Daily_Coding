//[Baekjoon C++] 탈출 [DFS]
#include <iostream>
#include <vector>
#define MAX_ROW 10001
#define MAX_COL 501
using namespace std;

// row : y
// col : x
// BFS로 가장 아래열의 cost들을 모두 더하면 정답
int row, col, answer = 0; 
bool check;

int dy[3] = {-1,0,1};
int dx[3] = {1,1,1};

vector<string> map(MAX_ROW);
vector<vector<bool>> isVisit(MAX_ROW, vector<bool> (MAX_COL, false)); // isVisit[ROW][COL]
void dfs(int y, int x){
    isVisit[y][x] = true;
    if(x == col-1){
        answer++;
        check = true;
        return;
    }

    for(int k = 0; k < 3; k++){
        int ny = y + dy[k];
        int nx = x + dx[k];
        if(ny >= row || nx >= col || ny < 0 || nx < 0) continue;

        if(map[ny][nx] == '.' && !isVisit[ny][nx]){
            dfs(ny, nx);
            if(check) return;
        }
    }
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);    
    cin >> row >> col;
    for(int k = 0 ; k < row; k++){
        cin >> map[k];
    }

    // 모든 파이프라인은 첫째 열에서 시작
    for(int y = 0; y < row; y++){
        // 건물이 있는 경우 설치 불가
        if(map[y][0] == 'x') continue;
        check = false;
        dfs(y,0);
    }
    
    cout << answer;
}