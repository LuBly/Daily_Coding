//[Baekjoon C++] 1로 만들기 2 [그래프 구현]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    //1. X가 3으로 나누어 떨어지면, 3으로 나눈다.
    //2. X가 2로 나누어 떨어지면, 2로 나눈다.
    //3. 1을 뺀다.
    //dp[3n]=min(dp[n],dp[3n-1])+1
    //dp[2n]=min(dp[n],dp[2n-1])+1
    //dp[6n]=min(dp[2n],dp[3n],dp[6n-1])+1
    //dp[n]=min(dp[n-1])+1

    //dp[10]=dp[5]+1,dp[9]+1;
    //dp[9]=dp[8]+1,dp[3]+1;
    //dp[8]=dp[4]+1,dp[7]+1;
    //dp[7]=dp[6]+1
    //dp[6]=dp[3]+1,dp[2]+1,dp[5]+1
    //dp[5]=dp[4]+1
    //dp[4]=dp[2]+1,dp[3]+1
    //dp[3]=dp[2]+1,dp[1]+1
    //dp[2]=dp[1]+1
    //dp[1]=0;
    int input;
    cin>>input;
    vector<int> dp(input+1,0);
    for(int k=1;k<=input;k++)
        dp[k]=k;

    for(int k=2;k<=input;k++){
        if(k%2==0)
            dp[k]=min(dp[k/2],dp[k]);
        if(k%3==0)
            dp[k]=min(dp[k/3],dp[k]);
        dp[k]=min(dp[k],dp[k-1])+1;
    }
    cout<<dp[input]-1<<'\n';
    
    while(input!=0){
        cout<<input<<" ";
        if(dp[input]==dp[input-1]+1)
            input-=1;
        else if(input%2==0 && dp[input]==dp[input/2]+1)
            input/=2;
        else if(input%3==0 && dp[input]==dp[input/3]+1)
            input/=3;
    }
}