//[Baekjoon C++] 포도주 시식 [DP]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int wineCnt;
    cin >> wineCnt;

    vector<int> wines(wineCnt + 1);
    vector<int> dp(wineCnt + 1);

    // 포도주 잔에 들어있는 포도주 양 입력
    for(int i = 1; i <= wineCnt; i++){
        cin >> wines[i];
    }

    // 1. 포도주 잔을 선택하면 그 잔에 들어있는 포도주는 모두 마셔야 하고, 
    //    마신 후에는 원래 위치에 다시 놓아야 한다.
    // 2. 연속으로 놓여 있는 3잔을 모두 마실 수는 없다.
    // dp[1] = wines[1]
    // dp[2] = wines[1] + wines[2]
    // dp[3] = wines[1] + wines[2] vs wines[1] + wines[3] vs wines[2] + wines[3]
    
    // dp[N] = {dp[N-1]} vs {wines[N] + dp[N-2]} vs {dp[N-3] + wines[N-1] + wines[N]} 
    dp[0] = 0;
    dp[1] = wines[1];
    dp[2] = wines[1] + wines[2];
    // 1. 마지막 잔을 마시지 않고, 1번째 앞에 잔의 최대값
    // 2. 마지막 잔을 기준으로 2번째 앞의 잔을 마시고 + 마지막 잔
    // 3. 마지막 잔을 기준으로 3번째 앞의 잔을 마시고, 1번째 앞의 잔 + 마지막 잔
    for(int k = 3; k <= wineCnt; k++){
        dp[k] = max({dp[k-1], dp[k-2] + wines[k], dp[k-3] + wines[k-1] + wines[k]});
    }

    cout << dp[wineCnt];
}