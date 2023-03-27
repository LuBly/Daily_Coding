//[Baekjoon C++] 안전 영역 [DFS]
#include <iostream>
#include <set>
using namespace std;

int N,height;
int map[101][101]={0,};
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
bool is_visited[101][101]={false};
set<int> height_set;

void dfs(int y,int x){
    is_visited[y][x]=true;
    for(int a=0;a<4;a++){
        int ny=y+dy[a];
        int nx=x+dx[a];
        if(ny>=N||nx>=N||ny<0||nx<0) continue;
        if(!is_visited[ny][nx]&&map[ny][nx]>height){//방문 안했고, N보다 큰 지역이라면 체크
            dfs(ny,nx);
        }
    }
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>N;
    for(int k=0;k<N;k++){
        for(int j=0;j<N;j++){
            int tmp;
            cin>>tmp;
            map[k][j]=tmp;
            height_set.insert(tmp);//높이정보를 통해 비교하기 위해 set을 활용하기로 함
        }
    }

    int answer=1;
    for(auto iter:height_set){
        fill_n(&is_visited[0][0],101*101,0);
        int count=0;
        height=iter;
        for(int k=0;k<N;k++){
            for(int j=0;j<N;j++){
                if(map[k][j]>height&&!is_visited[k][j]){
                dfs(k,j);
                count++;
                }
            }
        }
        answer = count>answer ? count : answer; //count가 이전에 센 값보다 크다면 대체 아니라면 그대로
    }

    cout<<answer;
}