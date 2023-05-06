//[Baekjoon C++] 스타트링크 [DFS/BFS]
#include <iostream>
#include <vector>
#include <queue>
#define MAX 1000001
using namespace std;

int height, st, target, up, down;
vector<int> path(MAX,0);
vector<bool> is_visit(MAX,false);
void BFS(int start){
    queue<int> q;    
    q.push(start); 
    is_visit[start]=true;
    while(!q.empty()){
        int cur = q.front(), next;
        q.pop();
        for(int k=0;k<2;k++){//up down
            int next;
            if(k==0) next = cur + up;
            else next = cur - down;
            
            if(next<1||next>height)continue;

            if(!is_visit[next]){
                is_visit[next]=true;
                path[next]=path[cur]+1;
                q.push(next);
            }
        }
    }
}

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>height>>st>>target>>up>>down;
    if(st==target){
        cout<<0;
        return 0;
    }
    BFS(st);
    
    if(path[target]!=0)
        cout<<path[target];
    else
        cout<<"use the stairs";
}
