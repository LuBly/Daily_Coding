//[Programmers C++] 숫자의 표현
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int count=1;
    while((count-1)*count/2 < n){
        if((n-(count-1)*count/2)%count==0) answer++;
        count++;
    }
    return answer;
}
