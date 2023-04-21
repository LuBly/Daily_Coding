//[Baekjoon C++] DFS와 BFS [dfs bfs]
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int node, edge, start;
bool is_visited[1001] = {false,};
bool map[1001][1001] = {false,};
queue<int> q;
void dfs(int st){
    cout<<st<<" ";
    is_visited[st]=true;
    for(int k=1;k<=node;k++){
        if(map[st][k]&&!is_visited[k]){//방문하고자 하는 노드가 갈 수 있고, 방문한적 없다면
            dfs(k);
        }
    }
}
void clear(){
    fill_n(&is_visited[0],1001,false);
}
void bfs(int st){
    q.push(st);
    is_visited[st]=true;

    while(!q.empty()){
        int cur = q.front();
        cout<<cur<<" ";
        q.pop();
        for(int k=1;k<=node;k++){
            if(map[cur][k] && !is_visited[k]){
                q.push(k);
                is_visited[k]=true;
            }
        }
    }
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>node>>edge>>start;

    for(int k=0;k<edge;k++){
        int a,b;
        cin>>a>>b;
        map[a][b]=true; map[b][a]=true;
    }

    dfs(start);
    cout<<'\n';
    clear();
    bfs(start);
}