//[Baekjoon C++] 거스름돈 [그리디]
#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;
/*
dp[1] = -1
dp[2] = 1
dp[3] = -1
dp[4] = 2
dp[5] = 1
dp[6] = 3

k
if(k / 5)

if K 27
5로 먼저 나누고 5 10 15 20 25 ,
2로 나눈다 -> 22 17 12 7 2
결과 -> 12, -1, 9, -1, 6 
최소값 -> 6

*/
int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);    
    int N;
    cin >> N;

    int res = INF;
    for(int k = 0; k <= (N / 5); k++){
        int curFive = 5 * k;
        int curTwo = N - curFive;

        if(curTwo % 2 == 0){
            res = min(res, (k + curTwo / 2));
        }
    }
    
    if(res == INF) cout << -1;
    else cout << res;
}