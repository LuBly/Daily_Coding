//[Baekjoon C++] 적록색약 [DFS]
#include <iostream>
#include <vector>
using namespace std;

char map[101][101];
char map_edit[101][101];
int is_visited[101][101]={false};
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int area_size;

void orig_dfs(int y, int x){
    is_visited[y][x]=true;
    for(int k=0;k<4;k++){
        int ny=y+dy[k];
        int nx=x+dx[k];
        if(nx>=area_size||nx<0||ny>=area_size||ny<0) continue; // 범위 밖으로 벗어나는 경우 continue
        if(map[ny][nx]==map[y][x]&&!is_visited[ny][nx])//다음 지역이 land고, 방문x라면 다음 지역으로 이동해서 dfs 계속 수행
            orig_dfs(ny,nx); 
    }
}

void edit_dfs(int y, int x){
    is_visited[y][x]=true;
    for(int k=0;k<4;k++){
        int ny=y+dy[k];
        int nx=x+dx[k];
        if(nx>=area_size||nx<0||ny>=area_size||ny<0) continue; // 범위 밖으로 벗어나는 경우 continue
        if(map_edit[ny][nx]==map_edit[y][x]&&!is_visited[ny][nx])//다음 지역이 land고, 방문x라면 다음 지역으로 이동해서 dfs 계속 수행
            edit_dfs(ny,nx); 
    }
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>area_size;
    fill_n(&map[0][0],101*101,'Z');//map 배열을 Z로 초기화
    fill_n(&map_edit[0][0],101*101,'Z');//edit_map 배열을 Z로 초기화

    for(int k=0;k<area_size;k++){
        for(int j=0;j<area_size;j++){
            char tmp;
            cin>>tmp;
            map[k][j]=tmp;          // 정상 입력
            if(tmp=='R') tmp='G';   // 적록 색약을 위한 map에 입력해줄 값 변형(RG를 모두 G로 통일)
            map_edit[k][j]=tmp;     // 색약 입력
        }
    }
    int orig_cnt=0;
    for(int k=0;k<area_size;k++){
        for(int j=0;j<area_size;j++){
            if(!is_visited[k][j]){
                orig_dfs(k,j);
                orig_cnt++;
            }
        }
    }
    fill_n(&is_visited[0][0],101*101,0);// 색약 cnt를 세기위해 is_visited 초기화

    int edit_cnt=0;
    for(int k=0;k<area_size;k++){
        for(int j=0;j<area_size;j++){
            if(!is_visited[k][j]){
                edit_dfs(k,j);
                edit_cnt++;
            }
        }
    }

    cout<<orig_cnt<<" "<<edit_cnt;
}