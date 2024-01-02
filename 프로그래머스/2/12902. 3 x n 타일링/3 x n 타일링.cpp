#include <string>
#include <vector>
#define MOD 1000000007
using namespace std;
/*
짝수단위로 update?
F[N] = F[N-2] * F[2] + F[N-4] * 2(F[4]의 특수 모양) + F[N-6] * 2(F[6]의 특수 모양) ~~ + F[2] * 2 + 2
*/

int solution(int n) {
    if(n%2 != 0) return 0;
    
    vector<long long> dp(5001, 0);
    dp[0] = 1;
    dp[2] = 3;
    
    for(int k = 4; k <= n; k += 2){
        dp[k] = dp[k-2] * dp[2];
        
        for(int j = k-4; j >= 0; j -= 2){
            dp[k] += dp[j] * 2;
        }
        
        dp[k] %= MOD;
    }
    
    return dp[n];
}