//[Baekjoon C++] 동물원 [dp]
#include <iostream>
#include <vector>
#define MOD 9901
using namespace std;

// dp[N][3] , o x, x o, x x
// 
int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;
    vector<vector<int>> dp(N+1,vector<int>(3,0)); // dp[N+1][3] 생성
    //dp 초기 값 지정
    for(int k = 0; k < 3; k++)
        dp[1][k] = 1;
    
    for(int k = 2; k <= N; k++){
        // o x 는 x o, x x 이후에 올 수 있다.
        dp[k][0] = (dp[k-1][1] + dp[k-1][2]) % MOD;
        // x o 는 o x, x x 이후에 올 수 있다.
        dp[k][1] = (dp[k-1][0] + dp[k-1][2]) % MOD;
        // x x 는 어떤 상태 이후든 올 수 있다.
        dp[k][2] = (dp[k-1][0] + dp[k-1][1] + dp[k-1][2]) % MOD;
    }

    cout << (dp[N][0] + dp[N][1] + dp[N][2]) % MOD;
}