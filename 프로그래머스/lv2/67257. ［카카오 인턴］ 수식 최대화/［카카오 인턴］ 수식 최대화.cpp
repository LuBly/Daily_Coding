#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// + < - < *
// + < * < -
// - < + < *
// - < * < +
// * < + < -
// * < - < +
long long calculate(long long a,long long b,char op){
    if(op=='+')
        return a+b;
    if(op=='-')
        return a-b;
    if(op=='*')
        return a*b;
}

long long solution(string expression) {
    long long answer = 0;
    string tmp = "";
    vector<char> cal;
    vector<long long> num;
    // string parsing
    for(int k=0;k<expression.size();k++){
        char cur = expression[k];
        if(cur=='+'||cur=='-'||cur=='*'){
            cal.push_back(cur);
            num.push_back(stoll(tmp));
            tmp="";
        }
        else
            tmp+=cur;
    }
    num.push_back(stoll(tmp));
    vector<int> op {0,1,2};
    string oper = "*+-";
    //계산
    //op 배열을 순열로 돌리면서 우선순위대로 계산
    do{
        vector<long long> nums = num;
        vector<char> cals = cal;
            
        for(int k=0;k<op.size();k++){
            for(int j=0;j<cals.size();){
                if(cals[j]==oper[op[k]]){
                    long long res = calculate(nums[j],nums[j+1],cals[j]);
                    nums.erase(nums.begin()+j);
                    nums.erase(nums.begin()+j);
                    nums.insert(nums.begin()+j,res);
                    
                    cals.erase(cals.begin()+j);
                }
                else
                    j++;
            }
        }
        answer = max(answer,abs(nums[0]));
    }
    while(next_permutation(op.begin(),op.end()));
    
    
    return answer;
}