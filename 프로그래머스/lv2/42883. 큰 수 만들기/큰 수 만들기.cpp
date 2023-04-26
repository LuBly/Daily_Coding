#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int idx=0, length = number.size()-k, end = k;//check할 idx 시작 지점, 최종 문자길이, 문자 비교 끝 point
    //글자수가 길이(num.size- k)가 될때까지 반복
    //1. 한 자리씩 체크 ex 1924 
    //-> 192/check => 가장 큰수 9, idx = 1
    //-> 24/check => 가장 큰수 4 idx = 4
    //answer = 9 4
    while(answer.size()<length){
        int max = 0;
        for(int i = idx;i<=end;i++){
            int cur = number[i]-'0';
            if(cur>max){
                idx = i;
                max = cur;
            }
        }
        idx++;
        end++;
        answer+=to_string(max);
    }
    return answer;
}