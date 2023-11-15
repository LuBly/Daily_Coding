//[Baekjoon C++] 2×n 타일링 [DP]
#include <iostream>
#include <vector>
#define DIV 10007
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;

    vector<int> dp(N+1);
    dp[1] = 1;
    dp[2] = 2;
    /*
    55 % 3 = (22 % 3 + 33 % 3 ) % 3
    1 = 1 + 0 = 1
    */
    for(int k = 3; k <= N; k++){
        dp[k] = (dp[k-2]%DIV + dp[k-1]%DIV) % DIV;
    }

    cout << dp[N];
}