//[Baekjoon C++] LCS [dp]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    string input1;
    string input2;

    cin >> input1 >> input2;
    input1 = '0' + input1;
    input2 = '0' + input2;
    vector<vector<int>> dp(input1.size(), vector<int>(input2.size(), 0));

    for(int k = 1; k < input1.size(); k++){
        for(int j = 1; j < input2.size(); j++){
            if(input1[k] == input2[j]){
                dp[k][j] = dp[k - 1][j - 1] + 1;
            }
            else{
                dp[k][j] = max(dp[k-1][j], dp[k][j-1]);
            }
        }
    }

    cout << dp[input1.size()-1][input2.size()-1];
    /*
          A C A Y K P
        0 1 2 3 4 5 6
      0 0 0 0 0 0 0 0  
    C 1 0 0 1 1 1 1 1
    A 2 0 1 1 2 2 2 2
    P 3 0 1 1 2 2 2 3
    C 4 0 1 2 2 2 2 3
    A 5 0 1 2 3 3 3 3
    K 6 0 1 2 3 3 4 4
    */
}