//[Baekjoon C++] 스티커 [dp]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    // testCnt : 테스트 케이스의 개수
    int testCnt;
    cin >> testCnt;

    for(int k = 0; k < testCnt; k++){
        // width : 행의 너비
        int width;
        cin >> width;
        vector<vector<int>> arr(2, vector<int>(width));
        vector<vector<int>> dp(2, vector<int>(width));
        for(int y = 0; y < 2; y++){
            for(int x = 0; x < width; x++){
                cin >> arr[y][x];
            }
        }
        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        dp[0][1] = dp[1][0] + arr[0][1];
        dp[1][1] = dp[0][0] + arr[1][1];
        for(int x = 2; x < width; x++){
            // 대각 이동 vs 점프 대각 이동
            dp[0][x] = max(dp[1][x-1], dp[1][x-2]) + arr[0][x];
            dp[1][x] = max(dp[0][x-1], dp[0][x-2]) + arr[1][x];
        }

        cout<< max(dp[0][width-1], dp[1][width-1])<<'\n';
    }
}