//[Programmers C++] 가운데 글자 가져오기
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    if(s.size()%2==0){//짝수 
        answer+=s[s.size()/2-1];
        answer+=s[s.size()/2];
    }
    else{
        answer+=s[s.size()/2];
    }
    return answer;
}