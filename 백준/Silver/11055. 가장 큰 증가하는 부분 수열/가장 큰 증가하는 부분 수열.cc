//[Baekjoon C++] 가장 큰 증가하는 부분 수열 [?]
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// 입력된 수열 중에서 합이 가장 큰 것
// dp
// dp[0] = arr[0]
// dp[1] = arr[0] + arr[1]
// dp[2] = arr[0] + arr[2] / arr[1] + arr[2] 불가.
// dp[3] = dp[2] + arr[3]
// dp[4] = dp[3] + arr[4]

// if(이전에 왔던 값중 가장 큰 값 < 현재 값) 
// dp[가장 큰 값이 있던 idx] + arr[k]

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int numCnt;
    cin >> numCnt;

    vector<int> data(numCnt);
    for(int k = 0; k < numCnt; k++){
        cin >> data[k];
    }    
    vector<int> dp(data);
    
    for(int k = 0; k < numCnt; k++){
        int curNum = data[k];
        for(int j = 0; j < k; j++){
            int cmpNum = data[j];
            if(curNum > cmpNum){
                dp[k] = max(dp[k], dp[j] + data[k]);
            }      
        }
    }

    cout << *max_element(dp.begin(), dp.end());
}