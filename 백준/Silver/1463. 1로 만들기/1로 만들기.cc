//[Baekjoon C++] 알파벳 [dfs]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int num;
    cin>>num;
    vector<int> dp(num+1);

    dp[1]=0;
    //1번. X가 3로 나누어 떨어질 경우 3로 나눈다
    //2번. X가 2로 나누어 떨어질 경우 2로 나눈다
    //3번. 1을 뺀다
    for(int k=2;k<=num;k++){//Bottom-up연산 밑에서 부터 차곡차곡 쌓아간다.
        dp[k]=dp[k-1]+1;//k가 증가함에 따른 3번연산
        if(k%3==0) dp[k]=min(dp[k],dp[k/3]+1);// k가 3의 배수일 경우 위 연산에서 1번 계산 or k/3연산+1 중에 작은 것
        if(k%2==0) dp[k]=min(dp[k],dp[k/2]+1);// k가 2의 배수일 경우 위 연산에서 1번 계산 or k/2연산+1 중에 작은 것
    }

    cout<<dp[num];
}