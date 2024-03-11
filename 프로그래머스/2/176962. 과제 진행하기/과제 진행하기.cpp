/*
1. 시작 순서대로 정렬한다.

2. 현재 할 수 있는 일이 걸리는 시간과 과 다음 일의 시작시간까지의 시간을 비교한다.

3-1. 만약 일을 다 하고도 시간이 남으면 처리하지 못한 일의 stack의 top에서부터 일을 다음 일의 시작시간 전까지 처리한다.

3-2. 일을 다 하지 못하고 다음 일의 시작시간이 된다면 현재 하고 있던 일을 stack에 push 한다.

4. 마지막 일은 바로 끝낸다.

5. 남은 stack에 있는 일을 순차적으로 진행한다.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stack>
using namespace std;

typedef struct _node{
    string name;
    int start;
    int takes;
}node;

node arr[1001];
stack <node> s;
bool cmp(node a, node b){
    return a.start < b.start;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    int idx = 0;
    int N = plans.size();
    for(int i = 0 ; i < N; i++){
        arr[i].name = plans[i][0];
        arr[i].takes = stoi(plans[i][2]) * 1;
        arr[i].start = (plans[i][1][0]- '0') * 600
                        + (plans[i][1][1] - '0') * 60
                        + (plans[i][1][3] - '0') * 10
                        + (plans[i][1][4] - '0');
    }
    sort(arr,arr+N,cmp);
    node cur;
    node next = arr[idx++];
    while(idx < N){
        cur = next;
        next = arr[idx++];
        int diff = next.start - cur.start;
        if(diff >= cur.takes){
            diff -= cur.takes;
            answer.push_back(cur.name);
            while(diff > 0 && !s.empty()){
                node snode = s.top(); s.pop();
                if(diff >= snode.takes){
                    diff -= snode.takes;
                    answer.push_back(snode.name);
                }
                else{
                    snode.takes -= diff;
                    diff = 0;
                    s.push(snode);
                }
            }
        }
        else{
            cur.takes -= diff;
            s.push(cur);
        }
    }
    answer.push_back(arr[N-1].name);
    while(!s.empty()){
        cur = s.top(); s.pop();
        answer.push_back(cur.name);
    }
    return answer;
}