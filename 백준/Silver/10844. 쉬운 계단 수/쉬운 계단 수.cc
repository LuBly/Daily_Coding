//[Baekjoon C++] 쉬운 계단 수 [DP]
#include <iostream>
#include <vector>
#define div 1000000000
using namespace std;

// 1 -> 1 2 3 4 5 6 7 8 9 = 9개
// 2 -> 12 10/21 23/32 34/43 45/54 56/ ~~ 98 910(X) = 17
// dp[자리수][끝나는 수]
//끝나는 수
//0 1 2 3 4 5 6 7 8 9
//0 1 1 1 1 1 1 1 1 1
//1 1 2 2 2 2 2 2 2 1
//1 3 3 4 4 4 4 4 3 2

//dp[n][j]= dp[n-1][j-1]+dp[n-1][j+1]
//if(j=0) => dp[n-1][j+1]
//if(j=9) => dp[n-1][j-1];

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int input;
    cin>>input;
    int dp[101][10]={0,};//[자리수(1~100)][끝나는 수(0~9)]
    for(int k=1;k<10;k++){
        dp[1][k]=1;//초기값 설정
    }

    for(int k=2;k<=input;k++){
        for(int j=0;j<10;j++){
            if(j==0)
                dp[k][j]=dp[k-1][j+1];
            else if(j==9)
                dp[k][j]=dp[k-1][j-1];
            else
                dp[k][j]=dp[k-1][j-1]+dp[k-1][j+1];

            dp[k][j]%=div;
        }
    }

    int answer = 0;
    for(int j=0;j<10;j++){
        answer = (answer+dp[input][j])%div;
    }
    cout<<answer;
}