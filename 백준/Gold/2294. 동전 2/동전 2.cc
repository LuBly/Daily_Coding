//[Baekjoon C++] 동전 2 [DP]
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 10001
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    // coinCnt   : 동전의 종류 개수
    // target    : 목표로하는 가치
    // cointType : 동전의 종류들을 저장할 vector
    // dp        : dp[target] => target까지 사용할 동전의 최소 개수들을 저장할 vector
    int coinCnt, target;
    cin >> coinCnt >> target;
    vector<int> coinType(coinCnt + 1);
    vector<int> dp(target + 1, INF);
    dp[0] = 0;
    // 동전을 단계별로 사용하며 최소값을 수정해나간다.
    // 1번 동전으로 최소값들을 먼저 싹 구하고
    // 2번 동전으로 그다음 최소값들 계산
    // ~~
    // 모든 동전을 썼을 때 최소값들 저장
    // 마지막 target에서의 최소값을 출력
    
    for(int cnt = 1; cnt <= coinCnt; cnt ++){
        cin >> coinType[cnt];
        for(int idx = coinType[cnt]; idx <= target; idx++){
            // dp[idx] 는 원래 만들 수 있는 동전의 개수 vs 새로운 동전을 포함하여 만들 수 있는 동전의 개수
            dp[idx] = min(dp[idx], dp[idx - coinType[cnt]] + 1);
        }
    }
    
    if(dp[target]==INF) cout << -1;
    else cout << dp[target];
}