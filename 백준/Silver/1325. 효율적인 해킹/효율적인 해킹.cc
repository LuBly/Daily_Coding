//[Baekjoon C++] 효율적인 해킹 [bfs]
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 100001
using namespace std;

vector<int> board[MAX];
bool isVisited[MAX]={false,};

int bfs(int start){
    queue<int>q;
    q.push(start);
    isVisited[start]=true;
    int cnt = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        //cur을 기준으로 접근 가능한 node 카운트
        for(int k=0;k<board[cur].size();k++){
            int nx = board[cur][k];
            //방문한적 없는 노드라면 다음 q에 입력
            if(!isVisited[nx]){
                q.push(nx);
                isVisited[nx]=true;
                cnt++;
            }
        }
    }
    return cnt;
}

void reset(int nodeCnt){
    for(int k=1;k<=nodeCnt;k++){
        isVisited[k]=false;
    }
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int node, edge;
    cin>>node>>edge;
    for(int k=0;k<edge;k++){
        int a,b;
        cin>>a>>b;
        //a->b를 신뢰 = b를 타고 a까지 갈 수 있다.
        board[b].push_back(a);
    }

    //첫번째 노드부터 총 방문 가능한 컴퓨터의 갯수 저장
    vector<int> canHack(node+1,0);
    //최대로 해킹 가능한 컴퓨터의 수를 체크하기 위한 변수
    int maxHack=0;

    for(int k=1;k<=node;k++){
        int result = bfs(k);
        canHack[k]=result;
        maxHack = max(maxHack,result);
        reset(node);
    }
    
    for(int k=1;k<=node;k++){
        if(canHack[k]==maxHack) cout<<k<<" ";
    }
}