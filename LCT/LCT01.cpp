//[LCT C++] 모험가 길드 [그리디 알고리즘] 311p(157), 정답 506p()
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int cnt, answer=0;
    cin>>cnt;

    vector<int> group;
    for(int k=0;k<cnt;k++){
        int n;
        cin>>n;
        group.push_back(n);
    }
    sort(group.begin(),group.end());
    //1 2 2 2 3
    //1. 정렬
    //2. 앞에서 부터 조건을 만족하는지 체크하면서 순회
    //ex) 1, 2 2 , 2 3 (x)=>2
    int group_cnt=0;// 해당 그룹 현재 인원
    for(int k=0;k<group.size();k++){
        group_cnt++;
        if(group_cnt>=group[k]){
            answer++;
            group_cnt=0;
        }
    }

    cout<<answer;
}
