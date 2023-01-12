//[Programmers C++] [3차] 압축
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string,int> str_map;
    int result;
    int end=26;
    for(int a=65;a<=90;a++){//map에 한글자 인덱스 입력
        string ch="";
        ch+=a;
        str_map[ch]=a-64;
    }
    string current_str="";//현재 입력
    string check_str="";//다음 글자와 확인해서 사전에 있는지 확인해볼 str
    for(int b=0;b<msg.size();b++){
        current_str+=msg[b];
        check_str+=current_str; check_str+=msg[b+1]; 
        if(str_map[check_str]!=0){//사전에 데이터가 있는 경우
            check_str="";
        }
        else{//사전에 데이터가 없는경우 현재 입력(w)를 출력
            //cout<<"current_str: "<<current_str<<" check_str: "<<check_str<<" msg[b+1]: "<<msg[b+1]<<endl;
            result=str_map[current_str];
            answer.push_back(result);//현재 입력(w)를 출력
            str_map[check_str]=end+1;//사전 추가
            end++;
            current_str=""; check_str=""; //검색용 string 초기화
        }
    }
    
    return answer;
}