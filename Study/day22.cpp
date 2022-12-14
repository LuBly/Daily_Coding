#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string s)
{
    int answer = 0;
    vector<char> stack;
    for(int k = 0; k<s.size(); k++){
        if(stack.size()>0&&stack.back()==s[k]) stack.pop_back();
        else stack.push_back(s[k]);
    }
    if(stack.empty()) answer = 1;
    return answer;
}