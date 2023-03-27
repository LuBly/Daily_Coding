#include <string>
#include <vector>

using namespace std;
int is_visited[201]={false};

void dfs(int cur, int size, vector<vector<int>> map){
    is_visited[cur]=true;
    for(int k=0;k<size;k++){
        if(map[cur][k]==1 && !is_visited[k]) dfs(k,size,map);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int j=0;j<n;j++){
        if(!is_visited[j]) {
            dfs(j,n,computers);
            answer++;
        }
    }
    return answer;
}