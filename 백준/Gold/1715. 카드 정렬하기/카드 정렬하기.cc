//[BaekJoon C++] 카드 정렬하기 [그리디]
#include <iostream>
#include <queue>
using namespace std;

//여러 카드 뭉치를 합치는 과정

/*
오름차순 정렬
2개씩 합치기? 

ex) 30 10 20 40 50
-> 40 30 60 90

-> 10 20 30 40 50
// 누적 합?

10 30 60 100 150
40 100 200 350
상태 (10 20) 30 40 50
횟수 30

상태 (30 30) 40 50
횟수 30 + 60

상태 (40 50) 60
횟수 30 + 60 + 90

상태 (90 60)
횟수 30 + 60 + 90 + 150

= 330

상태 (10 20) 30 40 50
횟수 30

상태 30 (30 40) 50
횟수 30 + 70

상태 (30 50) 70
횟수 30 + 70 + 80

상태 (80 70)
횟수 30 + 70 + 80 + 150 
= 330
///////////////////////////////////
10 20 30 40 50 60
상태 (10 20) 30 40 50 60
횟수 30

상태 (30 30) 40 50 60
횟수 30 + 60

상태 (40 50) 60 60
횟수 30 + 60 + 90

상태 (60 60) 90
횟수 30 + 60 + 90 + 120

상태 90 120
횟수 30 + 60 + 90 + 120 + 210 = 510

= 510

상태 (10 20) 30 40 50 60
횟수 30

상태 30 (30 40) 50 60
횟수 30 + 70

상태 (30 50) 60 70
횟수 30 + 70 + 80

상태 (60 70) 80
횟수 30 + 70 + 80 + 130

상태 (130 80)
횟수 30 + 70 + 80 + 130 + 210 = 520
////////////////////////////////////

해결 방안
1. priority queue 활용(오름차순)
2. 앞에서부터 두개 pop해서 더하고 push
3. queue.size()가 1이되는 순간 종료.
*/


int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;
    
    priority_queue<int, vector<int>, greater<int>> pq; 
    for(int k = 0; k < N; k++){
        int num;
        cin >> num;
        pq.push(num);
    }
    
    int res = 0;
    while(true){
        if(pq.size() == 1) break;
        // 앞에서부터 두개 pop
        int num1 = pq.top(); pq.pop();
        int num2 = pq.top(); pq.pop();
        int sum = num1 + num2;
        res += sum;
        pq.push(sum);
    }

    cout << res;
}    