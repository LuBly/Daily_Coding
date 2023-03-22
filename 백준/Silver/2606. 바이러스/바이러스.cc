//[Baekjoon C++] 바이러스 [DFS]
#include <iostream>
#include <vector>
using namespace std;

bool graph[101][101]={false};
bool is_visited[101]={false};
int com_num, network, answer=0;

void dfs(int n){
    answer++;
    is_visited[n]=true;
    for(int k=1;k<=com_num;k++){
        if(graph[n][k]&&!is_visited[k]) 
            dfs(k);
    }
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>com_num>>network;
    for(int k=0;k<network;k++){
        int a,b;
        cin>>a>>b;
        graph[a][b]=true;
        graph[b][a]=true;
    }

    dfs(1);
    cout<<--answer;
}