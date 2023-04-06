//[Baekjoon C++] 촌수 계산 [BFS]
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int total, st, dest,rel_cnt;
bool relation[101][101];
int is_visited[101]={false,};
queue<int> q;

void BFS(int start){
    q.push(start);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int k=1;k<=total;k++){
            if(relation[cur][k]&&!is_visited[k]){//현재 cur과 선택하는 k와의 관계가 있고 k를 방문한적이 없는 경우 방문
                is_visited[k]=is_visited[cur]+1;
                q.push(k);
            }
        }
    }
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>total>>st>>dest>>rel_cnt;
    fill_n(&relation[0][0],101*101,false);//관계 초기화
    
    //관계 그래프 생성
    for(int k=0;k<rel_cnt;k++){
        int a,b;
        cin>>a>>b;
        relation[a][b]=true; relation[b][a]=true;
    }
    BFS(st);
    if(is_visited[dest]==0) is_visited[dest]=-1;
    cout<<is_visited[dest];
}