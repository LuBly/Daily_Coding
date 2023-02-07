//[BaekJoon C++] N과 M(3) [백트래킹]
#include <iostream>
#include <vector>
using namespace std;


int N,M; //N=숫자 갯수, M=길이


void dfs(int cnt,vector<int> select){
    if(cnt == M){
        for(int i = 0; i < M; i++)
            cout<<select[i]<<" ";
        cout<<"\n";
        return;
    }   

    for(int i = 0; i < N; i++){
        select[cnt] = i+1;
        dfs(cnt+1,select);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin>>N>>M;
    vector<int> select(M);
    dfs(0,select);
}