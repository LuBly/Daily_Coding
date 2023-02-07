//[Programmers C++] 둘만의 암호
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    string check = "abcdefghijklmnopqrstuvwxyz";
    for(int k=0;k<skip.size();k++){
        check.erase(remove(check.begin(),check.end(),skip[k]),check.end());//문자열에서 특정 문자 삭제하기.
    }
    for(int j=0;j<s.size();j++){
        char c=s[j];
        int idx = check.find(c);
        idx = (idx+index)%check.size();
        answer+=check[idx];
    }
    
    
    return answer;
}