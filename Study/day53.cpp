//[Programmers C++] 땅따먹기
/*
#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int cur;
    int tmp=land[0][0];
    
    for(int b=0;b<land[0].size();b++){
        if(land[0][b]>tmp){
            cur=b;
            tmp=land[0][b];
        }
    }
    cout<<tmp<<" "<<cur<<endl;
    answer+=tmp;
    
    
    for(int a=1;a<land.size();a++){
        int max=land[a][0];//한칸씩 내려갈때마다 max값 초기화
        int max_cur=99;
        for(int b=0;b<land[a].size();b++){
            if(land[a][b]>max && cur!=b){
                max_cur=b;
                max=land[a][b];
            }
        }
        cur=max_cur;
        answer+=max;
        cout<<max<<" "<<cur<<endl;
    }

    return answer;
}
*/
////////////////그리디로 문제를 해결하려하면 최선의 값을 찾지 못할 수 있다.//////////////////
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    for(int k=1;k<land.size();k++){
        land[k][0]+=max({land[k-1][1],land[k-1][2],land[k-1][3]});
        land[k][1]+=max({land[k-1][0],land[k-1][2],land[k-1][3]});
        land[k][2]+=max({land[k-1][0],land[k-1][1],land[k-1][3]});
        land[k][3]+=max({land[k-1][0],land[k-1][1],land[k-1][2]});
    }
    answer=max({land.back()[0],land.back()[1],land.back()[2],land.back()[3]});
    
    return answer;
}