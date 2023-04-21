//[Baekjoon C++] 1로 만들기 [dp]
#include <iostream>
#include <vector>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int num;
    cin>>num;
    vector<int> dp(num+1);
    dp[1]=0, dp[2]=1, dp[3]=1;
    for(int k=2;k<=num;k++){
        int min = dp[k-1]+1;//1을 빼는걸 기본으로 가지고 가고
        if(k%2==0)//2로 나눌 때
            min = (min<dp[k/2]+1) ? min : dp[k/2]+1;
        if(k%3==0)//3으로 나눌 때
            min = (min<dp[k/3]+1) ? min : dp[k/3]+1;
            
        dp[k]=min;//3개중에 최소값을 dp[k]에 입력
    }
    cout<<dp[num];
 }