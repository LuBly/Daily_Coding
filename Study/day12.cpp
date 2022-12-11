//[Programmers C++] 점 찍기
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long d_Square = pow(d,2);
    for(int a=0; a <= d/k; a++){
        long long x_Square = pow(a*k,2);//최대값만 구해서 그만큼 answer에 더한다?
        int tmp = sqrt(d_Square-x_Square);
        answer += (tmp/k)+1;
    }
    
    return answer;
}
