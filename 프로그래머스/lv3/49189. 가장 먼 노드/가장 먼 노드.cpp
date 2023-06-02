#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 20001
using namespace std;
//20000 50000 1,000,000,000
bool is_visit[MAX]={false,};
int path[MAX] = {0,};
int mx = 0;

void bfs(int start, vector<vector<int>> graph){
    queue<int> q;
    is_visit[start] = true;
    q.push(start);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto next : graph[cur]){
            if(!is_visit[next]){
                is_visit[next] = true;
                path[next]=path[cur]+1;
                mx = max({mx,path[next]});//이동거리의 최대값 계산
                q.push(next);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    //최단 경로로 이동했을 때 간선의 개수가 가장 많은 노드
    // bfs를 통해 최대 이동 거리를 계산
    // path에서 max값과 일치하는 node의 갯수 = answer
    vector<vector<int>> graph(n+1);
    for(auto idx : edge){
        int from = idx[0];
        int to = idx[1];
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    bfs(1,graph);
    for(int k = 1; k<=n; k++){
        if(path[k] == mx)
            answer++;
    }
    return answer;
}