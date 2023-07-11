//[Baekjoon C++] 정사각형 [기하학]
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int length(pair<int,int> pt1, pair<int,int> pt2){
        int x1 = pt1.first, x2 = pt2.first, y1 = pt1.second, y2 = pt2.second;
        return pow((x2-x1),2)+pow((y2-y1),2);
}
int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int testCase;
    cin>>testCase;
    for(int k=0;k<testCase;k++){
        vector<pair<int,int>> sq;
        for(int j=0;j<4;j++){
            int x, y;
            cin>>x>>y;
            sq.push_back({x,y});
        }
        sort(sq.begin(),sq.end());
        pair<int,int> LD = sq[0];
        pair<int,int> LU = sq[1];
        pair<int,int> RD = sq[2];
        pair<int,int> RU = sq[3];
        
        //4변의 길이가 모두 같고
        //대각선의 길이가 같으면 정사각형
        //두 점사이의 거리 = sqrt((x2-x1)^2+(y2-y1)^2)
        int left = length(LD,LU);//왼쪽
        int right = length(RU,RD);//오른쪽
        int bottom = length(LD,RD);//아래
        int top = length(LU,RU);//위
        int diagonal1 = length(LU,RD);
        int diagonal2 = length(LD,RU);

        if((left==right&&right==bottom&&bottom==top&&top==left)&&(diagonal1==diagonal2)){
            cout<<1<<'\n';
        }
        else cout<<0<<'\n';
    }
}