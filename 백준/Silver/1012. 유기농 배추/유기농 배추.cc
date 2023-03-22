//[Baekjoon C++] 유기농 배추 [DFS]
#include <iostream>
using namespace std;

int Length,Height,Count;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool map[51][51] = {false};//1=true, 0=false 밭 데이터
bool is_visited[51][51] = {false};

void reset(){
    for(int k=0; k<Height; k++){
        for(int j=0;j<Length;j++){
            map[k][j]=false;
            is_visited[k][j]=false;
        }
    }
}


void dfs(int y,int x){
    is_visited[y][x]=true;
    for(int p=0;p<4;p++){//상하좌우 4개의 방향 check
        int nx=x+dx[p];
        int ny=y+dy[p];
        if(nx>=Length||ny>=Height||nx<0||ny<0) continue;
        //방문 x 이고 배추가 있다면 계속 탐색
        if(map[ny][nx]&&!is_visited[ny][nx])
            dfs(ny,nx);
        
    }
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int TestCase;
    cin>>TestCase;

    for(int n=0;n<TestCase;n++){
        int Answer=0;
        cin>>Length>>Height>>Count;
        reset();
        for(int k=0;k<Count;k++){
            int a,b;
            cin>>a>>b;
            map[b][a]=true;
        }
    
        for(int i=0;i<Height;i++){
            for(int j=0;j<Length;j++){
                if(map[i][j]&&!is_visited[i][j]){//matrix를 전체 탐색하면서 방문하지 않은 node를 찾는다. 1(배추)
                    dfs(i,j);//해당 배추를 기준으로 상하좌우 dfs를 수행
                    //->dfs를 수행하면서 방문한 node들의 is_visited를 전부 true로 변경
                    Answer++;//덩어리별로 Answer++
                }
            }
        }
        cout<<Answer<<'\n';
    }
}