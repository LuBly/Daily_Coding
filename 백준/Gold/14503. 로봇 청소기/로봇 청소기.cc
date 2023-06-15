//[Baekjoon C++] 로봇 청소기 [구현]
#include <iostream>
#include <vector>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int height, width, cnt=0;
    cin>>height>>width;
    pair<pair<int,int>, int> robot_data;//로봇의 좌표와 방향 0->북, 1->동, 2->남, 3->서
    vector<vector<int>> board(height,vector<int>(width,0));//height, width size의 벡터 생성
    cin>>robot_data.first.first>>robot_data.first.second>>robot_data.second;
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++)
            cin>>board[y][x];
        
    }
    //주어진 조건대로 반복문을 설정
    int dy[4]={-1,0,1,0};
    int dx[4]={0,1,0,-1};
    while(true){
        //1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
        int curY=robot_data.first.first, curX=robot_data.first.second, dir=robot_data.second;
        if(board[curY][curX]==0){
            board[curY][curX]=2;//청소된 구역을 2로 설정
            cnt++;//청소하는 칸 개수 ++
        }

        //주변에 이동할 수 있는 빈칸이 있는지 check
        int can_move = false;
        for(int k=0;k<4;k++){
            int ny=curY+dy[k];
            int nx=curX+dx[k];
            //if(ny<0||nx<0||ny>=height||nx>=width) continue;
            if(board[ny][nx]==0){//청소되지 않은 빈칸이라면 이동 ㄱㄴ
                can_move=true;
                break;
            }
        }

        //2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
        if(!can_move){
            int ndir = (dir+2)%4;//후진 이동
            int ny = curY+dy[ndir];
            int nx = curX+dx[ndir];

            if(board[ny][nx]!=1){//벽이 아니라면 이동
                //로봇의 위치 변경
                robot_data.first.first = ny;
                robot_data.first.second = nx;
                //한칸 후진하고 1번으로 돌아간다.
                continue;
            }
            break;//벽이라면 작동을 멈춘다.
        }
        //3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
        else{
            while(true){
                int ndir = (dir+3)%4;//반시계방향으로 회전
                int ny = curY+dy[ndir];
                int nx = curX+dx[ndir];
                if(board[ny][nx]==0){
                    robot_data.first.first = ny;
                    robot_data.first.second = nx;
                    robot_data.second = ndir;
                    break;
                }
                else dir = ndir;
            }
        }

    }
    cout<<cnt<<'\n';
}