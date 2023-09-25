//[BaekJoon C++] 우주신과의 교감 [MST]
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 1001
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

//(x1 - x2) ^2 + (y1 - y2) ^2
double distance(pair<double, double> p1, pair<double, double> p2){
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    // N : 우주신들의 개수
    // M : 이미 연결된 신들과의 통로 개수
    int N,M;
    cin >> N >> M;

    // 우주신들의 좌표
    vector<pair<int,int>> godPoints(N + 1); // x, y
    for(int k = 1; k <= N; k++){
        cin >> godPoints[k].first >> godPoints[k].second;
    }

    // 이미 연결된 좌표들
    vector<pair<int,int>> connectedPoints(M);
    for(int k = 0; k < M; k++){
        cin >> connectedPoints[k].first >> connectedPoints[k].second;
    }

    // 모든 좌표간 거리 계산
    vector<pair<double,pair<int,int>>> board; // cost, node번호 a,b
    for(int a = 1; a <= N-1; a++){
        for(int b = a + 1; b <= N; b++){
            double dist = distance(godPoints[a], godPoints[b]);
            board.push_back({dist, {a, b}});
        }
    }
    sort(board.begin(), board.end());
    // parent 초기화
    for(int k = 1; k <= N; k++){
        parent[k] = k;
    }
    
    // 이미 연결되어 있는 노드들 연결
    for(int k = 0; k < M; k++){
        uni(connectedPoints[k].first, connectedPoints[k].second);
    }

    double result = 0;
    for(int k = 0 ; k < board.size(); k++){
        if(!sameParent(board[k].second.first, board[k].second.second)){
            uni(board[k].second.first, board[k].second.second);
            result += board[k].first;
        }
    }

    printf("%.2f", result);
}    