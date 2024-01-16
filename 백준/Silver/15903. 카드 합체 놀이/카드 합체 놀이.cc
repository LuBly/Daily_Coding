//[Baekjoon C++] 카드 합체 놀이 [그리디] 11 07
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
// 점수가 가장 작게 만드는 것이 목적
// 정렬 => 0 1 값 합쳐서 저장
// 정렬 => 0 1 값 합쳐서 저장
// 위 행동을 fusionCnt 횟수만큼 반복
int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);        
    int cardCnt, fusionCnt;
    cin >> cardCnt >> fusionCnt;
    
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(int k = 0; k < cardCnt; k++){
        ll num;
        cin >> num;
        pq.push(num);
    }

    while(fusionCnt > 0){
        ll card_0 = pq.top(); pq.pop();
        ll card_1 = pq.top(); pq.pop();

        pq.push(card_0 + card_1);
        pq.push(card_0 + card_1);
        
        fusionCnt--;
    }

    ll answer = 0;
    while(!pq.empty()){
        answer += pq.top();
        pq.pop();
    }

    cout << answer;

}