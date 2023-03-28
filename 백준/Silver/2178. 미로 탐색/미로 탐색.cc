//[Baekjoon C++] 미로 탐색 [bfs] 진행중.
//dfs로 수행할 경우 너무 많은 경우의 수를 검사해서 시간 초과
/*
#include <iostream>
using namespace std;

char map[101][101];
bool is_visited[101][101]={false};
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int height,length,answer=10001;


void dfs(int y, int x, int cnt){
    
    if(y==height-1 && x==length-1) {
        if(cnt<answer) answer=cnt;
        return;
    }
    if(y>=height||x>=length||y<0||x<0) return;
    for(int a=0;a<4;a++){
        int ny=y+dy[a];
        int nx=x+dx[a];
        
        if(!is_visited[ny][nx]&&map[ny][nx]=='1'){
            is_visited[ny][nx]=true;
            dfs(ny,nx,cnt+1);
            is_visited[ny][nx]=false;
        }
    }
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>height>>length;
    for(int k=0;k<height;k++){
        cin>>map[k];
    }
    dfs(0,0,1);
    cout<<answer;
}
*/
//BFS로 재구성해보자.
#include <iostream>
#include <queue>
using namespace std;

char map[101][101];                 // 미로 정보
bool is_visited[101][101]={false};  // 방문표시
int map_data[101][101]={0,};        // 시작점으로부터 거리 표시
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int height,length;

void BFS(int y, int x){
    is_visited[y][x]=true; // 방문 표시
    queue<pair<int,int>> q;// queue 생성
    q.push(make_pair(y,x));// 시작 점 넣기
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop(); // queue 맨 앞 데이터 제거

        for(int k=0;k<4;k++){
            int ny= y+dy[k];
            int nx= x+dx[k];
            if(ny>=height||nx>=length||ny<0||nx<0) continue;
            if(map[ny][nx]=='1'&&!is_visited[ny][nx]){//길이 존재하고 방문한적이 없는 경우
                map_data[ny][nx]=map_data[y][x]+1; // 경로 거리 정보 업데이트
                is_visited[ny][nx]=true;
                q.push(make_pair(ny,nx)); // 큐에 데이터 밀어놓고 테스트
            }
        }
    }
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>height>>length;
    for(int k=0;k<height;k++){
        cin>>map[k];
    }
    BFS(0,0);
    cout<<map_data[height-1][length-1]+1;
}