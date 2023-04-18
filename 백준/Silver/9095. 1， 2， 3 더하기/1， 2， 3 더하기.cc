//[Baekjoon C++] 1,2,3 더하기 [dp]
#include <iostream>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int cnt;
    int dp[12]={0,};
    cin>>cnt;
    dp[0]=1; dp[1]=2; dp[2]=4;

    for(int k=0;k<cnt;k++){
        int num;
        cin>>num;
        for(int k=3;k<num;k++){
            dp[k]=dp[k-1]+dp[k-2]+dp[k-3];
        }
        cout<<dp[num-1]<<'\n';
    }
}