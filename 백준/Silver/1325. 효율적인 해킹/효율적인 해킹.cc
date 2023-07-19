//[Baekjoon C++] 효율적인 해킹 [BFS]
#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001
using namespace std;

vector<int> board[MAX];
bool is_visit[MAX] = {false,};

int BFS(int start, int cnt){
    is_visit[start]=true;
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        //현재 노드에서 해킹 가능한 pc 전부 탐색
        for(int idx=0;idx<board[cur].size();idx++){
            int nx = board[cur][idx];
            if(!is_visit[nx]){
                is_visit[nx]=true;
                q.push(nx);
                cnt++;
            }
        }
    }
    return cnt;
}

void resetVisit(int N){
    for(int k=1;k<=N;k++)
        is_visit[k]=false;
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N,M;
    cin>>N>>M;
    //board 생성
    for(int k=0;k<M;k++){
        int from,to;
        cin>>from>>to;
        //A(from)->B(to)를 신뢰하면 B(to)=>A(from)로 해킹 가능
        board[to].push_back(from);
    }

    int result[MAX];//결과 저장(node/연결가능 컴퓨터의 개수)
    //노드를 하나하나 순회하며 BFS 계산
    for(int k=1;k<=N;k++){
        int count = BFS(k,1);
        resetVisit(N);
        result[k]=count;
    }

    //최대 해킹 가능한 수 계산
    int maxCnt=-1;
    for(int k=1;k<=N;k++){
        if(result[k]>maxCnt)
            maxCnt = result[k];
    }
    
    //오름차순 출력
    for(int k=1;k<=N;k++){
        if(result[k]==maxCnt)
            cout<<k<<" ";
    }
    
}