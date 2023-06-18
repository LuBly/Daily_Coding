//[BaekJoon C++] 병든 나이트 [구현]
#include <iostream>
#include <algorithm>
using namespace std;
//가로는 항상 오른쪽으로 +1 or +2
//세로는 위 아래 이동 가능 
//4회 이동 전까지는 최대 width 6, height 3이 필요하다.
//height를 기준으로 분류
int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int height, width;
    cin>>height>>width;
    int answer;
    if(height==1)
    //높이가 1인 경우 출발점을 제외하곤 이동할 수 없다.
        answer=1;
    else if(height==2)
    //높이가 2인 경우 2->3->2->3 최대 4번까지 이동할 수 있다.
    //하지만 width에 따라 변할 수 있기 때문에 min (width+1)/2 와 비교
        answer=min(4,((width+1)/2));
    else{
        if(width>6)
        //이외의 경우엔 모든 이동방향을 사용 가능
            answer = width-2;
        else
        //가로가 6 이하인 경우 4개 이동방향 전부 사용 불가 
        //우측 1칸 이동인 방향으로 최대한 이동할 수 있는만큼 이동하는 것 = width의 수
            answer = min(4,width);
    }
    cout<<answer;
}   
