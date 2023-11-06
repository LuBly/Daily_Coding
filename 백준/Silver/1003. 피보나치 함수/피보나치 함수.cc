//[Baekjoon C++] 피보나치 함수 [DP]
#include <iostream>
#include <vector>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;

    // 3
    /*
    0 -> 1 0
    1 -> 0 1
    3 -> f(2) + f(1)
    ->f(1)+f(0) + f(1)
    dp[0] = 1
    dp[1] = 1

    dp[2] = 2 = dp[1] + dp[0]
    dp[3] = 3 = dp[2] + dp[1]
    => dp[1] + dp[0] + dp[1] = 2dp[1] + dp[0]
    dp[4] = 5 = dp[3] + dp[2]
    => 2dp[1] + dp[0] + dp[1] + dp[0] = 3dp[1] + 2dp[0]
    dp[5] = 8
    */
    // 0cnt, 1cnt
    vector<pair<int,int>> dp(41);
    dp[0] = {1,0};
    dp[1] = {0,1};
    for(int k = 0; k < N; k++){
        int num;
        cin >> num;
        for(int j = 2; j <= num; j++){
            dp[j].first = dp[j-1].first + dp[j-2].first;
            dp[j].second = dp[j-1].second + dp[j-2].second;
        }

        cout << dp[num].first << " " << dp[num].second << '\n';
    }
}