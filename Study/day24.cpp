#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int round = 0;
    while(n>1){
        round++;
        if(a%2==1) a=a/2+1;
        else a/=2;
        
        if(b%2==1) b=b/2+1;
        else b/=2;
        
        if(a==b){
            answer = round;
            break;
        }
        n/=2;
    }
    
    return answer;
}