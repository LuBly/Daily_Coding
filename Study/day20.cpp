#include <string>
#include <vector>
//#include <iostream>
using namespace std;

int check_num(int p){
    int count = 0;
    vector<bool> bit;
    
    while(p != 0){
        if(p%2==1) bit.push_back(1);
        else bit.push_back(0);
        p/=2;
    }
    
    for(int k =0; k<bit.size();k++){
        if(bit[k]==true) {
            count++;
        }
    }
    return count;
}

int solution(int n) {
    int answer = n+1;
    int tmp =n;
    int base_num = check_num(tmp);
    while(n>0){
        if(base_num==check_num(answer)) return answer;
        answer++;
    }
    return answer;
}