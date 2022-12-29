//[Programmers C++] 최소직사각형
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    for(int k=0;k<sizes.size();k++){//가로를 전부 짧은쪽으로 정렬
        sort(sizes[k].begin(),sizes[k].end());
        //cout<<k<<" "<<sizes[k][0]<<" "<<sizes[k][1]<<endl;
    }
    int max_x=sizes[0][0];
    int max_y=sizes[0][1];
    
    for(int k=1;k<sizes.size();k++){//가로 최대값과 세로 최대값 찾기.
        if(sizes[k][0]>max_x) max_x=sizes[k][0];
        if(sizes[k][1]>max_y) max_y=sizes[k][1];
        //cout<<"k: "<<k<<" max_x: "<<max_x<<" max_y: "<<max_y<<endl;
    }
    
    answer=max_x*max_y;
    return answer;
}