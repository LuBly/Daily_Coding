//[Baekjoon C++] LCS [DP]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
문제
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

입력
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

출력
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.

예제
ACAYKP
CAPCAK

dp[1] = 0
A
C
dp[2] = 1 C
AC
CA
dp[3] = 2 CA
ACA
CAP
dp[4] = 2 CA,AC
ACAY
CAPC
dp[5] = 3 ACA
ACAYK
CAPCA
dp[6] = 4 ACAK
ACAYKP
CAPCAK
*/

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    string str1, str2;
    cin >> str1 >> str2;

    int str1Size = str1.size(), str2Size = str2.size();
    vector<vector<int>> dp(str1Size + 1, vector<int>(str2Size + 1, 0));

    for(int k = 1; k <= str1Size; k++){
        for(int j = 1; j <= str2Size; j++){
            if(str1[k-1] == str2[j-1]) dp[k][j] = dp[k-1][j-1] + 1;
            else dp[k][j] = max(dp[k-1][j], dp[k][j-1]);
        }
    }
    cout << dp[str1Size][str2Size];
}