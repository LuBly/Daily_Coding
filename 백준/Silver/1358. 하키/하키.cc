//[Baekjoon C++] 하키 [기하학]
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int w, h, x, y, p;
bool checkSq(int px, int py){//직사각형 내부에 있는지 check
    return (px>=x&&px<=x+w)&&(py>=y&&py<=y+h);
}

bool checkCir(int px, int py){
    //원의 부등식 (x-X)^2+(y-(Y+h/2))^2<=(h/2)^2
    int X = (px-x)*(px-x), Y = (py-(y+h/2))*(py-(y+h/2)), R = (h/2) * (h/2);
    return X+Y<=R;
    /*
    if((pow(px-x,2)+pow(py-(y+h/2),2))<=pow((h/2),2)) return true;
    return false;
    */
}


int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>w>>h>>x>>y>>p;
    int answer = 0;
    for(int k=0;k<p;k++){
        int px,py;//플레이어 좌표
        cin>>px>>py;
        if(checkSq(px,py)){ 
            answer++;
            continue;
        }
        if(checkCir((px < x) ? px : px - w, py)){ 
            answer++;
            continue;
        }
    }
    cout<<answer;
}