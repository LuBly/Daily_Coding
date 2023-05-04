#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    for(int k=0;k<s.size();k++){
        if(s[k]<48||s[k]>57) answer=false; 
    }
    if(s.size()!=4&&s.size()!=6) answer=false;
    return answer;
}