//[BaekJoon C++] 웜홀 [최단거리]
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 9876543421
using namespace std;

int nodeCnt, edgeCnt, wormCnt;
struct edge{
    int st, dt, cost;
};

bool BellmanFord(int nodeCnt, vector<edge> board){
    vector<int> dist(nodeCnt + 1, INF);
    int st, dt, cost;
    dist[1] = 0;

    //nodeCnt 하나씩늘려가며 최단거리 체크
    for(int k = 1; k < nodeCnt; k++){
        for(int j = 0; j < board.size(); j++){
            st = board[j].st;
            dt = board[j].dt;
            cost = board[j].cost;

            if(dist[dt] > dist[st] + cost){
                dist[dt] = dist[st] + cost;
            }
        }
    }

    for(int k = 0; k < board.size(); k++){
        st = board[k].st;
        dt = board[k].dt;
        cost = board[k].cost;

        if(dist[dt] > dist[st] + cost)
            return true;
    }

    return false;
}


int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int TC;
    cin >> TC;

    for(int k = 0; k < TC; k++){
        // 지점의 수, 도로의 개수, 웜홀의 개수
        cin >> nodeCnt >> edgeCnt >> wormCnt;
        
        // from / {to, cost}
        vector<edge> board;
        
        for(int eIdx = 0; eIdx < edgeCnt; eIdx++){
            int from, to, cost;
            cin >> from >> to >> cost;
            board.push_back({from, to, cost});
            board.push_back({to, from, cost});
        }

        for(int wIdx = 0; wIdx < wormCnt; wIdx++){
            int from, to, cost;
            cin >> from >> to >> cost;
            
            board.push_back({from, to, -cost});
        }

        if(BellmanFord(nodeCnt, board)) cout << "YES\n";
        else cout << "NO\n";
    }
}   
