//[Baekjoon C++] 강의실 배정 [그리디]
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;
    vector<pair<int,int>> data;
    for(int k = 0; k < N; k++){
        int st, fin;
        cin >> st >> fin;
        data.push_back(make_pair(st, fin));
    }
    sort(data.begin(), data.end());

    priority_queue<int,vector<int>,greater<int>> pq;
    for(int k=0;k<N;k++){
        //강의가 끝나는 시간들을 pq에 push
        pq.push(data[k].second);
        //가장 빨리 끝나는 강의가 다음 강의의 시작시간보다 이르면 해당 강의실 사용 가능
        if(pq.top()<=data[k].first) pq.pop();
    }
    cout<<pq.size();
}