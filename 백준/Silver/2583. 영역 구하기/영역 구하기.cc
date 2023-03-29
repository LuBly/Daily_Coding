//[Baekjoon C++] 영역 구하기 [DFS]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int height, length, cnt;
int area_cnt=0, area_size=1;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
bool map[101][101];
bool is_visited[101][101] = {false};

void dfs(int y,int x){
    is_visited[y][x]=true;
    for(int j=0;j<4;j++){
        int ny=y+dy[j];
        int nx=x+dx[j];
        if(ny>=height||nx>=length||ny<0||nx<0) continue;
        if(map[ny][nx] && !is_visited[ny][nx]){
            area_size++;
            dfs(ny,nx);
        }
    }
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    vector<int> result;

    cin>>height>>length>>cnt;
    fill_n(&map[0][0],101*101,true); // map 배열을 true로 초기화
    
    for(int k=0;k<cnt;k++){          // 좌표를 입력받으면서 색칠된 직사각형 위치의 map 정보를 false로 변경
        int sx,sy,nx,ny;
        cin>>sx>>sy>>nx>>ny;
        for(int a=sy;a<ny;a++){
            for(int b=sx;b<nx;b++){
                map[a][b]=false;
            }
        }
    }

    for(int p=0;p<height;p++){
        for(int q=0;q<length;q++){
            if(map[p][q]&&!is_visited[p][q]){
                dfs(p,q);
                area_cnt++;
                result.push_back(area_size);
                area_size=1;
            }
        }
    }
    sort(result.begin(),result.end());

    cout<<area_cnt<<endl;
    for(auto iter:result)
        cout<<iter<<" ";
}