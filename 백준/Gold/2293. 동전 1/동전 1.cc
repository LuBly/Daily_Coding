//[Baekjoon C++] 동전 1 [DP]
#include <iostream>
#include <vector>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int typeCnt, target;
    cin >> typeCnt >> target;
    vector<int> coins(typeCnt);
    vector<int> dp(target+1);
    for(int k = 0; k < typeCnt; k++){
        cin >> coins[k];
    }
    dp[0] = 1; // 아무것도 고르지 않은 것도 하나의 경우의 수로 판단
    //dp[1원] = 경우의 수 -> orig{1} = 1
    //dp[2원] = {1,1},{2} = 2
    //dp[3원] = {1,1,1},{2,1} = 2
    //dp[4] = {1,1,1,1},{2,1,1},{2,2} = 3
    //dp[5] = {1,1,1,1,1},{2,1,1,1},{2,2,1},{5} = 4
    //dp[6] = {1,1,1,1,1,1},{2,1,1,1,1},{2,2,1,1},{5,1},{2,2,2} = 5
    //dp[7] = 
    for(int k = 0; k < typeCnt; k++){
        for(int j = coins[k]; j <= target; j++){
            dp[j] += dp[j-coins[k]];
        }
    }

    cout<<dp[target];
}