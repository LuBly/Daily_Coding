#include <string>
#include <vector>
#define div 1000000007
using namespace std;
//점화식 dp[n]=dp[n-2](가로++)+dp[n-1](세로++);
int solution(int n) {
    //dp[n]%div = (dp[n-2]%div+dp[n-1]%div)%div
    int dp[60000];
    int answer = 0;
    dp[0]=1; dp[1]=2;
    for(int k=2;k<n;k++){
        dp[k]=(dp[k-1]%div+dp[k-2]%div)%div;
    }
    answer = dp[n-1];
    return answer;
}