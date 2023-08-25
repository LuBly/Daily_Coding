//[Baekjoon C++] 카드 구매하기 [DP]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    // target    : 구매하려고 하는 카드의 개수
    // dp[num]   : num개의 카드를 구매하려할 때의 최대값을 저장할 dp vector
    // data[idx] : idx개의 카드가 들어있는 카드팩의 가격 data vector 
    
    int target;
    cin >> target;
    vector<int> dp(target+1);
    vector<int> data;
    data.push_back(0);

    
    for(int k = 0; k < target; k++){
        int num;
        cin >> num;
        data.push_back(num);
    }

    //dp[1] = arr[1]
    //dp[2] = max(dp[1]+arr[1] ,arr[2]);
    //dp[3] = max(dp[2]+arr[1], arr[3]);
    //dp[4] = max(dp[3]+arr[1], dp[2]+arr[2], arr[4])
    //dp[5] = max(dp[4]+arr[1], dp[3]+arr[2], arr[5])
    //dp[6] = max(dp[5]+arr[1], dp[4]+arr[2], dp[3]+arr[3], arr[6])
    //dp[7] = max(dp[6]+arr[1], dp[5]+arr[2], dp[4]+arr[3], arr[7])

    // O(n^2) = 1,000,000
    for(int k = 1; k <= target; k++){
        dp[k] = data[k];
        for(int j = 1; j <= k/2; j++){
            dp[k] = max(dp[k], dp[k-j] + data[j]);
        }
    }
    cout << dp[target];
}