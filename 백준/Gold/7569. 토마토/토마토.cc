//[Baekjoon C++] 토마토 [BFS]
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int width, length, height;//가로, 세로, 높이

int dz[6]={0,0,0,0,1,-1};
int dy[6]={1,-1,0,0,0,0};
int dx[6]={0,0,1,-1,0,0};

int map[101][101][101]={0,};//map 데이터 생성
bool is_visited[101][101][101] = {false};//bfs 사용을 위한 방문 여부 체크 bool
int path[101][101][101]={0,};
queue<tuple<int,int,int>> q;

void BFS(){
    while(!q.empty()){
        int z=get<0>(q.front());
        int y=get<1>(q.front());
        int x=get<2>(q.front());
        q.pop();
        for(int k=0;k<6;k++){
            int nz=z+dz[k];
            int ny=y+dy[k];
            int nx=x+dx[k];
            if(nz>=height||ny>=length||nx>=width||nz<0||ny<0||nx<0) continue;
            if(!is_visited[nz][ny][nx]&&map[nz][ny][nx]==0){//방문한적 없고 해당 지역의 토마토가 안익은 상태라면
                is_visited[nz][ny][nx]=true;
                q.push(make_tuple(nz,ny,nx));
                path[nz][ny][nx]=path[z][y][x]+1;
            }
        }
    }
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>width>>length>>height;
    
    //토마토 상자 입력
    for(int z=0;z<height;z++){
        for(int y=0;y<length;y++){
            for(int x=0;x<width;x++){
                cin>>map[z][y][x];
            }
        }
    }
    //토마토가 익은 부분 queue에 push, 시작점이 정해져 있지 않으니 모든 시작점을 사용.
    for(int z=0;z<height;z++){
        for(int y=0;y<length;y++){
            for(int x=0;x<width;x++){
                if(map[z][y][x]==1) q.push(make_tuple(z,y,x));
            }
        }
    }

    BFS();

    //안익는 토마토 check
    for(int z=0;z<height;z++){
        for(int y=0;y<length;y++){
            for(int x=0;x<width;x++){
                if(map[z][y][x]==0&&path[z][y][x]==0){//map의 데이터가 0이면서 해당 자리가 변하지 않는다면 -1 출력
                    cout<<-1;
                    return 0;
                }
            }
        }
    }

    //최대값 출력
    int answer=-1;
    for(int z=0;z<height;z++){
        for(int y=0;y<length;y++){
            for(int x=0;x<width;x++){
                if(path[z][y][x]>answer) answer=path[z][y][x];
            }
        }
    }

    cout<<answer;
}