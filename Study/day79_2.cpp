//[Programmers C++] 대충 만든 자판

/*
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    for(int k=0;k<targets.size();k++){//계산 targets.size() 최대=100
        bool is_possible = false;
        int result = 0;
        
        for(int p=0;p<targets[k].size();p++){//타겟 문자열의 단어 하나하나의 최소 버튼입력 수를 체크
            char search_ch=targets[k][p];
            int min=1000;
            
            for(int j=0;j<keymap.size();j++){
                int idx = keymap[j].find(search_ch);
                if(idx!=string::npos){//keymap에서 문자를 찾았을 때, 해당 문자의 idx를 min에 저장
                    is_possible = true;
                    if(idx < min) min = idx;            
                }
            }
            
            result+=min+1;
        }
        if(is_possible) answer.push_back(result);
        else answer.push_back(-1);
        
    }
    
    return answer;
}
테스트 케이스 14~23까지 실패처리가되어 map을 사용해보고자함.
*/ 

#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> K_map;
    
    for(int k=0;k<keymap.size();k++){
        for(int j=0;j<keymap[k].size();j++){
            char cur = keymap[k][j];
            if(K_map[cur]) K_map[cur]=min(K_map[cur],j+1);
            else K_map[cur]=j+1;
        }
    }
    
    for(auto iter:K_map){
        cout<<iter.first<<" "<<iter.second<<endl;
    }
    cout<<endl;

    for(int p=0;p<targets.size();p++){
        int result=0;
        for(int q=0;q<targets[p].size();q++){
            char tmp = targets[p][q];
            cout<<tmp<<" "<<K_map[tmp]<<endl;
            if(K_map[tmp]) result+=K_map[tmp];
            else {
                result=-1;
                break;
            }
        }
        answer.push_back(result);
    }
    
    return answer;
}