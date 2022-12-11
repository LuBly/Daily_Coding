//[Programmers C++] 귤 고르기
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int count = 1;
    int sum = 0;
    vector<int> size_cnt;
    sort(tangerine.begin(),tangerine.end());
    
    for(int i = 0; i < tangerine.size(); i++){
        if(i>0&&tangerine[i]==tangerine[i-1]){
            count++;
            if(tangerine.size()-1 == i) size_cnt.push_back(count);
        }
        else {
            size_cnt.push_back(count);
            count = 1;
        }
     
    }
    
    sort(size_cnt.rbegin(),size_cnt.rend());
    
    for(int p = 0; p < size_cnt.size(); p++){
        sum+=size_cnt[p];
        
        if(sum>=k){
            answer = p;
            break;
        }
    }
    answer+=1;
    
    return answer;
}
