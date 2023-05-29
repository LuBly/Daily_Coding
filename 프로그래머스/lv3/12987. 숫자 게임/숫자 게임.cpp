#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#define MAX 100000
using namespace std;
// dfs, backtracking을 활용하여 문제 풀이?
// 배열을 돌면서 A의 값보다 큰 값들을 전부 체크?
// dfs로 풀기엔 시간복잡도가 어마무시하다
int solution(vector<int> A, vector<int> B) {
    int answer=0;
    sort(A.begin(),A.end());
    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto b : B)
        pq.push(b);
    //A를 오름차순으로 정렬 1 3 5 7, heap에서 하나씩 꺼내와서 비교
    //idx별로 체크, 1<->2, answer ++
    //3<->2 X -> 3<->6 answer ++
    //5<->8 answer ++
    //heap empty라 패스
    int idx = 0;
    while(idx<A.size()){
        int a = A[idx];
        int b = pq.top();
        if(pq.empty()) break;
        
        if(a<b){
            answer++;
            idx++;
        }
        pq.pop();
    }
    return answer;
}