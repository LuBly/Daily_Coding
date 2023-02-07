//[BaekJoon C++] 알고리즘 수업 - 피보나치 수열 [DP 활용]
#include <iostream>
#include <vector>
using namespace std;

int recursive_cnt=1;
int dp_cnt=0;
int re_fib(int n){
    if(n==1||n==2){
        return 1;
    }
    else {
        recursive_cnt++;    
        return (re_fib(n-1)+re_fib(n-2)); 
    }
}

int dp_fib(int n){
    vector<int> dp;
    dp.push_back(1); dp.push_back(1);//dp[0]=1,dp[1]=1
    for(int k=2;k<n;k++){
        dp_cnt++;
        dp.push_back(dp[k-1]+dp[k-2]);
    }
    return dp.back();
}

int main() {
    int input;
    cin>>input;

    re_fib(input); dp_fib(input);
    cout<<recursive_cnt<<" "<<dp_cnt;
}
