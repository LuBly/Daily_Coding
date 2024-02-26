//[Baekjoon C++] 합분해 [DP]
#include <iostream>
#include <vector>
using namespace std;

/*
20 = dp[19] + 1 = {21}
19 = dp[18] + 1 = {20}
18 = dp[17] + 1 = {19}

dp[N] = dp[N-1] + 1

6
6 0 0 0
5 1 0 0
4 2 0 0
3 3 0 0
2 4 0 0
1 5 0 0
0 6 0 0

5
0 0 0 5
0 0 1 4
0 0 2 3
0 0 3 2
0 0 4 1
0 0 5 0

~~

5


*/

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int d[201][201];
    
    for (int i=0;i<=k;i++)
        d[1][i] = i;
    
    for (int i=2;i<=n;i++)
        for (int j=1;j<=k;j++)
            d[i][j] = (d[i-1][j] + d[i][j-1]) % 1000000000;
        
    cout << d[n][k] << endl;

    return 0;

}