//[LCT C++] 회의실 배정 [그리디]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second==b.second) return a.first<b.first;
    return a.second < b.second;
}

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int cnt, answer=1;
    cin>>cnt;
    vector<pair<int,int>> timeline;
    for(int k=0;k<cnt;k++){
        int st, dt;
        cin>>st>>dt;
        timeline.push_back({st,dt});
    }
    //회의의 종료 시간을 기준으로 정렬
    sort(timeline.begin(),timeline.end(),cmp);

    int time = timeline[0].second;//최초로 회의가 끝나는 시간
    //회의가 끝나는 시간 이후에 다음 차례의 회의가 들어올 수 있는 경우들을 answer++;
    for(int k=1;k<=cnt;k++){
        int start = timeline[k].first;
        int end = timeline[k].second;
        if(start >= time){
            answer++;
            time = end;
        }
    }
    cout<<answer;
}
