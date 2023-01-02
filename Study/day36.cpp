//[Programmers C++] [1차] 다트 게임
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int tmp;
    vector<int> num;
    for(int k=0;k<dartResult.size();k++){
        if(dartResult[k]=='P') continue;
        
        if(dartResult[k]>='0'&&dartResult[k]<='9'){//숫자일 때
            if(dartResult[k]=='1'){
                if(dartResult[k+1]=='0'){
                    tmp=10;
                    dartResult[k+1]='P';
                    continue;
                }
            }
            tmp=dartResult[k]-'0';
            continue;
        }
        //S,D,T 문자일 때
        if(dartResult[k]=='S') {
            tmp=pow(tmp,1);
            num.push_back(tmp);
            continue;
        }
        if(dartResult[k]=='D') {
            tmp=pow(tmp,2);
            num.push_back(tmp);
            continue;
        }
        if(dartResult[k]=='T') {
            tmp=pow(tmp,3);
            num.push_back(tmp);
            continue;
        }
        
        if(dartResult[k]=='*'){
            if(num.size()==1) num[0]*=2;
            else{
                num[num.size()-1]*=2;
                num[num.size()-2]*=2;
            }
            continue;
        }
        if(dartResult[k]=='#'){
            num.back()*=-1;
            continue;
        }
    }
    
    for(int j=0;j<num.size();j++) {
        //cout << num[j]<<endl;
        answer+=num[j];
    }
    
    return answer;
}