#include <string>
#include <vector>
#include <queue>
#define MAX 1000001
using namespace std;

bool is_visit[MAX] = {false,};
int path[MAX] = {0,};
int dx[3]={0,1,2};
queue<int> q;
void BFS(int start, int target, int num){
    is_visit[start]=true;
    q.push(start);
    while(!q.empty()){
        int x = q.front();
        q.pop();    
        for(int k=0;k<3;k++){
            int nx;
            if(dx[k]==0) nx=x+num;
            else if(dx[k]==1) nx=x*2;
            else nx=x*3;
            
            if(x>target||nx>MAX) continue;
            if(!is_visit[nx]){
                q.push(nx);
                path[nx]=path[x]+1;
                is_visit[nx]=true;
            }
        }
    }
}

int solution(int x, int y, int n) {
    int answer;
    if(x==y) return 0;
    BFS(x,y,n);
    answer = path[y]==0 ? -1 : path[y];
    return answer;
}