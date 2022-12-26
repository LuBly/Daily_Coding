//[Programmers C++] 문자열 나누기
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int f_num = 0;
    int x_num = 0;
    vector<char> tmp;
    
    for(int k=0;k<s.size();k++){
        if(tmp.empty()) tmp.push_back(s[k]);
        
        if(s[k]==tmp[0]) f_num++;
        else x_num++;
        
        if(f_num==x_num){
            tmp.pop_back();
            f_num=0;
            x_num=0;
            answer++;
        }
    }
    if(f_num>0) answer++;
    return answer;
}