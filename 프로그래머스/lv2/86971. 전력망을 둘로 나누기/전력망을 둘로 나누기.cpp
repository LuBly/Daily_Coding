#include <string>
#include <vector>

using namespace std;
bool map[101][101] = {false,};
bool is_visited[101]={false,};
int cnt;
void dfs(int n,int cur){
    is_visited[cur]=true;
    for(int i=1;i<=n;i++){
        if(!is_visited[i]&&map[cur][i]){
            dfs(n,i);
            cnt++;
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    
    for(int k=0;k<wires.size();k++){//wire 정보 배열에 저장
        int st = wires[k][0], dt = wires[k][1];
        map[st][dt]=true;
        map[dt][st]=true;
    }
    for(int k=0;k<wires.size();k++){//wire 하나씩 끊으면서 dfs 계산
        fill_n(&is_visited[0],101,false);
        int st = wires[k][0], dt = wires[k][1];
        //연결 끊기
        map[st][dt]=false;
        map[dt][st]=false;
        vector<int> data;
        for(int j=1;j<=n;j++){//노드 순환하면서 방문하지 않은 node와 연결된 모든 노드 방문
            if(!is_visited[j]){
                cnt=0;
                dfs(n,j);
                data.push_back(cnt);
            }
        }
        answer = min(answer, abs(data[0]-data[1]));        
        //계산이 종료된 후 map정보 초기화
        map[st][dt]=true;
        map[dt][st]=true;
    }
    
    
    return answer;
}