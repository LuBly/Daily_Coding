//[BaekJoon C++] 파도반 수열 [DP 활용]
#include <iostream>
#include <vector>
using namespace std;


long long dp[1000] = {1, 1, 1, 2, 2};

long long seq(int num){
    for(int k=5; k<num; k++) dp[k]=dp[k-1]+dp[k-5];
    return dp[num-1];
}

int main() {
    int input;
    int count;
    vector<long long> answer;
    cin>>count;
    for(int a=0;a<count;a++){
        cin>>input;
        answer.push_back(seq(input));
    }
    for(int b=0; b<answer.size();b++) cout<<answer[b]<<endl;

}
