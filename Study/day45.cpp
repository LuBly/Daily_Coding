//[Programmers C++] 더 맵게
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    bool is_end=false;
    priority_queue<int,vector<int>,greater<int> > pq;
    for(auto iter : scoville) pq.push(iter);//scoville을 넣으면서 자동 정렬 1 2 3 9 10 12
    
    int first = pq.top();
    while((pq.size() > 1) && (first < K)){
        pq.pop();
        int second = pq.top();
        pq.pop();
        int mix = first+(second*2);
        pq.push(mix);
        answer++;
        //cout<<first<<" "<<second<<" "<<mix<<endl;
        first=pq.top();
        //cout<<"next_first: "<<first<<endl;
    }
    if(first < K) answer = -1;
    
    return answer;
}