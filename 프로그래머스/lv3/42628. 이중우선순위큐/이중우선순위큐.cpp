#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2,0);
    priority_queue<int,vector<int>> pq_less;//내림차순, 최대값
    priority_queue<int,vector<int>,greater<int>> pq_greater;//오름차순, 최소값
    int cnt = 0;//queue 내부의 갯수를 파악할 변수
    for(int k=0;k<operations.size();k++){
        if(!cnt){
            while(!pq_less.empty()) pq_less.pop();
            while(!pq_greater.empty()) pq_greater.pop();
        }
        
        if(operations[k][0]=='I'){//insert일 경우
            string tmp="";
            int idx=2;
            while(idx<operations[k].size()){
                tmp+=operations[k][idx++];
            }
            pq_less.push(stoi(tmp));
            pq_greater.push(stoi(tmp));
            cnt++;
        }
        else{// 삭제
            if(!cnt) continue;
            
            if(operations[k][2]=='1'){//최대값 삭제의 경우
                pq_less.pop();
                cnt--;
            }
            else{//최소값 삭제의 경우
                pq_greater.pop();
                cnt--;
            }
        }
    }
    if(cnt){
        answer[0]=pq_less.top();
        answer[1]=pq_greater.top();
    }
    
    return answer;
}