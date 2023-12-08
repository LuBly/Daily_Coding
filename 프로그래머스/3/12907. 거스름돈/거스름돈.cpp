#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> money){
    int answer = 0;
    
    vector<int> dp(n + 1);

    dp[0] = 1;
    for(int i = 1; i <= n; i++)
        dp[i] = ((i % money[0] == 0) ? 1 : 0);
    
    for(int i = 1; i < money.size(); i++)
        for (int j = 0; j <= n; j++){
            if (j >= money[i])
                dp[j] = (dp[j] + dp[j - money[i]]) % 1000000007;
        }
          /*else if (j < money[i])
                dp[j] = dp[j] % 1000000007;*/

    answer = dp[n];
    return answer;
}