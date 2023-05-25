//[Baekjoon C++] 빙산 [BFS/DFS]
#include <iostream>
#include <vector>
using namespace std;

int length, width;
//dfs로 연결된 모든 친구들을 탐색하면서 -1
bool is_visit[301][301]={false,};
int map[301][301]={0,};
int melt[301][301]={0,};
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
void dfs(pair<int,int> start){
    int y = start.first, x = start.second;
    is_visit[y][x] = true;
    for(int k=0;k<4;k++){
        int ny = y + dy[k];
        int nx = x + dx[k];
        if(ny>=length||nx>=width||ny<0||nx<0) continue;
        if(!is_visit[ny][nx]&&map[ny][nx]>0){
            dfs({ny,nx});
        }
    }
}

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>length>>width;
    for(int y=0;y<length;y++){//map 구성
        for(int x=0;x<width;x++){
            cin>>map[y][x];
        }
    }
    
    int answer = 0;
    while(true){
        fill_n(&is_visit[0][0],301*301,false);
        fill_n(&melt[0][0],301*301,0);
        int cnt = 0;
        for(int y=0;y<length;y++){//map 탐색
            for(int x=0;x<width;x++){
                if(map[y][x]>0&&!is_visit[y][x]){
                    dfs({y,x});
                    cnt++;
                }                  
            }
        }
        if(cnt==0){ 
            answer=0;
            break;
        }
        if(cnt>=2) break;
        answer++;
        for(int y=0;y<length;y++){//절차별로 녹는 정도 파악
            for(int x=0;x<width;x++){
                for(int i=0;i<4;i++){
                    int ny = y+dy[i];
                    int nx = x+dx[i];
                    if(ny>=length||nx>=width||ny<0||nx<0) continue;
                    if(map[ny][nx]==0) melt[y][x]++;
                }            
            }
        }
        
        for(int y=0;y<length;y++){//동시에 녹여버리기
            for(int x=0;x<width;x++){
                if(map[y][x]<melt[y][x])
                    map[y][x] = 0;
                else 
                    map[y][x]-=melt[y][x];  
            }         
        }
    }
    cout<<answer;
}
