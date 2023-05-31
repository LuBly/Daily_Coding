#include <string>
#include <vector>
#include <set>
using namespace std;

// dfs를 활용하여 문제 풀이
// 불량 사용자 아이디 목록을 돌면서 만족하는 모든 아이디 탐색
// *rodo -> frodo, *rodo ->frodo(X 이미 탐색한 아이디) crodo(O), ****** (abc123)
// 백트래킹 활용하여 계속 탐색 frodo crodo frodoc 
// 중복 처리는 어떻게??
// 결과 값을 set에 저장(idx값 string으로 저장후 오름차순 정렬 025/205 정렬하면 모두 025로 중복 제거됨)
bool is_visit[8]={false,};
set<string> s;
bool check_ban(string user, string ban){
    for(int k=0; k<user.size();k++){
        if(user[k]!=ban[k]&&ban[k]!='*') return false;
    }
    return true;
}
void dfs(vector<string> user_id, vector<string> banned_id, int idx){
    //탈출 조건 idx가 banned_id
    if(idx == banned_id.size()){
        string str = "";
        for(int k=0;k<8;k++){
            if(is_visit[k]) str+=(k+'0');
        }
        s.insert(str);
        return;
    }
    string cur = banned_id[idx];
    for(int k = 0; k < user_id.size(); k++){
        if(user_id[k].size()==cur.size()){
            if(check_ban(user_id[k],cur)&&!is_visit[k]){//ban_id가 될 수 있고 방문하지 않은 노드인 경우
                is_visit[k]=true;
                dfs(user_id,banned_id,idx+1);
                is_visit[k]=false;
            }
        }
    }
}


int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    dfs(user_id,banned_id,0);
    answer = s.size();
    return answer;
}