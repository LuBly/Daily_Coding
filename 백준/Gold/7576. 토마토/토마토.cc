//[Baekjoon C++] 토마토 [BFS]
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int width, length;//가로, 세로, 높이

int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};

int map[1001][1001];//map 데이터 생성
bool is_visited[1001][1001] = {false};//dfs 사용을 위한 방문 여부 체크 bool
int path[1001][1001];
queue<pair<int,int>> q;
void BFS(){
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny>=length||nx>=width||ny<0||nx<0) continue;
            if(map[ny][nx]==0&&!is_visited[ny][nx]){
                is_visited[ny][nx]=true;
                q.push(make_pair(ny,nx));
                path[ny][nx]=path[y][x]+1;
            }
        }
    }
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>width>>length;
    
    for(int k=0;k<length;k++){
        for(int j=0;j<width;j++)
            cin>>map[k][j];
    }
    
    //익은 토마토를 찾아 BFS의 출발지로 queue에 삽입
    for(int k=0;k<length;k++){
        for(int j=0;j<width;j++){
            if(map[k][j]==1){
                q.push(make_pair(k,j));
            }
        }
    }

    BFS();// bfs 수행
    
    //익지 않은 토마토가 있다면 -1 출력
    for(int k=0;k<length;k++){
        for(int j=0;j<width;j++){
            if(map[k][j]==0&&path[k][j]==0){ //익지 않은 토마토가 있으나 방문한적이 없을 경우
                cout<<-1;
                return 0;
            }
        }
    }

    //방문일자 저장 배열 중 최대값 출력
    int answer=-1;
    for(int k=0;k<length;k++){
        for(int j=0;j<width;j++){
            if(path[k][j]>answer){ //익지 않은 토마토가 있으나 방문한적이 없을 경우
                answer=path[k][j];                
            }
        }
    }
    cout<<answer;
}