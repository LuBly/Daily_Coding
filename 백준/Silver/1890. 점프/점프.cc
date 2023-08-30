//[BaekJoon C++] 점프 [DP]
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    // N : 게임 판의 크기
    int N;
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N)); // board[N][N] 
    vector<vector<ll>> dp(N,vector<ll>(N, 0)); // dp[N][N]
    dp[0][0] = 1;
    
    // board 입력
    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            cin >> board[y][x];
        }
    }

    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            // 이어진 경로가 없거나, 끝 점이면 continue
            if(dp[y][x]==0 || (y == N-1 && x == N-1)) continue;
            // 다음 좌표들
            int Right = x + board[y][x];
            int Down = y + board[y][x];
            if(Right < N) dp[y][Right] += dp[y][x];
            if(Down < N) dp[Down][x] += dp[y][x];
        }
    }

    cout<<dp[N-1][N-1];
}   
