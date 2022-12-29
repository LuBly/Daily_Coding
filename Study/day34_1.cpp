//[Programmers C++] 시저 암호
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int k=0;k<s.size();k++){
        if(s[k]==' ') continue;
        else if(s[k]>=65&&s[k]<=90){//대문자
            s[k]=(s[k]-65+n)%26+65;
        }
        else if(s[k]>=97&&s[k]<=122){//소문자122+25-26 121
            s[k]=(s[k]-97+n)%26+97;
        }
    }
    answer.append(s);
    return answer;
}