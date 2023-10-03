//[BaekJoon C++] 연속합 [DP]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    // N : 숫자의 개수
    int N;
    cin >> N;
    vector<int> dp(N);
    cin >> dp[0];

    int answer = dp[0];
    for(int k = 1; k < N; k++){
        int num;
        cin >> num;
        dp[k] = max(num, dp[k-1]+num);
        answer = max(answer, dp[k]);
    }

    cout << answer;

    // 10 6 9 10 15 21 -14 12 33 32
    // 2 3 -1 3 7 3 9 14 9 10 
    // -1 -3 -6 -10 -15
}   
