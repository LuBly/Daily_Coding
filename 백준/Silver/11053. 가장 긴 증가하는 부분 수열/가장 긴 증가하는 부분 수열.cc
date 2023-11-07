//[Baekjoon C++] 가장 긴 증가하는 부분 수열 [DP]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int size;
    cin >> size;

    vector<int> dp(size + 1, 1);
    vector<int> arr(size + 1);
    for(int k = 1; k <= size; k++){
        cin >> arr[k];
    }
    
    int sum = 0;
    for(int k = 1; k <= size; k++){
        for(int j = 1; j < k; j++){
            if(arr[j] < arr[k]){
                dp[k] = max(dp[k], dp[j] + 1);
            }
        }
        sum = max(sum, dp[k]);    
    }

    cout << sum;
}