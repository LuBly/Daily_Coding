#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define INF 98765432
using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    // Dijkstra or Floid-Wortial
    // n = Node의 개수, s = Start, a = A도착점, b = B도착점
    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));
    //int dist[201][201] = {INF,};
    for(auto fare : fares){
        dist[fare[0]][fare[1]] = fare[2];
        dist[fare[1]][fare[0]] = fare[2];
    }
    // 모든 node간의 최소 이동 거리 계산 O(n^3) = 200^3 = 8,000,000 (OK)
    for(int adj = 1; adj <= n; adj++){
        for(int from = 1; from <= n; from++){
            for(int to = 1; to <= n; to++){
                if(from==to) dist[from][to] = 0;
                else dist[from][to] = min(dist[from][to], (dist[from][adj] + dist[adj][to]));
            }
        }
    }
    
    // 최소 비용 = St -> adj(합승 이동) + adj -> A + adj -> B 
    answer = dist[s][a] + dist[s][b]; // 합승안하는 경우
    for(int adj = 1; adj <= n; adj++){
        answer = min(answer, dist[s][adj] + dist[adj][a] + dist[adj][b]);
    }
    
    return answer;
}