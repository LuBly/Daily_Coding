#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0,idx=0, total=0, waiting = truck_weights.size();
    queue<int> br_q;//다리에 들어온 트럭의 무게를 저장하는 queue
    while(1){
        if(idx==waiting){//다리에 진입하는 마지막 차량일 때 다리 길이만큼 +해주고 반복 종료
            answer+=bridge_length;
            break;
        }
        answer++;//반복을 수행할 때마다 초 증가
        int cur = truck_weights[idx];
        
        if(br_q.size()==bridge_length){//다리가 꽉 찼을 때
            total-=br_q.front();
            br_q.pop();
        }
        
        if(total+cur<=weight){//다리에 진입할 수 있을 때
            total+=cur;
            br_q.push(cur);
            idx++;
        }
        else{//다리에 진입할 수 없을 때 0을 push하면서 대기
            br_q.push(0);
        }
        
    }
    return answer;
}