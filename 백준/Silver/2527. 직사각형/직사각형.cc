//[Baekjoon C++] 직사각형 [기하학]
#include <iostream>
#include <algorithm>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    for(int k=0;k<4;k++){
        int x1,y1,p1,q1,x2,y2,p2,q2;
        cin>>x1>>y1>>p1>>q1>>x2>>y2>>p2>>q2;
        int xl = max(x1,x2);
        int xr = min(p1,p2);
        int yb = max(y1,y2);
        int yt = min(q1,q2);

        int xdiff = xr-xl;
        int ydiff = yt-yb;

        if(xdiff>0&&ydiff>0) cout<<'a'<<'\n';
        else if(xdiff<0||ydiff<0)cout<<'d'<<'\n';
        else if(xdiff==0&&ydiff==0)cout<<'c'<<'\n';
        else cout<<'b'<<'\n';
    }
}