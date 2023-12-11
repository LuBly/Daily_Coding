//[Baekjoon C++] 2×n 타일링2 [DP]
#include <iostream>
#include <vector>
#define DIV 10007
using namespace std;

/*
dp[n] = dp[n-2] * 2 + dp[n-1]
*/

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;

    vector<int> dp(N+1);
    dp[1] = 1;
    dp[2] = 3;

    // % 분배법칙
    // 7 % 3 = ((2 * 2) % 3 + (3 % 3)) % 3 = 1

    for(int k = 3; k <= N; k++){
        dp[k] = ((dp[k-2] * 2) % DIV + (dp[k-1]) % DIV) % DIV;
    }

    cout << dp[N];
}