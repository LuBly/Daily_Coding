//[Baekjoon C++] 전력난 [MST]
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200001
using namespace std;

int parent[MAX];

int find(int x){
    if(parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void uni(int x, int y){
    x = find(x);
    y = find(y);

    parent[y] = x;
}

bool sameParent(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return true;
    else return false;
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    while(true){
        // m : 집의 수 , max 200,000
        // n : 길의 수
        int m, n;
        cin >> m >> n;
        if(m == 0 && n == 0) break;
        // 모든 비용을 다 더하고
        // 각 노드들을 연결하는 최소 비용을 구해서
        // 전체 비용 - 최소 비용 = 절약비용(최대)
        // cost/ from,to
        int totalCost = 0;
        vector<pair<int, pair<int,int>>> board;
        for(int k = 0; k < n; k++){
            int from, to, cost;
            cin >> from >> to >> cost;
            board.push_back({cost, {from, to}});
            totalCost += cost;
        }
        
        for(int k = 0; k < m; k++){
            parent[k] = k;
        }

        sort(board.begin(), board.end());

        int resCost = 0;
        for(int k = 0; k < n; k++){
            if(!sameParent(board[k].second.first, board[k].second.second)){
                uni(board[k].second.first, board[k].second.second);
                resCost += board[k].first;
            }
        }
        cout << totalCost - resCost << '\n';
    }
}