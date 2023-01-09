//[Programmers C++] 전화번호 목록
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int count = 1;
    sort(phone_book.begin(), phone_book.end());
    
    for(int a=0;a<phone_book.size()-1;a++){
        string tmp=phone_book[a];
        if(phone_book[a+1].compare(0,tmp.size(),tmp)==0){
            answer=false;
            break;
        }
    }
    return answer;
}