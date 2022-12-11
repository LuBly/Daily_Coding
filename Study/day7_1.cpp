//[Programmers C++] 자릿수 더하기
#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    int tmp = 0;
    for(int k=0; k<9;k++){
        answer += n%10;
        n = n/10;
    }
    cout << answer << endl;

    return answer;
}
