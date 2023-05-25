#include <string>
#include <vector>
#include <queue>
#define MAX 600000
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long answer = 0;
    //queue1에 입력하면서 숫자 합 3 2 7 2 = 14
    //queue2에 입력하면서 숫자 합 4 6 5 1 = 16
    //큰 쪽에서 작은쪽에 숫자 insert 
    // 1. 3 2 7 2 4 = 18
    // 1. 6 5 1 = 12 (pop)
    
    // 2. 2 7 2 4 = 15 (pop)
    // 2. 6 5 1 3 = 15
    
    // 1 1 / 1 5 
    // 1 1 1 / 5
    // 1 1 1 5 /
    // 어느 한쪽이 empty가 되면 answer = -1
    
    long long sum1=0;
    queue<int> q1;
    for(int k=0;k<queue1.size();k++){
        q1.push(queue1[k]);
        sum1+=queue1[k];
    }
    
    long long sum2=0;
    queue<int> q2;
    for(int k=0;k<queue2.size();k++){
        q2.push(queue2[k]);
        sum2+=queue2[k];
    }
    
    while(true){
        if(q1.empty()||q2.empty()||answer>MAX){
            answer=-1;
            break;
        }    
        if(sum1>sum2){//queue1의 합이 queue2의 합보다 클 때
            //queue1의 원소를 queue2에 push
            int left = q1.front();
            sum2+=left;
            sum1-=left;
            q1.pop();
            q2.push(left);
            answer++;
        }
        else if(sum1<sum2){//queue1의 합이 queue2의 합보다 작을 때
            //queue2의 원소를 queue1에 push
            int right = q2.front();
            sum1+=right;
            sum2-=right;
            q2.pop();
            q1.push(right);
            answer++;
        }
        else//두개의 합이 같을 때
            break;
        
    }
    
    return answer;
}