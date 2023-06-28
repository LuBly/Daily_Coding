//[Baekjoon C++] 플로이드 [그래프 탐색]
#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;



int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int node, edge;
    cin>>node>>edge;
    int data[101][101];//from, to
    
    //자기자신에서 자기자신으로 가는 경우의 cost를 0으로 초기화
    for(int from=1;from<=node;from++){
        for(int to=1;to<=node;to++){
            if(from==to) data[from][to]=0;
            else data[from][to]=INF;
        }   
    }

    for(int k=0;k<edge;k++){
        int from, to, cost;
        cin>>from>>to>>cost;
        data[from][to] = min(data[from][to],cost);//동일 노선이라면 기존의 cost와 새로 입력되는 cost 중 작은 것을 선택
    }


    for(int k=1;k<=node;k++){
        for(int st=1;st<=node;st++){
            for(int dt=1;dt<=node;dt++){
                //임의의 k를 공유하는 경로가 더 짧다면 해당 경로로 이동
                data[st][dt]=min(data[st][dt], data[st][k]+data[k][dt]);
            }
        }
    }

    for(int st=1;st<=node;st++){
        for(int dt=1;dt<=node;dt++){
            if(data[st][dt]==INF){
                cout<<0<<" ";
            }
            else
                cout<<data[st][dt]<<" ";
        }
        cout<<'\n';
    }

}