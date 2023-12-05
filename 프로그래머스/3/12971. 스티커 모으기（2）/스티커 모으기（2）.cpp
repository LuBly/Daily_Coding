#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//dfs를 활용하여 문제 풀이?
//
int solution(vector<int> sticker)
{
    int answer = 0;
    int tmpMax = 0;
    int n = sticker.size();
    vector<int> dp(n);
    if(n == 1) return sticker[0];
    
    // 첫번째 스티커를 뜯은 경우
    dp[0] = sticker[0];
    dp[1] = dp[0];
    
    for(int k = 2; k < n-1; k++){
        dp[k] = max(dp[k-1], dp[k-2] + sticker[k]);
    }
    
    dp[n-1] = dp[n-2];
    tmpMax = *max_element(dp.begin(), dp.end());
    
    // 첫번째 스티커를 뜯지 않은 경우
    dp[0] = 0;
    dp[1] = sticker[1];
    for(int k = 2; k < n; k++){
        dp[k] = max(dp[k-1], dp[k-2] + sticker[k]);
    }
    
    answer = max(tmpMax, *max_element(dp.begin(), dp.end()));
    return answer;
}