//[Baekjoon C++] 특정 거리의 도시 찾기 [그래프 탐색]
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 300001
using namespace std;

vector<int> board[MAX];
bool isVisit[MAX]={false,};
int cityCnt, routeCnt, dis, start;

vector<int> bfs(int start){
    vector<int> res;
    queue<pair<int,int>> q;//방문노드, cnt;
    
    isVisit[start]=true;
    q.push({start,0});
    
    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(cnt == dis) res.push_back(cur);
        
        for(int k=0;k<board[cur].size();k++){
            int nx = board[cur][k];
            if(!isVisit[nx]){
                isVisit[nx]=true;
                q.push({nx,cnt+1});
            }
        }
    }

    return res;
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);    
    cin>>cityCnt>>routeCnt>>dis>>start;

    for(int k=0;k<routeCnt;k++){
        int st, dt;
        cin>>st>>dt;
        board[st].push_back(dt);
    }

    vector<int> result = bfs(start);

    if(result.empty())
        cout<<"-1";
    else{
        sort(result.begin(),result.end());
        for(auto iter : result){
            cout<<iter<<endl;
        }
    }
    
    
}