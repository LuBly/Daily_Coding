#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<string>> ticket;
vector<string> answer;

bool is_check[10001] = {false,};
bool is_answer = false;

void dfs(string start, int ticket_cnt){
    answer.push_back(start);
    if(ticket_cnt == ticket.size()){
        is_answer = true;
    }
    for(int k=0;k<ticket.size();k++){
        if(is_check[k]) continue;//이미 확인한 티켓이면 out
        if(ticket[k][0] == start){//방문한 티켓의 출발점이 start라면 dfs 진입
            is_check[k]=true;
            dfs(ticket[k][1],ticket_cnt+1);
            
            if(!is_answer){//항공권을 다 사용하지 못했는데 길이 끊긴 경우 backtracking으로 경로 다시 탐색
                answer.pop_back();
                is_check[k] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(),tickets.end());
    ticket=tickets;
    dfs("ICN",0);
    return answer;
}