#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
/*
N1 : N
N2 : N1ㅁN1, NN
N3 : N1ㅁN2, N2ㅁN1, NNN
N4 : N1ㅁN3, N2ㅁN2, N3ㅁN1, NNNN


위의 결과를 통해 DP[i]에는 N i개로 만들 수 있는 숫자들을 저장해야겠다고 생각하였다.
또한, Nk는 Ni와 Nj(i + j = k)의 조합으로 구성된다는 규칙성을 파악할 수 있었다.
(실제 코드에서는 0 <= i < 8으로 구현해서 i + j + 1 = k이어야 한다.)
 
 
DP[k] = DP[i] ㅁ DP[j] (i + j = k), NN..N(N으로만 이루어진 k자리 숫자)
*/


unordered_set<int> dp[8];
//dp[자리수] = 숫자들
void MakeNN(int N){
    int num = N;
    for(int k = 1; k < 8; k++){
        num = num * 10 + N;
        dp[k].insert(num);
    }
}

int solution(int N, int number) {
    int answer = -1;
    if(N == number) return 1;
    dp[0].insert(N);
    
    // 사칙연산 없이 기본적으로 만들 수 있는 숫자들 생성
    // ex) NN, NNN, NNNN, ~~~
    MakeNN(N);
    
    // 사칙연산
    for(int k = 1; k < 8; k++){
        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){
                if(i + j + 1 != k) continue;
                for(int a : dp[i]){
                    for(int b : dp[j]){
                        dp[k].insert(a + b);
                        if(a > b) dp[k].insert(a - b);
                        dp[k].insert(a * b);
                        if(a / b > 0) dp[k].insert(a / b);
                    }
                }
            }
        }    
    }
    // set을 채웠으니 number가 set에 들어가 있는지 여부만 확인하면 된다!
    for(int k = 0; k < 8; k++){
        if(dp[k].find(number) != dp[k].end()){
            answer = k + 1;
            break;
        }  
    }
    
    return answer;
}