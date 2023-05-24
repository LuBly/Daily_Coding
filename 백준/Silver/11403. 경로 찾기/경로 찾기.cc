//[Baekjoon C++] 경로찾기 [그래프 탐색]
#include <iostream>
#include <vector>
using namespace std;

bool graph[101][101]={false,};
int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int sz;
    cin>>sz;
    for(int from=0;from<sz;from++){
        for(int to=0;to<sz;to++){
            int input;
            cin>>input;
            if(input==1) graph[from][to]=true;
        }
    }    
    //플로이드 와샬 알고리즘
    //a->b로 가는 길이 없어도
    //c를 거쳐갈 수 있으면 갈 수 있다고 여긴다.
    for(int c=0;c<sz;c++){
        for(int a=0;a<sz;a++){
            for(int b=0;b<sz;b++){
                if(graph[a][c]&&graph[c][b])
                    graph[a][b]=1;
            }
        }
    }

    for(int y=0;y<sz;y++){
        for(int x=0;x<sz;x++){
            cout<<graph[y][x]<<" ";
        }
        cout<<"\n";
    }
}