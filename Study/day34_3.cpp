#include <string>
#include <vector>
//[Programmers C++] H-index
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int cur = citations.size();
    for(int k = cur;k>0;k--){
        int upper =0;
        
        for(int j=0;j<citations.size();j++){
            if(citations[j]>=k) upper++;
        }
        //cout <<k <<" " << upper <<endl;
        if(upper>=k&&citations.size()-upper<=k){
            answer = k;
            break;
        }
    }
    return answer;
}