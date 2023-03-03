//[BaekJoon C++] DFS와 BFS [DFS/BFS]
#include <iostream>
#include <queue>

using namespace std;

int node, edge, start;
int graph[1001][1001];//인접 행렬 그래프
bool isVisited[1001];//방문 노드 
queue<int> q;

void reset(){//방문한 노드를 전부 0으로 수정
    for(int i=1;i<=node;i++){
        isVisited[i]=0;
    }
}

void DFS(int v){//정점 하나하나 심층 탐색
    isVisited[v]=true;
    cout<<v<<" ";
    for(int i=1;i<=node;i++){
        if(graph[v][i]==1&&isVisited[i]==0)//현재 정점과 연결되어있고 방문하지 않은 노드로 이동
            DFS(i);
    }
}

void BFS(int v){
    q.push(v);//방문한 node를 큐에 저장
    isVisited[v] =true;
    cout<<v<<" ";
    while(!q.empty()){
        v=q.front();
        q.pop();
        for(int j=1;j<=node;j++){
            if(graph[v][j]==1 && isVisited[j]==0){//현재 정점과 연결되어있고 방문하지 않았으면 진입
                q.push(j);
                isVisited[j]=true;
                cout<<j<<" ";
            }
        }
    }
}

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>node>>edge>>start;
    for(int k=0;k<edge;k++){
        int a, b;
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }

    reset();
    DFS(start);
    cout<<'\n';
    reset();
    BFS(start);

}