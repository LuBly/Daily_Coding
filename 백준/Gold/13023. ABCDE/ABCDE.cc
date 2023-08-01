//[Baekjoon C++] ABCDE [그래프 탐색]
#include <iostream>
#include <vector>
#define MAX 2000
using namespace std;

vector<int> relation[MAX];
bool isVisit[MAX]={false,};
bool isFriend = false;

void dfs(int node, int depth){
    if(depth == 4){
        isFriend = true;
        return;
    }
    for(int k = 0; k < relation[node].size(); k++){
        int nextNode = relation[node][k];
        if(!isVisit[nextNode]){
            isVisit[nextNode]=true;
            dfs(nextNode,depth+1);
            isVisit[nextNode]=false;
        }
    }
}


int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int friendCnt, relationCnt;
    cin>>friendCnt>>relationCnt;
    //친구관계를 타고타고 넘어가면서
    //0->1
    //1->2
    //2->3
    //n->n+1 가 존재하는지 체크
    //Yes No만 판별하면 되므로 dfs로 하나하나 체크
    //a->b->c->d->e 인지 판별하기 위해선 깊이가 4 이상인지만 체크하면 된다.
    for(int k=0;k<relationCnt;k++){
        int st, dt;
        cin>>st>>dt;
        relation[st].push_back(dt);
        relation[dt].push_back(st);
    }

    for(int k=0;k<friendCnt-1;k++){
        isVisit[k]=true;
        dfs(k,0);
        isVisit[k]=false;
        //친구 관계가 하나라도 연결되어 있으면 1을 출력하고 함수 종료
        if(isFriend){
            cout<<1;
            return 0;
        }
    }
    //종료되지 않았으면 모두 있다는 뜻이므로 1을 출력하고 종료
    cout<<0;
    return 0;
}