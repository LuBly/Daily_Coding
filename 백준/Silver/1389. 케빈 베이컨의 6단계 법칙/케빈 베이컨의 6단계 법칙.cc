//[Baekjoon C++] 케빈 베이컨의 6단계 법칙 [그래프 탐색]
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int userCnt, relCnt;
    cin>>userCnt>>relCnt;
    vector<vector<int>> distance(userCnt+1,vector<int>(userCnt+1,INF));//distance 정보를 저장할 2차원 vector

    // 플로이드 워셜->DP의 방식으로 문제를 풀어나간다.
    // dis[from][to] = min(dis[from][to], dis[from][adj]+dis[adj][to]);
    for(int k=0;k<relCnt;k++){
        int from, to;
        cin>>from>>to;
        distance[from][to]=1;
        distance[to][from]=1;
    }

    for(int adj=1;adj<=userCnt;adj++){ //거쳐가는 정점
        for(int from=1;from<=userCnt;from++){// 출발 정점
            for(int to=1;to<=userCnt;to++){// 도착 정점
                if(from==to) continue;
                distance[from][to]=min(distance[from][to],distance[from][adj]+distance[adj][to]);
            }
        }
    }
    //결과 확인
    int minResult = INF;
    int minUser;
    for(int from=1;from<=userCnt;from++){
        int KBNum=0;
        for(int to=1;to<=userCnt;to++){
            if(from==to) continue;
            else KBNum+=distance[from][to];
        }
        if(KBNum<minResult){
            minUser = from;
            minResult = KBNum;
        }
    }

    cout<<minUser;
}