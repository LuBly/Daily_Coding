#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_visited[101] = {false,};
int card_map[101]={0,};//경로 check, start/end
int cnt;
void dfs(int st){
    is_visited[st]=true;
    int nx = card_map[st];
    if(!is_visited[nx]){
        cnt++;
        dfs(nx);
    }
}

int solution(vector<int> cards) {
    int answer = 0;
    
    for(int k=0;k<cards.size();k++){
        card_map[k+1]=cards[k];
    }
    
    for(int k=0;k<cards.size();k++){//시작포인트 설정 모든 위치에서 시작
        vector<int> result;
        fill_n(&is_visited[0],101,false);//상자 초기화
        cnt=1;
        dfs(cards[k]);
        result.push_back(cnt);
        for(int j=0;j<cards.size();j++){
            if(!is_visited[cards[j]]){
                cnt = 1;
                dfs(cards[j]);
                result.push_back(cnt);            
            }
        }
        sort(result.rbegin(),result.rend());//내림차순 정리
        if(result.size()==1) answer=0;
        else answer = (result[0]*result[1])>answer ? result[0]*result[1] : answer;
    }
    
    return answer;
}