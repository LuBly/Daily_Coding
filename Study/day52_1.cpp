//[Programmers C++] [3차] n진수 게임
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string mk_str(int num, int bit){
    string result ="";
    if(num==0) {
        result+='0';
        return result;
    }
    while(num>0){
        int cul = num%bit;
        if(cul==10) result+='A';
        else if(cul==11) result+='B';
        else if(cul==12) result+='C';
        else if(cul==13) result+='D';
        else if(cul==14) result+='E';
        else if(cul==15) result+='F';
        else result+=(cul)+'0';    
        num/=bit;
    }
    reverse(result.begin(),result.end());
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string Line="";
    int num=0;
    for(int a=0; a<t;a++){
        int cur=a*m+(p-1);
        //cout<<"cur: "<<cur<<" Line: "<<Line<<endl;
        while(cur>=Line.size()) {
            Line+=mk_str(num,n);
            num++;
        }
        answer+=Line[cur];
    }
    
    
    return answer;
}