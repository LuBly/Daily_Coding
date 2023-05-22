#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
//n횟수 만큼 works에서 가장 큰 값을 -1 해주자.
//works에서 가장 큰 값을 찾는 것 
//1. max_element- O(n)=>1,000,000*20,000 X, 2. priority queue O(2logN) O, 3.map , 4.sort(너무 오래걸릴 것 같음 X)
long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<long long> pq;
    for(int k=0;k<works.size();k++)
        pq.push(works[k]);

    while(n>0){             //works에서 가장 큰 값을 -1 해주는 반복문
        long long max = pq.top();
        pq.pop();
        if(max>0) max-=1;   //최대값에서 -1
        pq.push(max);
        n--;                //순환할때마다 n-1
    }
    
    while(!pq.empty()){     //결과값 계산
        long long num = pq.top();
        pq.pop();
        answer+=pow(num,2);
    }
    
    return answer;
}