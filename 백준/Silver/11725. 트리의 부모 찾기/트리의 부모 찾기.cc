//[Baekjoon C++] 트리의 부모 찾기 [bfs]
#include <iostream>
#include <queue>
#include <vector>
#define MAX 100001
using namespace std;

vector<int> parent(MAX,0);//부모노드를 저장할 배열
vector<bool> is_visit(MAX,false);//특정 노드를 방문했는지에 대한 bool
vector<int> board[MAX];
//bfs로 Level별 check
//queue에서 pop되는 
void bfs(int start,int node){
    queue<int> q;
    q.push(start);
    is_visit[start]=true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int k=0;k<board[cur].size();k++){
            int child = board[cur][k];
            if(!is_visit[child]){//edge가 있고, 방문한적 없는 노드라면 방문
                parent[child]=cur;
                is_visit[child]=true;
                q.push(child);
            }
        }
    }
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int cnt;
    cin>>cnt;
    
    
    for(int k=0;k<cnt-1;k++){
        int a,b;
        cin>>a>>b;
        board[a].push_back(b);
        board[b].push_back(a);
    }

    bfs(1,cnt);

    for(int k=2;k<=cnt;k++)
        cout<<parent[k]<<'\n';
}