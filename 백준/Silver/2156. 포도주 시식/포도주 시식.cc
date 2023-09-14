//[Baekjoon C++] 포도주 시식 [DP]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// dp[0] = 0
// dp[1] = arr[1]
// dp[2] = arr[1] + arr[2]
// dp[3] = arr[1] + arr[2] vs arr[1] + arr[3] vs arr[2] + arr[3]
// dp[n] = dp[n-1] vs dp[n-2] + arr[n] vs dp[n-3] + arr[n] + arr[n-1]


int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    // cupCnt : 포도주 잔의 개수
    int cupCnt;
    cin >> cupCnt;

    vector<int> cupData(cupCnt+1, 0);
    vector<int> dp(cupCnt+1 , 0);
    for(int k = 1; k <= cupCnt; k++){
        cin >> cupData[k];
    }

    // dp 비교
    // x o o = dp[k-3] + arr[k] + arr[k-1]
    // o x o = dp[k-2] + arr[k]
    // o o x = dp[k-1]
    dp[1] = cupData[1];
    dp[2] = cupData[1] + cupData[2];
    for(int k = 3; k <= cupCnt; k++){
        dp[k] = max({dp[k-1], dp[k-2] + cupData[k], dp[k-3] + cupData[k] + cupData[k-1]});
    }

    cout << dp[cupCnt];
}