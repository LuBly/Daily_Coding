//[Baekjoon C++] 뱀과 사다리 게임 [그래프와 순회]
#include <iostream>
#include <queue>
using namespace std;

// ledder과 snake 정보는 0으로 초기화
// data가 없으면 무시 있으면 타고 왔다갔다
int ledderSnake[101]={0,};
bool visited[101]={false,};

void bfs(){
    queue<pair<int,int>> q;
    q.push({1,0});
    visited[1]=true;
    while(!q.empty()){
        int curPos = q.front().first;
        int curCnt = q.front().second;
        q.pop();
        if(curPos == 100){
            cout<<curCnt;
            break;
        }
        //주사위 굴리기
        for(int dice=1;dice<=6;dice++){
            int nx = curPos+dice;
            //예외 처리(메모리 관리)
            if(nx>100||visited[nx]) 
                continue;
            //사다리나 뱀을 만났을 때 현재 위치 이동.
            if(ledderSnake[nx]!=0)
                nx = ledderSnake[nx];
            q.push({nx,curCnt+1});
            visited[nx]=true;
        }
    }
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int ledderCnt, snakeCnt;
    cin>>ledderCnt>>snakeCnt;
    for(int k=0;k<ledderCnt+snakeCnt;k++){
        int st, dt;
        cin>>st>>dt;
        ledderSnake[st]=dt;
    }
    //bfs 탐색
    bfs();
}