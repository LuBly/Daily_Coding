#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
// 완전탐색 x , k가 500,000이라 펙토리얼로 가지고 가면 너무 오래걸림
// 쭉 먹으면서 가고 먹은 것들 중 가장 큰 친구한테 무적권 사용
// ex) [4 n=3 2 n=1] (4->n=5)<<못먹네? 무적권 있어? 1장 차감해서 4가 있는 idx 1에서 무적권 사용
// n은 5가되고 계속 진행
// 4(o) [2/ n=5 4 n=1] (5)<<못먹네? 무적권 있어? 1장 차감해서 2,4 중 가장 큰 값 4가 있는 idx 3에서 무적권 사용
// n은 5가되고 계속 진행
// 4(o) 2 4(o->n=5) [5] n=0 (3)<<못먹네? 무적권 있어? 1장 차감해서 5 중 가장 큰 값 5가 있는 idx 4에서 무적권 사용
// n은 5가되고 계속 진행
// 4(o) 2 4(o) 5(o) 3 //(3)<<못먹네? 무적권 있어? 없어? 그럼 끝 여기까지클리어
int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    int sum=0;
    priority_queue<int> q;
    
    if(k==enemy.size())
        return k;
    
    for(int i=0;i<enemy.size();i++){
        int input = enemy[i];
        if(n>=input){// 무적권을 사용하지 않고 클리어 가능할 때
            q.push(input);
            n-=input;
        }
        else{
            if(k>0){//무적권이 남아있다면
                k--;
                if(!q.empty()){
                    int cur = q.top();
                    q.pop();
                    if(cur>=input){//계산하는 모든 값들 중 가장 큰 값에 무적권을 사용해야하므로
                        // queue에 남아있던 최대값이 현재 들어온 인풋값보다 큰 경우
                        // queue에 있는 값에 새로 들어온 값을 입력해주고, n값 연산
                        // n값 연산 => cur에 무적권을 사용하고, input값을 q에 넣었으므로 n+cur-input
                        q.push(input);
                        n=n+cur-input;
                    }
                    else{
                        // 새로 들어온 값이 최대값인 경우 queue, n 변형없이 그대로 진행
                        q.push(cur);
                    }
                }
            }
            else 
                return i;
        }
        
    }
}