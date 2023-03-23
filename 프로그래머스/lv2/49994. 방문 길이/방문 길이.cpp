#include <string>
#include <iostream>
using namespace std;

int solution(string dirs) {//U: y+1, D: y-1, L: x-1, R: x+1
    int x=5,y=5,answer = 0;//index로 데이터를 관리하니 x와 y의 값을 0 0 이 아닌 중앙값인 5 5로 설정해줘야 한다.
    bool data[11][11][11][11];//출발 x,y  도착 x,y
    fill_n(&data[0][0][0][0],11*11*11*11,0);//data 배열을 false로 초기화
    
    for(int k=0; k<dirs.size();k++){
        //next X, next Y를 선언하고 x,y를 대입
        int nx=x,ny=y;
        //입력값 체크 && 좌표평면 밖으로 벗어나는 경우엔 해당 문자열 skip
        if(dirs[k]=='U'&&y<10) ny++; 
        if(dirs[k]=='D'&&y>0) ny--;
        if(dirs[k]=='L'&&x>0) nx--;
        if(dirs[k]=='R'&&x<10) nx++;
        
        //cout<<x<<" "<<y<<" "<<nx<<" "<<ny<<" result: "<<data[x][y][nx][ny]<<endl;
        if(nx==x&&ny==y) continue;//좌표의 변화가 없으면 좌표평면 밖으로 나가는 명령임을 확인하고 continue.
        if(!data[x][y][nx][ny]) {
            data[x][y][nx][ny]=true;
            data[nx][ny][x][y]=true;
            answer++;
        }
        x=nx; y=ny;
    }
    return answer;
}