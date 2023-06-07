//[Baekjoon C++] 봄버맨 [구현]
#include <iostream>
#include <vector>
using namespace std;

// 초단위로 폭탄의 상태를 갱신
// 폭탄을 int 3으로 계산
// 시간이 지날때마다 -1
// 시간이 모두 지났을 때 board_int 갱신
// 최대 반복 200 * 200 * 200 = 8,000,000 
// 일반적인 TLE인 1억의 한참 아래.
// 문제를 있는 그대로 따라가보자.
int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int height, width, sec, time=0;
    cin>>height>>width>>sec;
    vector<vector<int>> board_int(height,vector<int>(width,0));
    vector<vector<char>> board_char(height,vector<char>(width,'.'));
    vector<vector<bool>> bomb_area(height,vector<bool>(width,false));
    
    

    //height, width인 board_int, 와 board_char생성 = 초기 설치
    for(int y=0;y<height;y++){
        string tmp_str;
        cin>>tmp_str;
        for(int x=0;x<width;x++){
            if(tmp_str[x]=='O'){
                board_int[y][x] = 2;//초기 설치이후 1초동안 아무것도 안하기 때문에 타이머를 미리 한칸 돌려놓는다.
                board_char[y][x] = 'O';
            }
        }
    }
    time++;//다음 1초동안 아무것도 하지않는다.
    
    //폭탄이 터질 방향 배열
    int dy[4]={1,-1,0,0};
    int dx[4]={0,0,1,-1};
    
    // 초 단위로 판단.1초 부터 시작
    // 초가 0인 폭탄이 먼저 터지고, 이후에 폭탄을 설치 1초+
    // 중점: 설치는 초가 시작할 때, 폭발은 초가 끝날 때
    while(time<sec){
        //다음 1초동안 폭탄이 설치되지 않은 모든 칸에 폭탄을 설치한다.
        //->1. 해당 초에 터질 폭탄 터트리기 2. 빈 자리에 폭탄 설치
        //하나의 반복문에서 처리할 경우 동시 처리가 어려울 수 있어 일단 반복문을 나눠서 구현하고자 함

        //폭탄이 터질 자리 판단하기
        for(int y=0;y<height;y++){
            for(int x=0;x<width;x++){
                if(board_char[y][x]=='O'&&board_int[y][x]==0){
                    bomb_area[y][x]=true;
                    for(int k=0;k<4;k++){
                        int ny = y+dy[k];
                        int nx = x+dx[k];
                        if(ny<0||nx<0||ny>=height||nx>=width) continue;//범위 밖으로 나가는 좌표들 관리
                        bomb_area[ny][nx]=true;
                    }
                }
            }
        }
        //폭발 구역 board에 최신화
        for(int y=0;y<height;y++){
            for(int x=0;x<width;x++){
                if(bomb_area[y][x]){
                    board_int[y][x]=0;
                    board_char[y][x]='.';
                    bomb_area[y][x]=false;
                }
            }
        } 
        //모든 폭탄이 터지고 빈자리에 폭탄 설치하는 과정 + 폭탄이 설치된 경우 폭탄 카운트 -1
        for(int y=0;y<height;y++){
            for(int x=0;x<width;x++){
                if(board_char[y][x]=='.'){
                    board_char[y][x]='O';
                    board_int[y][x]=3;
                }
                else
                    board_int[y][x]--;
            }
        }  
        time++;
    }

    //반복문 종료 이후 폭발해야하는 폭탄 폭발
    //폭탄이 터질 자리 판단하기
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            if(board_char[y][x]=='O'&&board_int[y][x]==0){
                bomb_area[y][x]=true;
                for(int k=0;k<4;k++){
                    int ny = y+dy[k];
                    int nx = x+dx[k];
                    if(ny<0||nx<0||ny>=height||nx>=width) continue;//범위 밖으로 나가는 좌표들 관리
                    bomb_area[ny][nx]=true;
                }
            }
        }
    }
    //폭발 구역 board에 최신화
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            if(bomb_area[y][x]){
                board_int[y][x]=0;
                board_char[y][x]='.';
                bomb_area[y][x]=false;
            }
        }
    } 

    //결과 출력
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            cout<<board_char[y][x];
        }
        cout<<'\n';
    }
}