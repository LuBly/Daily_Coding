//[Baekjoon C++] 강의실 배정 [구현]
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin>>N;
    vector<pair<int,int>> data;
    for(int k=0;k<N;k++){
        int start, fin;
        cin>>start>>fin;
        data.push_back({start,fin});
    }
    //강의를 최대 몇개까지 들을 수 있냐 X
    //모든 강의를 위해서 최소 몇 개의 강의실이 필요한가

    sort(data.begin(),data.end());
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int k=0;k<N;k++){
        //강의가 끝나는 시간들을 pq에 push
        pq.push(data[k].second);
        //가장 빨리 끝나는 강의가 다음 강의의 시작시간보다 이르면 해당 강의실 사용 가능
        if(pq.top()<=data[k].first) pq.pop();
    }
    cout<<pq.size();
}