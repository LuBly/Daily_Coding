//[Programmers C++] 124 나라의 숫자
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int reminder=-1;
    while(n>0){
        reminder = n%3;
        n/=3;
        if(reminder==0){
            answer= '4'+answer;
            n--;
        }
        if(reminder==1) answer = '1' + answer;
        if(reminder==2) answer = '2' + answer;
    }
    return answer;
}