//[Baekjoon C++] 연결 요소의 개수 [DFS]
#include <iostream>
using namespace std;

int node_Cnt, edge_cnt;
bool graph[1001][1001]={false};
bool is_visited[1001]={false};

void dfs(int n){
    is_visited[n]=true;
    for(int a=1;a<=node_Cnt;a++){
        if(graph[n][a] && !is_visited[a]){
            is_visited[a]=true;
            dfs(a);
        }
    }
}


int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int answer=0;
    cin>>node_Cnt>>edge_cnt;
    for(int k=0;k<edge_cnt;k++){
        int a,b;
        cin>>a>>b;
        graph[a][b]=true; graph[b][a]=true;
    }

    for(int j=1;j<=node_Cnt;j++){
        if(!is_visited[j]) {
            dfs(j);
            answer++;
        }
    }

    cout<<answer;
}