//[BaekJoon C++] 숨바꼭질 [BFS]
#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001
using namespace std;

int path[MAX]={0,};
bool is_visited[MAX]={false,};
int dx[3]={0,-1,1};
queue<int> q;
void BFS(int st, int dt){
    q.push(st);
    is_visited[st]=true;
    while(!q.empty()){
        int x=q.front();
        q.pop();

        if(x==dt){
            while(!q.empty()) q.pop();
            return;
        }

        for(int k=0;k<3;k++){
            int nx;
            if(dx[k]==0) nx=x*2;
            else nx=x+dx[k];

            if(nx>=MAX||nx<0) continue;
            if(!is_visited[nx]){
                is_visited[nx]=true;
                path[nx]=path[x]+1;
                q.push(nx);
            }
        }
    }
}

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int start, dest;
    cin>>start>>dest;
    BFS(start,dest);
    cout<<path[dest];
}    