//[BaekJoon C++] 제곱수의 합 [DP]
#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;
/*
dp[1] = 1
dp[2] = 1^2 + 1^2 = 2
dp[3] = 1^2 + 1^2 + 1^2 = 3
dp[4] = 2^2 = 1
dp[5] = dp[4] + dp[1] = 2^2 + 1^2 = 2
dp[6] = dp[4] + dp[2] = 2^2 + 1^2 + 1^2 = 3
dp[7] = dp[4] + dp[3] = 4 2^2 + 1^2 + 1^2 1^2 = 4
dp[8] = dp[4] + dp[4] = 2
dp[9] = 3^2 = 1
dp[10] = dp[9] + dp[1]
dp[11] = dp[9] + dp[2]
dp[12] = dp[9] + dp[3]
dp[13] = dp[9] + dp[4] = 2
dp[14] = dp[9] + dp[5]
dp[15] = dp[9] + dp[6]
dp[16] = 1
dp[17] = dp[16] + dp[1] = 2, dp[9] + dp[8] = 3, dp[4] + dp[13] = 3, dp[1] + dp[16] =2
dp[18] = dp[16] + dp[2], dp[9] + dp[9] 
*/  

bool isSquare(int num){
    for(int k = 1; k*k <= num; k++){
        if(k * k == num) return true;
    }
    return false;
}

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N; 
    cin >> N;

    vector<int> dp(N+1, INF);
    vector<int> curSq;
    for(int k = 1; k <= N; k++){
        if(isSquare(k)){//제곱수 인지 판별
            curSq.push_back(k);
            dp[k] = 1;
        }
        else{
            for(int cur : curSq){
                dp[k] = min(dp[k], dp[cur] + dp[k-cur]);
            }
        }

        //cout << dp[k] << endl;
        
    }

    cout << dp[N];
}    