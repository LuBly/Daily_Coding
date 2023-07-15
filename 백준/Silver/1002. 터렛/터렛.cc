//[Baekjoon C++] 터렛 [기하학]
#include <iostream>
#include <cmath>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int test_cnt;
    cin>>test_cnt;
    for(int k=0;k<test_cnt;k++){
        int x1,y1,x2,y2,r1,r2;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        //두 원의 위치관계
        double d = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        double sub = r1>r2 ? r1-r2 : r2-r1;
        int answer;
        if(d==0 && r1==r2) answer=-1;
        else if(r1+r2==d || sub==d) answer = 1;
        else if(r1+r2>d && sub<d) answer = 2;
        else answer = 0;
        
        cout<<answer<<'\n';
    }
}