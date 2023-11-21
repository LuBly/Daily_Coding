//[Baekjoon C++] 계단 오르기 [DP]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int cnt;
    cin >> cnt;
    vector<int> arr(cnt+1);
    vector<int> dp(cnt+1);

    for(int k = 1; k <= cnt; k++){
        cin >> arr[k];
    }
    /*
    dp[1] = arr[1]
    dp[2] = arr[1] + arr[2]
    dp[3] = arr[2] + arr[3]
    dp[4] = dp[2] + arr[4] or dp[1] + arr[3] + arr[4]
    dp[5] = dp[3] + arr[5] or dp[2] + arr[4] + arr[5]
    dp[k] = max(dp[k-2] + arr[k], dp[k-3] + arr[k-1] + arr[k])
    */
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
    
    for(int k = 4; k <=cnt; k++){
        dp[k] = max(dp[k-2] + arr[k], dp[k-3] + arr[k-1] + arr[k]);
    }
    cout << dp[cnt];
}
