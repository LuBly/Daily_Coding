//[Baekjoon C++] 인구 이동 [구현]
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> board;
vector<vector<bool>> isVisit;
int Land_size, diff_L, diff_R;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

struct Point{
    int y;
    int x;
    int count;
};

bool bfs(int y, int x){
    bool isMove = false;
    isVisit[y][x] = true;
    queue<Point> q;
    vector<pair<int,int>> visitPoint;
    q.push({y, x, board[y][x]});
    visitPoint.push_back({y,x});
    int uCnt = 1;
    int uPeople = board[y][x];

    while(!q.empty()){
        int cy = q.front().y;
        int cx = q.front().x;
        int cCount = q.front().count;
        q.pop();
        for(int k = 0; k < 4; k++){
            int ny = cy + dy[k];
            int nx = cx + dx[k];

            if(ny >= Land_size || nx >= Land_size || ny < 0 || nx < 0) continue;
            
            int nCount = board[ny][nx];
            int diff = cCount - nCount;
            if(diff < 0) diff *= -1;
            if(!isVisit[ny][nx] && (diff <= diff_R && diff >= diff_L)){
                q.push({ny,nx,nCount});
                isVisit[ny][nx] = true;
                visitPoint.push_back({ny, nx});
                isMove = true;
                uCnt++;
                uPeople += nCount;
            }
        }
    }
    if(isMove){
        for(auto iter : visitPoint){
            board[iter.first][iter.second] = uPeople / uCnt;
        }
    }

    return isMove;
}
void InitVisitData(){
    for(int y = 0; y < Land_size; y++){
        for(int x = 0; x < Land_size; x++){
            isVisit[y][x] = false;
        }
    }
}
int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);    
    cin>>Land_size>>diff_L>>diff_R;
    board.resize(Land_size,vector<int>(Land_size,0));
    isVisit.resize(Land_size,vector<bool>(Land_size,false));

    for(int y=0;y<Land_size;y++){
        for(int x=0;x<Land_size;x++)
            cin>>board[y][x];
    }

    int result = 0;
    while(true){
        bool isMove = false;
        InitVisitData();

        for(int y = 0; y < Land_size; y++){
            for(int x = 0;x < Land_size; x++){
                if(!isVisit[y][x]){           
                    if(bfs(y,x)){
                        isMove = true;
                    }
                }
            }
        }


        if(isMove) result++;
        else break;
    }

    cout << result;
}