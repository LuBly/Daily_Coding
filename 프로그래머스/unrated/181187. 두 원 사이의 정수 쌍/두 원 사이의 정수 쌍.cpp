#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    //단순 int*int의 경우 제곱 계산이 올바르지 않은 경우 발생 long long 형태로 변환하여 문제를 풀이하거나 pow를 활용하여 문제 해결
    long long R1 = pow(r1,2);
    long long R2 = pow(r2,2); 
    
    for(int x=1;x<r2;x++){
        long long X = pow(x,2);
        double st = R1-X>0 ? sqrt(R1-X) : 0, end = sqrt(R2-X);
        answer += floor(end)-ceil(st)+1;
    }
    answer++;
    return answer*4;
}