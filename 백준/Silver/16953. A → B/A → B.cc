//[Baekjoon C++] A->B [BFS]
#include <iostream>
#include <queue>
#define MAX 1000000000
using namespace std;

int dx[2]={0,1};

queue<pair<long long, int>> q; // 숫자, count
void BFS(long long start, long long target){
    q.push(make_pair(start,1));
    while(!q.empty()){
        long long x = q.front().first;
        long long cnt = q.front().second;
        q.pop();
        for(int k=0;k<2;k++){
            long long nx;
            if(dx[k]==0) nx = x*2;
            else nx = x*10 +1;

            if(nx>target||nx>MAX)continue;
            else if(nx==target){
                cout<<cnt+1;
                return;
            }
            else
                q.push(make_pair(nx,cnt+1));
            
        }
    }
    cout<<-1;
}


int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    long long st, tgt; 
    cin>>st>>tgt;
    BFS(st,tgt);
}