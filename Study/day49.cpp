//[Programmers C++] 롤케이크 자르기
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    set<int> tmpA;
    set<int> tmpB;
    map<int,int> Cur; // 현재 
    for(int j=0;j<topping.size();j++){
        tmpB.insert(topping[j]);
        Cur[topping[j]]++;
    }
    
    
    for(int k=0;k<topping.size();k++){
        tmpA.insert(topping[k]);
        if(Cur[topping[k]]>1) Cur[topping[k]]--;
        else tmpB.erase(topping[k]);
        
        if(tmpA.size()==tmpB.size()) answer++;
    }
    
    
    return answer;
}