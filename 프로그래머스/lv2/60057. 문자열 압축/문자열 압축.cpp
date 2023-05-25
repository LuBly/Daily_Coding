#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = s.size();
    //하나씩 다 체크?
    for(int length=1;length<=s.size()/2;length++){//1~1000까지 모두 합산 -> 1000*999/2 할만하다
        string check="";
        string result="";
        int cnt=1;
        for(int k=0;k<length;k++)//맨 처음 기준값 생성
            check+=s[k];
        for(int k=length;k<s.size();k+=length){//ex length 2 시작점 2부터 2칸 체크
            string cmp="";
            for(int j=k;j<k+length;j++){
                if(j<s.size())
                    cmp+=s[j];
                else
                    break;
            }                
            if(cmp==check)
                cnt++; 
            else{
                if(cnt>1)
                    result+=to_string(cnt);
                result+=check;
                check=cmp;
                cnt=1;
            }
        }
        if(cnt>1)
            result+=to_string(cnt);
        result+=check;
        
        result.size()<answer ? answer = result.size() : answer = answer;
    }
    return answer;
}