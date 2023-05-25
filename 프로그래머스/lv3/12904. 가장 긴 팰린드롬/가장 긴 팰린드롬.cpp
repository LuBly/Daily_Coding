#include <iostream>
#include <string>
using namespace std;
//1. pelindrome 체크하는 함수생성
//2. 문자열 시작지점, 끝지점 체크해서 완전탐색
//? 완전탐색하면 O(n^3)이라 망하는게 아닌가..
//시간초과 발생
bool is_palindrome(string tmp){
    int sz = tmp.size();
    for(int k=0;k<sz/2;k++){
        if(tmp[k]!=tmp[sz-1-k])
            return false;
    }
    return true;
}

int solution(string s)
{
    int answer=0;
    for(int length=1;length<=s.size();length++){
        for(int st=0;st<=s.size()-length;st++){
            string check = s.substr(st,length);
            bool flag=true;
            for(int k=0;k<length/2;k++){
                if(check[k]!=check[length-1-k]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                answer=length;
                break;
            }
        }
    }
    return answer;
}