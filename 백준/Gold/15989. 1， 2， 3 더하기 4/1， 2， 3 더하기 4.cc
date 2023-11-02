//[Baekjoon C++] 1, 2, 3 더하기 4 [DP]
#include <iostream>
#include <vector>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);        
    int testCnt;
    cin >> testCnt;
    
    int dp[10001][3];
    // dp[i][0] : 1로 시작하는 경우
    // dp[i][1] : 2로 시작하는 경우
    // dp[i][2] : 3으로 시작하는  경우
    dp[1][0] = 1;
    dp[2][0] = 1;
    dp[2][1] = 1;
    dp[3][0] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;

    for(int k = 4; k < 10001; k++){
        dp[k][0] = 1;
        dp[k][1] = dp[k-2][0] + dp[k-2][1];
        dp[k][2] = dp[k-3][0] + dp[k-3][1] + dp[k-3][2];
    }

    for(int k = 0; k < testCnt; k++){
        int target;
        cin >> target;
        cout << dp[target][0] + dp[target][1] + dp[target][2] << '\n';
    }
}