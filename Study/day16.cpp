#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool isFirst = true;
    for(int k = 0; k<s.size(); k++){
        if(s[k] == ' '){
            isFirst = true;
            continue;
        }
        if(isFirst){
            if(s[k]>=97&&s[k]<=122) s[k] -= 32;
            isFirst = false;
            continue;
        }
        if(s[k]>=65&&s[k]<=90) s[k]+=32;
    }
    answer.append(s);
    return answer;
}