#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    while(storey!=0){
        int k=storey%10;
        if(k>=6){
            storey+=10-k;
            answer+=10-k; 
        }
        else if(k==5&&(storey/10)%10>=5){//나머지가 5이면서 다음자릿수가 5보다 크거나 같을 때
            storey+=10-k;
            answer+=10-k;
        }
        else
            answer+=k;
        storey/=10;
    }
    return answer;
}