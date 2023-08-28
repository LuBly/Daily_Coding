//[Baekjoon C++] 점프 점프 [DP]
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int jumpCnt;
    cin >> jumpCnt;
    vector<int> jumpData(jumpCnt+1);
    vector<int> dp(jumpCnt+1, INF);
    for(int k = 1; k <= jumpCnt; k++){
        cin >> jumpData[k];
    }

    dp[1] = 0;
    for(int k = 1; k < jumpCnt; k++){
        for(int j = 1; j <= jumpData[k]; j++){
            if((j+k) <= jumpCnt){
                dp[j+k] = min(dp[j+k], dp[k]+1);
            }
        }
    }
    if(dp[jumpCnt] == INF) cout << -1;
    else cout << dp[jumpCnt];

}