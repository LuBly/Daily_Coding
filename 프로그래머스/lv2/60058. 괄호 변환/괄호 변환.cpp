#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

//uv 생성
vector<string> make_uv(string w){
    int op=0,cl=0;
    vector<string> output;
    string u="",v="";
    int idx;
    for(int i=0;i<w.size();i++){
        u+=w[i];
        if(w[i]=='(') op++;
        else cl++;
        if(op==cl){
            output.push_back(u);
            idx=i;
            break;
        }
    }
    
    for(int j=idx+1;j<w.size();j++){
        v+=w[j];
    }
    output.push_back(v);
    return output;
}

//괄호 확인 절차
bool check(string u){
    stack<char> s;
    for(int i=0;i<u.size();i++){
        if(u[i]=='(')s.push(u[i]);
        else{
            if(s.empty()) return false;
            else s.pop();
        }
    }
    return true;
}

string result = "";//반환 결과값
string func(string w){
    //1. 입력이 빈 문자열일 경우, 빈 문자열을 반환
    if(w == "") return "";
        
    //2. 문자열 w를 u,v로 분리
    vector<string> uv = make_uv(w);
    string u = uv[0];
    string v = uv[1];
    //3. 문자열 u가 "올바른 괄호 문자열" 이라면
    if(u[0]=='('){
        //문자열 v에 대해 1단계부터 다시 수행
        //3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다. 
        return u+func(v);
    }
    //4. 문자열 u가 "올바른 괄호 문자열"이 아니라면
    else{
        //4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다.
        string n = "";
        //4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다
        //4-3. ')'를 다시 붙입니다.
        
        //4-4. u의 첫 번째와 마지막 문자를 제거하고 //나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
        for(int k=1;k<u.size()-1;k++){
            if(u[k]=='(') n+=")";
            else n+="(";
        }
        return "("+func(v)+")"+n;
    }

}


string solution(string p) {
    string answer = func(p);
    return answer;
}