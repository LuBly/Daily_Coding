//[Baekjoon C++] 계단 오르기 [DP]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
//마지막 stair을 반드시 밟는다고 가정
dp[1] = arr[1]
dp[2] = arr[1] + arr[2]
dp[3] = arr[1] + arr[3] vs arr[2] + arr[3]

dp[4] = dp[1] + arr[3] + arr[4] , dp[2] + arr[4]
dp[N] = dp[N-3] + arr[N-1] + arr[N] vs dp[N-2] + arr[N]
*/


int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);    
    int stairCnt;
    cin >> stairCnt;

    vector<int> arr(stairCnt + 1); 
    vector<int> dp(stairCnt + 1); 
    for(int k = 1; k <= stairCnt; k++){
        cin >> arr[k];
    }

    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);

    for(int k = 4; k <= stairCnt; k++){
        dp[k] = max(dp[k-3] + arr[k-1] + arr[k], dp[k-2] + arr[k]);
    }

    cout << dp[stairCnt];

}