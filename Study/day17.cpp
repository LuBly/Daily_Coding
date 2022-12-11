//[Programmers C++] 올바른 괄호
#include <string>
#include <vector>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    vector<bool> is_Open;
    for(int k = 0; k<s.size(); k++){
        if(s[k]=='('){
            is_Open.push_back(true);
        }
        else{
            if(is_Open.empty()){
                answer = false;
                break;
            }
            else is_Open.pop_back();
        }
    }
    if(!is_Open.empty()) answer = false;
    return answer;
}
