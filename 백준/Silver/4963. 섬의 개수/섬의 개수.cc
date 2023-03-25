//[Baekjoon C++] 섬의 개수 [DFS]
#include <iostream>
#include <vector>
using namespace std;

int length, height;
int dy[8]={1,-1,0,0,1,1,-1,-1};
int dx[8]={0,0,1,-1,1,-1,-1,1};
bool map[51][51] = {false};//map 데이터 생성
bool is_visited[51][51] = {false};//dfs 사용을 위한 방문 여부 체크 bool

void dfs(int y, int x){
    is_visited[y][x]=true;
    for(int k=0;k<8;k++){
        int ny=y+dy[k];
        int nx=x+dx[k];
        if(nx>=length||nx<0||ny>=height||ny<0) continue; // 범위 밖으로 벗어나는 경우 continue
        if(map[ny][nx]&&!is_visited[ny][nx])//다음 지역이 land고, 방문x라면 다음 지역으로 이동해서 dfs 계속 수행
            dfs(ny,nx); 
    }
}

void reset(){
    for(int y=0;y<height;y++){
        for(int x=0;x<length;x++){
            map[y][x]=false;
            is_visited[y][x]=false;
        }
    }
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    while(true){
        int count = 0;
        cin>>length>>height;
        if(length==0 && height==0) break;
        reset();
        for(int k=0;k<height;k++){
            for(int j=0;j<length;j++)
                cin>>map[k][j];
        }

        for(int k=0;k<height;k++){
            for(int j=0;j<length;j++){
                if(map[k][j]&&!is_visited[k][j]){
                    dfs(k,j);
                    count++;
                }
            }
        }
        cout<<count<<'\n';
    }
}