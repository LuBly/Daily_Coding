//[BaekJoon C++] 음식물 피하기 [그래프 이론]
#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

char map[MAX][MAX] = {'.',};
bool isVisit[MAX][MAX] = {false,};
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int length, width, cnt, curTrash;
void dfs(int y, int x){
    curTrash++;
    isVisit[y][x]=true;
    for(int k=0;k<4;k++){
        int ny = y + dy[k];
        int nx = x + dx[k];
        //범위 밖으로 나가는 경우 스킵
        if(ny>length||nx>width||ny<=0||nx<=0) continue;

        //연결되어 있는 쓰래기 이어붙이기
        if(map[ny][nx]=='#'&&!isVisit[ny][nx]){
            dfs(ny,nx);
        }
    }
}

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>length>>width>>cnt;

    for(int k = 0; k < cnt; k++){
        int x, y;
        cin>>y>>x;
        map[y][x]='#';
    }

    int maxTrash=0;
    for(int y = 1; y <= length; y++){
        for(int x = 1; x <= width; x++){
            if(map[y][x]=='#'&&!isVisit[y][x]){
                //음식물 쓰래기의 size 초기화
                curTrash = 0;
                //dfs를 활용하여 연결된 음식물 쓰래기의 크기 도출
                dfs(y,x);
                maxTrash = max(maxTrash,curTrash);
            }
        }
    }
    cout<<maxTrash;
}    