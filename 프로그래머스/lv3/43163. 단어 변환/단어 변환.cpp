#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//2중 dfs?
//map을 사용한 dfs/bfs?
//->한문자만 다른지 check
int answer = 50;
bool is_visit[50]={false,};

//두개의 문자열이 한문자만 다른지 체크
bool check_diff(string cmp1, string cmp2){
    int diff_cnt = 0;
    for(int k=0;k<cmp1.size();k++){
        if(cmp1[k]!=cmp2[k])
            diff_cnt++;
    }
    if(diff_cnt==1) return true;
    return false;
}

void dfs(string begin, string target, vector<string>words, int step){
    if(begin==target){
        answer = min(answer,step);
        return;
    }
    
    for(int k=0;k<words.size();k++){
        if(check_diff(begin,words[k])&&!is_visit[k]){//한개의 문자만 다르고 방문하지 않은 노드라면 탐색 시작
            is_visit[k]=true;
            dfs(words[k],target,words,step+1);
            is_visit[k]=false;
        }
    }
    return;
}

int solution(string begin, string target, vector<string> words) {
    dfs(begin,target,words,0);
    if(answer == 50) answer = 0;
    return answer;
}