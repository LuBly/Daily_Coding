#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
// 보석 개수 파악
// start, end 동시 시작
// 1. end 뒤로 빼면서 보석 개수 전부 포함할 때까지 이동
// 2. 전부 포함했을 때, start에서 보석이 하나 사라질 때까지 이동.
vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    
    unordered_map<string,int> gemData;
    for(auto gem : gems)
        gemData[gem]++;
    
    int idx = 0, start = 0, end = 0, minLen = 987654321;
    
    unordered_map<string,int> curGems;
    while(true){
        for(idx = end; idx < gems.size(); idx++){
            curGems[gems[idx]]++;
            if(curGems.size() == gemData.size()){
                end = idx;
                break;
            }
        }
        
        if(idx == gems.size())
            break;
        
        for(idx = start; idx < gems.size(); idx++){
            if(curGems[gems[idx]] == 1){
                start = idx;
                break;
            }
            else curGems[gems[idx]]--;
        }
        
        if(end - start < minLen){
            answer[0] = start+1;
            answer[1] = end+1;
            minLen = end - start;
        }
        
        curGems.erase(gems[start]);
        start++;
        end++;
    }
    return answer;
}