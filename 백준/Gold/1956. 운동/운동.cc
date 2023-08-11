//[BaekJoon C++] 운동 [플로이드 워셜]
#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;



int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int villageCount, roadCount;
    cin>>villageCount>>roadCount;
    
    vector<vector<int>> costs(villageCount+1, vector<int>(villageCount+1, INF));
    // 경로 정보 입력하기
    for(int k = 0; k < roadCount; k++){
        int from, to, cost;
        cin >> from >> to >> cost;
        costs[from][to] = cost;
    }

    int answer = INF;
    // 플로이드 워셜 알고리즘 적용
    for(int adj = 1; adj <= villageCount; adj++){
        for(int from = 1; from <= villageCount; from++){
            for(int to = 1; to <= villageCount; to ++){
                //기존 A->B 의 거리보다 경유한 거리가 더 짧다면 경유 거리를 A->B의 최단거리로 설정
                costs[from][to] = min(costs[from][to], costs[from][adj] + costs[adj][to]);
                if(from == to){
                    answer = min(answer, costs[from][to]);
                }
            }
        }
    }

    if(answer == INF)
        cout<<"-1";
    else
        cout<<answer;
}
