//[Baekjoon C++] 알파벳 [dfs]
#include <iostream>
using namespace std;

int height, length, answer=0;

//이동정보 배열
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};

// map_data정보를 저장하는 배열 선언
char map_data[21][21];
bool alpha_chk[26]={false};     //해당 문자가 이전에 들어왔던 문자인지 체크하기 위한 bool

void dfs(int y, int x, int cnt){
    answer = answer>cnt?answer:cnt;// dfs를 수행하면서 최대값을 찾기 위해 dfs때마다 cnt check         
    for(int a=0;a<4;a++){
        int ny=y+dy[a];
        int nx=x+dx[a];
        if(ny>=height||nx>=length||ny<0||nx<0) continue;    // 범위밖으로 이동할 경우 continue
        int cur_Alpha=map_data[ny][nx]-'A';                 // 범위 밖으로 나갈 경우의 수를 배제시킨 이후 수행
        if(!alpha_chk[cur_Alpha]){                          // 방문하지 않은 문자일 경우 진행
            alpha_chk[cur_Alpha]=true;
            dfs(ny,nx,cnt+1);
            alpha_chk[cur_Alpha]=false;                     //한번 지나가고 끝이 아닌, 아닐 경우 돌아가서 
                                                            //다시 체크를 진행하기 위해 backTracking 방법을 활용
        }
    }
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>height>>length;
    fill_n(&map_data[0][0],21*21,NULL); // map_data 배열에 아무것도 들어있지 않게 초기화.
    for(int k=0;k<height;k++){
        for(int j=0;j<length;j++){
            cin>>map_data[k][j];//입력값을 map_data에 하나씩 map_dataping.
        }
    }
    alpha_chk[map_data[0][0]-'A']=true; // 0,0 에 해당하는 alphabet은 반드시 지나므로 true로 변경
    dfs(0,0,1);
    cout<<answer;
}